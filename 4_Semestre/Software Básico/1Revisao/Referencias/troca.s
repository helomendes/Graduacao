.section .text
.global _start

_troca:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rax
pushq (%rax)
movq 24(%rbp), %rbx
movq (%rbx), %rcx
movq %rcx, (%rax)
movq -8(%rbp), %rcx
movq %rcx, (%rbx)
addq $8, %rsp
popq %rbp
ret

_start:
pushq %rbp
movq %rsp, %rbp
pushq $10
pushq $20
movq %rbp, %rax
subq $16, %rax
pushq %rax
addq $8, %rax
pushq %rax
call _troca
addq $16, %rsp
movq -8(%rbp), %rdi
subq -16(%rbp), %rdi
addq $16, %rsp
popq %rbp
movq $60, %rax
syscall
