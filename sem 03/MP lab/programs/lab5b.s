# linear search of character
.section .data
email:
    .asciz "myemail@gmail.com"
tar:
    .asciz "@"

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function
_start:

    movb $0,%cl
    
    loop:
        movb email(,%ecx,1),%al
        addb $1,%cl
        cmp tar,%al
        jne loop

    syscall
    call _ret           # exit