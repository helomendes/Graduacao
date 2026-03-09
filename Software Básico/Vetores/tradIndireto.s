.section .data
    i: .quad 0
    m: .quad 0
    v: .quad 10, 30, 5, 10, 50
.section .text
.global _start
_start:
    movq i, %rax
    movq m, %rdi
    movq v, %rbx
_loop_i:
    cmp $5, %rax
    je _loop_e
    cmp %rdi, (%rbx)
    jle _if_e
    movq (%rbx), %rdi
_if_e:
    addq $8, %rbx
    addq $1, %rax
    jmp _loop_i
_loop_e:
    movq $60, %rax
    syscall