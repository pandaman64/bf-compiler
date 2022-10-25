void basic_block_0(char *pointer);
void basic_block_59(char *pointer);
void basic_block_71(char *pointer);
void basic_block_82(char *pointer);
void basic_block_90(char *pointer);
void basic_block_107(char *pointer);
void basic_block_109(char *pointer);
void basic_block_119(char *pointer);
void basic_block_128(char *pointer);
void basic_block_143(char *pointer);
void basic_block_152(char *pointer);
void basic_block_164(char *pointer);
void basic_block_171(char *pointer);
void basic_block_194(char *pointer);
void basic_block_196(char *pointer);
void basic_block_207(char *pointer);
void basic_block_215(char *pointer);
void basic_block_219(char *pointer);
void basic_block_221(char *pointer);

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

void basic_block_0(char *pointer) {
    rt_putchar(*pointer);
    rt_putchar(*pointer);
    rt_putchar(*pointer);
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_59(pointer);
    } else {
        __attribute__((musttail)) return basic_block_71(pointer);
    }
}

void basic_block_59(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_59(pointer);
    } else {
        __attribute__((musttail)) return basic_block_71(pointer);
    }
}

void basic_block_71(char *pointer) {
    pointer--;
    rt_putchar(*pointer);
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_82(pointer);
    } else {
        __attribute__((musttail)) return basic_block_90(pointer);
    }
}

void basic_block_82(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_82(pointer);
    } else {
        __attribute__((musttail)) return basic_block_90(pointer);
    }
}

void basic_block_90(char *pointer) {
    pointer--;
    (*pointer)++;
    rt_putchar(*pointer);
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    rt_putchar(*pointer);
    rt_putchar(*pointer);
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    rt_putchar(*pointer);

    if (*pointer) {
        __attribute__((musttail)) return basic_block_107(pointer);
    } else {
        __attribute__((musttail)) return basic_block_109(pointer);
    }
}

void basic_block_107(char *pointer) {
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_107(pointer);
    } else {
        __attribute__((musttail)) return basic_block_109(pointer);
    }
}

void basic_block_109(char *pointer) {
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_119(pointer);
    } else {
        __attribute__((musttail)) return basic_block_128(pointer);
    }
}

void basic_block_119(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_119(pointer);
    } else {
        __attribute__((musttail)) return basic_block_128(pointer);
    }
}

void basic_block_128(char *pointer) {
    pointer--;
    rt_putchar(*pointer);
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_143(pointer);
    } else {
        __attribute__((musttail)) return basic_block_152(pointer);
    }
}

void basic_block_143(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_143(pointer);
    } else {
        __attribute__((musttail)) return basic_block_152(pointer);
    }
}

void basic_block_152(char *pointer) {
    pointer--;
    rt_putchar(*pointer);
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_164(pointer);
    } else {
        __attribute__((musttail)) return basic_block_171(pointer);
    }
}

void basic_block_164(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_164(pointer);
    } else {
        __attribute__((musttail)) return basic_block_171(pointer);
    }
}

void basic_block_171(char *pointer) {
    pointer--;
    rt_putchar(*pointer);
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    rt_putchar(*pointer);
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    rt_putchar(*pointer);
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    (*pointer)--;
    rt_putchar(*pointer);

    if (*pointer) {
        __attribute__((musttail)) return basic_block_194(pointer);
    } else {
        __attribute__((musttail)) return basic_block_196(pointer);
    }
}

void basic_block_194(char *pointer) {
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_194(pointer);
    } else {
        __attribute__((musttail)) return basic_block_196(pointer);
    }
}

void basic_block_196(char *pointer) {
    pointer++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_207(pointer);
    } else {
        __attribute__((musttail)) return basic_block_215(pointer);
    }
}

void basic_block_207(char *pointer) {
    pointer--;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    pointer++;
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_207(pointer);
    } else {
        __attribute__((musttail)) return basic_block_215(pointer);
    }
}

void basic_block_215(char *pointer) {
    pointer--;
    (*pointer)++;
    rt_putchar(*pointer);

    if (*pointer) {
        __attribute__((musttail)) return basic_block_219(pointer);
    } else {
        __attribute__((musttail)) return basic_block_221(pointer);
    }
}

void basic_block_219(char *pointer) {
    (*pointer)--;

    if (*pointer) {
        __attribute__((musttail)) return basic_block_219(pointer);
    } else {
        __attribute__((musttail)) return basic_block_221(pointer);
    }
}

void basic_block_221(char *pointer) {
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    (*pointer)++;
    rt_putchar(*pointer);
    exit(0);
}

