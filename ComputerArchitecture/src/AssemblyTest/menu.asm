.section .data
menu_msg:
    .asciz "\nChoose a menu ('1' for help): "
help_msg:
    .asciz "0: Exit\n1: Help\n2: Say hello\n3: About\n"
hello_msg:
    .asciz "Hello, world!\n"
about_msg:
    .asciz "This is Sam's menu program!\n"
goodbye_msg:
    .asciz "Goodbye!\n"
invalid_msg:
    .asciz "Invalid choice. Try again.\n"

.section .bss
    .lcomm input, 2

.section .text
.globl main

main:
    call menu
    call get_input
    call process_input
    
    jmp main

menu:
    mov $1, %rax
    mov $1, %rdi
    mov $menu_msg, %rsi
    mov $31, %rdx
    syscall
    ret

get_input:
    mov $0, %rax
    mov $0, %rdi
    mov $input, %rsi
    mov $2, %rdx
    syscall

    # Check if the second byte is a newline
    movzbl input+1(%rip), %eax
    cmp $'\n', %al
    jne done
    movb $0, input+1(%rip)

done:
    ret

process_input:
    mov input, %al
    cmp $'0', %al
    je exit_program
    cmp $'1', %al
    je print_help
    cmp $'2', %al
    je print_hello_world
    cmp $'3', %al
    je print_about
    jmp print_invalid_choice

print_help:
    mov $1, %rax
    mov $1, %rdi
    mov $help_msg, %rsi
    mov $38, %rdx
    syscall
    ret

print_hello_world:
    mov $1, %rax
    mov $1, %rdi
    mov $hello_msg, %rsi
    mov $14, %rdx
    syscall
    ret

print_about:
    mov $1, %rax
    mov $1, %rdi
    mov $about_msg, %rsi
    mov $28, %rdx
    syscall
    ret

print_invalid_choice:
    mov $1, %rax
    mov $1, %rdi
    mov $invalid_msg, %rsi
    mov $27, %rdx
    syscall
    ret

print_goodbye:
    mov $1, %rax
    mov $1, %rdi
    mov $goodbye_msg, %rsi
    mov $9, %rdx
    syscall
    ret

exit_program:
    call print_goodbye
    
    mov $60, %rax
    xor %rdi, %rdi
    syscall
