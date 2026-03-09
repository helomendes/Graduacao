.section .data
STR: .string "%ld\n"

.section .text
.global _start

_calcular_area:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rax
movq $3, %rbx
mul %rax
mul %rbx
popq %rbp
ret

_start:
pushq %rbp
movq %rsp, %rbp
pushq $10
call _calcular_area
movq %rax, %rsi
movq $STR, %rdi
call printf
addq $8, %rsp
popq %rbp
movq %rax, %rdi
movq $60, %rax
syscall
