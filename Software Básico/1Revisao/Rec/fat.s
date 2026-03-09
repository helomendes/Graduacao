.section .text
.global _start

_fat:
pushq %rbp
movq %rsp, %rbp
movq 16(%rbp), %rbx
cmpq $1, %rbx
je _cb
subq $1, %rbx
pushq %rbx
call _fat
addq $8, %rsp
addq $1, %rbx
mul %rbx
jmp _fn
 
_cb:
movq $1, %rax

_fn:
popq %rbp
ret

_start:
pushq %rbp
movq %rsp, %rbp
pushq $3
call _fat
addq $16, %rsp
movq %rax, %rdi
movq $60, %rax
syscall
