use std::{
    collections::BTreeMap,
    io::{self, Read},
};

use basic_block::{BasicBlock, BasicBlockBuilder, BasicBlockId, Instruction};

mod basic_block;

fn parse(input: &str) -> BTreeMap<BasicBlockId, BasicBlock> {
    let mut ret = BTreeMap::new();
    let mut open_bracket_stack = vec![];
    let mut current_id = BasicBlockId(0);
    let mut current = BasicBlockBuilder::default();

    for (index, c) in input.char_indices() {
        match c {
            '+' => current.push_inst(Instruction::Plus),
            '-' => current.push_inst(Instruction::Minus),
            '>' => current.push_inst(Instruction::Next),
            '<' => current.push_inst(Instruction::Prev),
            '.' => current.push_inst(Instruction::Print),
            ',' => current.push_inst(Instruction::Input),
            '[' => {
                let block_id = current_id;
                let mut block = std::mem::take(&mut current);
                // next index
                let next_block_id = BasicBlockId(index + c.len_utf8());

                block.jump_on_nonzero = Some(next_block_id);
                open_bracket_stack.push((block_id, block));

                current_id = next_block_id;
            }
            ']' => {
                let block_id = current_id;
                let mut block = std::mem::take(&mut current);
                // next index
                let next_block_id = BasicBlockId(index + c.len_utf8());

                let (back_block_id, mut back_block) = open_bracket_stack.pop().expect("too many ]");
                back_block.jump_on_zero = Some(next_block_id);
                block.jump_on_nonzero = Some(back_block.jump_on_nonzero.unwrap());
                block.jump_on_zero = Some(next_block_id);

                ret.insert(back_block_id, back_block.build_jump());
                ret.insert(block_id, block.build_jump());

                current_id = next_block_id;
            }
            _ => {}
        }
    }

    if !open_bracket_stack.is_empty() {
        panic!("too many [");
    }

    ret.insert(current_id, std::mem::take(&mut current).build_final());

    ret
}

fn compile<W: std::io::Write>(
    blocks: &BTreeMap<BasicBlockId, BasicBlock>,
    mut writer: W,
) -> io::Result<()> {
    for (block_id, _) in blocks.iter() {
        writeln!(
            writer,
            "void {}(char *pointer);",
            block_id.to_function_name()
        )?;
    }

    writer.write_all(
        br#"
int getchar(void);
int putchar(int c);
void exit(int status);

int main() {
    char buffer[30000];
    basic_block_0(buffer);
}

__attribute__((noinline))
char rt_getchar() {
    int c = getchar();
    if (c < 0) {
        exit(1);
    } else {
        return (char) c;
    }
}

__attribute__((noinline))
void rt_putchar(char c) {
    if (putchar(c) < 0) {
        exit(1);
    }
}

"#,
    )?;

    for (block_id, block) in blocks.iter() {
        writeln!(
            writer,
            "void {}(char *pointer) {{",
            block_id.to_function_name()
        )?;
        for inst in block.instructions.iter() {
            let template = match inst {
                Instruction::Plus => "(*pointer)++;",
                Instruction::Minus => "(*pointer)--;",
                Instruction::Next => "pointer++;",
                Instruction::Prev => "pointer--;",
                Instruction::Print => "rt_putchar(*pointer);",
                Instruction::Input => "*pointer = rt_getchar();",
            };
            writeln!(writer, "    {}", template)?;
        }
        match block.termination {
            basic_block::Termination::Jump {
                on_zero,
                on_nonzero,
            } => writeln!(
                writer,
                r#"
    if (*pointer) {{
        __attribute__((musttail)) return {}(pointer);
    }} else {{
        __attribute__((musttail)) return {}(pointer);
    }}"#,
                on_nonzero.to_function_name(),
                on_zero.to_function_name()
            )?,
            basic_block::Termination::Exit => writeln!(writer, "    exit(0);")?,
        }
        writeln!(writer, "}}\n")?;
    }

    Ok(())
}

fn main() -> io::Result<()> {
    let mut source = String::new();
    // TODO: replace with io::read_to_string
    let mut stdin = io::stdin().lock();
    stdin.read_to_string(&mut source)?;

    let basic_blocks = parse(&source);

    let stdout = io::stdout().lock();
    compile(&basic_blocks, stdout)
}
