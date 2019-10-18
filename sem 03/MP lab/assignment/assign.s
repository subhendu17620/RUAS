# sequence recognizer
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
    movl $0b1011,%esi # esi = binary 
    loop:
        movl %esi,%edi # edi = esi
        andl $0b1111,%edi # edi = edi and 1111 
        sarl $1,%esi
        cmp $0b1011,%edi
        je equal
        # jne not_equal

    equal:
        orl $1,%edi
        sall $1,%edi
        jmp loop

    # not_equal:
        
      #   jmp loop

    syscall
    call _ret           # exit