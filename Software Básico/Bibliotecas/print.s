.section .data
PRINTDATA: .string "Olá Mundo!\n"
.section .text
.global _start
_start:
movq $PRINTDATA, %rdi
call printf
movq $0, %rdi
movq $60, %rax
syscall
