# linear search
.section .data
list:
    .int 2,5,3,6,10,15
tar:
    .int 10

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function
_start:
    movl $0,%ecx
    movl $0,%eax
    
    loop:
        movl list(,%ecx,4),%eax
        addl $1,%ecx
        cmp tar,%eax
        jne loop

    syscall
    call _ret           # exit