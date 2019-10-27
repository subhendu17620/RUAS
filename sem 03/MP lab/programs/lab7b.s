# reverse the contents of MSG1 to MSG2
.section .data
str1:
    .ascii "subhendu maji"
.section .bss
    .lcomm output,10
.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function
_start:
    movl $str1+12,%esi
    movl $output,%edi
    movl $0,%edx

    loop:
        movsb
        subl $2,%esi
        addl $1,%edx
        cmp $13,%edx
        jne loop

    syscall
    call _ret           # exit