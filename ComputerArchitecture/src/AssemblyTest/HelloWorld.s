.section .data
message: 
    .ascii "Hello world!\n"
msglength: 
    .quad 12

.section .text
.global main

main:
    mov $1, %rax            # syscall: write
    mov $1, %rdi            # file descriptor: stdout
    lea message(%rip), %rsi # Load address of 'message' into %rsi
    mov msglength(%rip), %rdx # Load message length into %rdx
    syscall                 # Make the system call

    mov $60, %rax           # syscall: exit
    xor %rdi, %rdi          # exit code: 0
    syscall                 # Make the system call
