.global write
.global read
.global exit
.global getcwd
.global chdir

write:
    mov $1, %rax
    syscall
    ret

read:
    mov $0, %rax
    syscall
    ret

exit:
    mov $60, %rax
    syscall
    ret

getcwd:
    mov $79, %rax
    syscall
    ret


chdir:
    mov $80, %rax
    syscall
    ret