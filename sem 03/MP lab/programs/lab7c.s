# Compare Two Strings
.section .data
str1:
    .ascii "subhendu"

str2:
    .ascii "subhendu"

equal:
    .ascii "equal"

notequal:
    .ascii "notequal"

.section .bss
    .lcomm output, 10

.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax               # sys_exit
    movq    $0, %rdi                # exit code
    syscall

# driver function
_start:

    movl str1,%eax
    movl str2,%ebx

    cld     # clear the DF flag
    movl $8, %ecx   # set the length of the string
    movl $str1, %esi
    movl $str2, %edi
    repe cmpsb

    cmp $0, %ecx
    je _equal
_notequal:
    movl $5, %ecx
    movl $notequal, %esi
    movl $output, %edi
    rep movsb
    jmp _end

_equal:
    movl $5, %ecx
    movl $equal, %esi
    movl $output, %edi
    rep movsb
    jmp _end

_end:

    syscall
    call _ret           # exit