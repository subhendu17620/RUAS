# Moving Data from GPR's and Memory
.section .data
value:
    .int 10
x:
    .int 0

.section .text

.globl _start

# function for system exit code
_ret:
    # movq    $60, %rax               # sys_exit
    # movq    $0, %rdi                # exit code
    movl $1,%eax
    movl $0,%ebx
    int 0x80
    syscall

# driver function
_start:
    # moving data to GPR
    movb $100, %cl          # move 1 byte (8 bits) value to dl
    movw $10000, %bx        # move 2 byte (16 bits) value to bx
    movl $1000000000, %eax  # move 4 byte (32 bits) value to eax
    movl %eax, %ecx         # move 32 bit from GPR to GPR
    movl value, %eax        # move 32 bit from memory to GPR
    movl %eax, x           # move 32 bit from memory to memory by using a GPR as intermediate

    syscall
    call _ret           # exit