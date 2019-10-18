# arithmetic opeartion
.section .data
num1:
    .int 10
num2:
    .int 20
oprtn:
    .int 3

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
    movl num1,%ecx;
    movl num2,%edx;
    
    cmp $1,oprtn
    je add_loop

    cmp $2,oprtn
    je sub_loop

    cmp $3,oprtn
    je mul_loop

    cmp $4,oprtn
    je div_loop

    add_loop:
        addl %ecx,%edx # edx = edx + ecx
        jmp _end
    sub_loop:
        subl %ecx,%edx # edx = edx - ecx
        jmp _end
    mul_loop:
        movl num2,%eax
        mull num1  # eax = eax * num1
        jmp _end
    div_loop:
        movl num2,%eax 
        divl num1   # eax = eax / num1
        jmp _end
    
    _end:

    syscall
    call _ret           # exit