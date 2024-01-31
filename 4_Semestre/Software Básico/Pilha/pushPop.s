.section .data
    A: .quad 5

.section .text
.global _start
_start:
    movq $10, %rax
    pushq $0
    pushq $A
    pushq A
    pushq %rax
    popq A
    popq %rax
    popq A
    
    movq A, %rdi
    movq $60, %rax
    syscall