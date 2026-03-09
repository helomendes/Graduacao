.section .data
PRINTDATA: .string "Olá Mundo!\n"
.section .text
.global main
main:
pushq %rbp
movq %rsp, %rbp
movq $PRINTDATA, %rdi
call printf
popq %rbp
movq $0, %rdi
movq $60, %rax
syscall
