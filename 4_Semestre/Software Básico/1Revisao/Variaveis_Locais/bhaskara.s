.section .data
A: .quad 4
C: .quad -1

.section .text
.global _start

_calculaDelta:
pushq %rbp
movq %rsp, %rbp
movq A, %rax
movq C, %rbx
imul $-4, %rax
imul %rbx, %rax
cmp $0, %rax
jl _fim_if
movq $1, %rax
popq %rbp
ret

_fim_if:
movq $0, %rax
popq %rbp
ret

_start:
call _calculaDelta
movq %rax, %rdi
movq $60, %rax
syscall
