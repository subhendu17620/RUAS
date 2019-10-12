# second smallest in unsorted array
.section .data
ar:
    .int 7,3,5,1,6,9

.section .bss

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function  
_smallest:

_start:
    
    movl $0,%eax; # ar[i]
    movl $0,%ebx; # ar[j]
    movl $0,%ecx; # i = 0
    movl $1,%edx; # j = 1

    # movl ar(,0,4),%eax # moving first element to eax


    loop1:
        movl ar(,%ecx,4),%eax
        addl $1,%ecx
        cmp $6, %ecx
        jne loop2
        jmp _end

    loop2:
        movl ar(,%edx,4),%ebx
        cmp %ebx,%eax
        jg swap
        
    loop3:
        addl $1,%edx
        cmp $6, %edx
        jne loop2

    swap:
        xorl %eax,%ebx
        xorl %ebx,%eax
        xorl %eax,%ebx
        movl %eax,ar(,%ecx,4)
        movl %ebx,ar(,%edx,4)
        jmp loop3


    _end:
    syscall
    call _ret           # exit