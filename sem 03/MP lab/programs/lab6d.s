# second smallest in unsorted array
.section .data
array:
    .int 7,3,5,1,6,9
array2:
    .int 0,0,0,0,0,0
sec_small:
    .int 0
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
    movl $0,%ebx
    movl $0,%ecx
    movl $0,%edx
loop1:
    movl array(,%ecx,4),%eax
    cmpl %ebx,%eax
    je loop2
inc:
    addl $1,%ecx
    cmpl $6,%ecx
    jne loop1
    addl $1,%ebx
    movl $0,%ecx
    cmpl $16,%eax
    jne loop1
loop2:
    movl %eax,array2(,%edx,4)
    addl $1,%edx
    cmpl $6,%edx
    jne inc
    movl $1,%edx
    movl array2(,%edx,4),%eax
    movl %eax,sec_small
    
    
    syscall
    call _ret           # exit