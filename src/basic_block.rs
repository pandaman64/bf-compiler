#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum Instruction {
    Plus,
    Minus,
    Next,
    Prev,
    Print,
    Input,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub(crate) struct BasicBlockId(pub(crate) usize);

impl BasicBlockId {
    pub(crate) fn to_function_name(self) -> String {
        format!("basic_block_{}", self.0)
    }
}

#[derive(Debug, Default)]
pub(crate) struct BasicBlockBuilder {
    pub(crate) instructions: Vec<Instruction>,
    pub(crate) jump_on_zero: Option<BasicBlockId>,
    pub(crate) jump_on_nonzero: Option<BasicBlockId>,
}

impl BasicBlockBuilder {
    pub(crate) fn push_inst(&mut self, inst: Instruction) {
        self.instructions.push(inst)
    }

    pub(crate) fn build_jump(self) -> BasicBlock {
        BasicBlock {
            instructions: self.instructions,
            termination: Termination::Jump {
                on_zero: self.jump_on_zero.unwrap(),
                on_nonzero: self.jump_on_nonzero.unwrap(),
            },
        }
    }

    pub(crate) fn build_final(self) -> BasicBlock {
        BasicBlock {
            instructions: self.instructions,
            termination: Termination::Exit,
        }
    }
}

#[derive(Debug, Clone, Copy)]
pub(crate) enum Termination {
    Jump {
        on_zero: BasicBlockId,
        on_nonzero: BasicBlockId,
    },
    Exit,
}

#[derive(Debug)]
pub(crate) struct BasicBlock {
    pub(crate) instructions: Vec<Instruction>,
    pub(crate) termination: Termination,
}
