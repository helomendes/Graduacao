.section .text
.global _start
_burlando:
pushq %rbp
movq %rsp, %rbp
subq $8, %rsp
movq $5, -8(%rbp)
movq %rbp, %rax
subq $8, %rax
addq $8, %rsp
popq %rbp
ret

_start:
call _burlando
movq (%rax), %rdi
movq $60, %rax
syscall