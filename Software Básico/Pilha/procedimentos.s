.section .data
    A: .quad 10
    B: .quad 5
.section .text
.global _start
soma:
    pushq %rbp
    movq %rsp, %rbp
    movq A, %rax
    addq B, %rax
    popq %rbp
    ret
_start:
    call soma
    movq %rax, %rdi
    movq $60, %rax
    syscall