.section .text
.global _start

_modulo:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rax
cmp $0, %rax
jl _fim_if
popq %rbp
ret

_fim_if:
neg %rax
popq %rbp
ret

_start:
pushq %rbp
movq %rsp, %rbp
pushq $-10
call _modulo
addq $8, %rsp
popq %rbp
movq %rax, %rdi
movq $60, %rax
syscall
