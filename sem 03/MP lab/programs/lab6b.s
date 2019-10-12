# SWAP
.section .data
x:
    .int 10
y:
    .int 20
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
    movl x,%eax
    movl y,%ebx

    xorl %eax,%ebx
    xorl %ebx,%eax
    xorl %eax,%ebx

    movl %eax,x
    movl %ebx,y
    syscall
    call _ret           # exit