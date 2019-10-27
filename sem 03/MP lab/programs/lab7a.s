# Copy the contents of MSG1 to MSG2
.section .data
value:
    .ascii "hii welcome\n"
.section .bss
    .lcomm output, 12
.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function  
_start:
    
    
    leal value,%esi
    leal output,%edi
    movl $12,%ecx
    cld

    rep movsb
    # movsw
    # movsl

    syscall
    call _ret           # exit