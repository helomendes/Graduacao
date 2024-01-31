.section .data
    v: .quad 2, 2, 1, 2, 1, 2, 1, 2, 11, 2
.section .text
.global _start
_start:
    movq $0, %rdi
    movq v, %rax
    movq $0, %rbx
_loop_for:
    cmp $10, %rbx
    je _fim_for
    movq $1, %rcx
    movq v(, %rbx, 8), %rdx
    and %rcx, %rdx
    cmp $1, %rdx
    je _fim_if    
    addq $1, %rdi
_fim_if:
    addq $1, %rbx
    jmp _loop_for
_fim_for:
    movq $60, %rax
    syscall