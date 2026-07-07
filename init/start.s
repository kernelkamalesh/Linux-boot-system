.global _start
.extern kmain

.section .text

_start:
    call kmain

1:
    jmp 1b