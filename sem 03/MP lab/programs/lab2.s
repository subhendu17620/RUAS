# Arithmetic Operations
.section .data
a:
    .int 1
b:
    .int 10
c:
    .int 20
d:
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

    movl b,%ebx # ebx = b
    movl c,%ecx # ecx = c
    movl d,%edx # edx = d 
    
    addl %ebx, %ecx # ecx = b + c
    subl %edx, %ecx # ecx = ( b + c) - d 
    movl %ecx ,%esi # esi = ecx
    
    movl b,%eax # b = eax
    mull c   # eax = (b * c)
    divl d   # eax = (b * c) / d

    addl %esi, %eax # eax = esi + eax
    movl %eax,a # a = eax
    
    syscall
    call _ret           # exit