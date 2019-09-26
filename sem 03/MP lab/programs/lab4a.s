# print n even, odd numbers
.section .data
e:
    .int 0,0,0,0,0,0,0,0,0,0
o:
    .int 0,0,0,0,0,0,0,0,0,0
a:
    .int 15
.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function
_start:

    movl $0,%eax # i = 0
    movl $0,%ebx # a = 0
    movl $1,%ecx # b = 0
    
    loop:
        movl %ebx,e(,%eax,4) # a = e[i]
        movl %ecx,o(,%eax,4) # b = o[i]
        addl $1,%eax # i++
        addl $2,%ebx # a + = 2
        addl $2,%ecx # b + = 2
        cmp $10,%eax
    jne loop

    syscall
    call _ret           # exit