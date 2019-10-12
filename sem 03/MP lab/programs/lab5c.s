# Bit-Counting
.section .data

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

    movl $0x7f, %ebx    # b = 7 // actual number
    movl $0, %ecx       # c = 0 // to keep track of the number of 1's
loop:
    movl $1, %eax       # a = 1
    andl %ebx, %eax     # a = a & b
    addl %eax, %ecx     # c = c + a
    sarl %ebx
    cmp $0, %ebx
    jne loop

    movl %ecx, %eax     # a = c
    andl $1, %eax       # a = a & 1 // if even no. of 1's then 0 else 1

    syscall
    call _ret           # exit