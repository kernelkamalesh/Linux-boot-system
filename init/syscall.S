.global write
.global read

write:
    mov $1, %rax
    syscall
    ret

read:
    mov $0, %rax
    syscall
    ret