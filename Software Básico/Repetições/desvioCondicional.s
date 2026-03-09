.section .text

.global _start
_start:
movq $0, %rdi
movq $10, %rbx
movq $20, %rcx
cmp %rcx, %rbx
jg _finaliza
movq $1, %rdi

_finaliza:
movq $60, %rax
syscall
