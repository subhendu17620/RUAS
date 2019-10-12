# factorial
.section .data
n:
    .int 5
fact:
    .int 1
.section .bss

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function  
_start:
    movl $1,%eax
    movl $1,%ecx
    loop:
        addl $1,%ecx
        mull %ecx
        cmp n,%ecx
        jne loop
    
    movl %eax,fact

    syscall
    call _ret           # exit