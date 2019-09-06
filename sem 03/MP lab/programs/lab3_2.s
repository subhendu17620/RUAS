# Arithmetic Operations
.section .data

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax        # sys_exit
    movq    $0, %rdi         # exit code
    syscall

# driver function
_start:

    movl $6,%ebx # ebx = 6
    sall $4,%ebx # ebx = ebx * (2^4)
    sarl $2, %ebx # ebx = ebx / (2^2)

    
    syscall
    call _ret           # exit