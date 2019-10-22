# sequence recognizer
.section .data
ar:
    .int 0,0,0,0,0,0,0,0,0,0
ar_len:
    .int 10
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
    movl $0b0010110110,%esi # esi = binary 
    movl ar_len,%edx
    subl $1,%edx

    loop:
        movl %esi,%edi # edi = esi
        andl $0b1111,%edi # edi = edi and 1111 
        sarl $1,%esi
        
        cmp $0,%edx
        je _end 
              
        cmp $0b1011,%edi
        je equal
        jne not_equal   
        
    equal:
        movl $1,ar(,%edx,4)
        subl $1,%edx
        jmp loop

    not_equal:
        movl $0,ar(,%edx,4)
        subl $1,%edx
        jmp loop
        
    _end:
    
    syscall
    call _ret           # exit