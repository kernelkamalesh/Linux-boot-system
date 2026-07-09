.global write

write:
    mov $1, %rax
    syscall
    ret