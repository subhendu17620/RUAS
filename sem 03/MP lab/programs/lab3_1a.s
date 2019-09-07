# Arithmetic Operations
.section .data
a:
    .int 1 # 0001
b:
    .int 2 # 0010
c:
    .int 5 # 0101
d:
    .int 3 # 0011
.section .text

.globl _start

# function for system exit code
_ret:
    movq    $60, %rax        # sys_exit
    movq    $0, %rdi         # exit code
    syscall

# driver function
_start:
    
    movl b,%ebx # ebx = b
    movl c,%ecx # ecx = c
    movl d,%edx # edx = d 
    
    andl %ebx,%ecx # b and c = ecx
    movl %ecx, %eax # moving (b and c) to eax
    xorl %edx, %eax # eax =  (b AND c) XOR d
    
    movl %eax,a

    xorl %ebx,%ecx # ecx = b xor c 
    movl %ecx, %eax # eax = b xor c
    orl %edx,%eax # eax = (b xor c) or d 
    
    movl %eax,a

    syscall
    call _ret           # exit