.section .data
    i: .quad 0
    m: .quad 0
    v: .quad 10, 30, 5, 10, 50

.section .text
.global _start
_start:
    movq i, %rax
    movq $5, %rbx
    movq $v, %rcx
    

    _inicioFor:
    cmp %rax, %rbx
    bge _fimFor
    
    _if:
    addq %rax, %rcx
    movq (%rcx), %rdx
    cmp %rdx, 
    

    _else:
    addq $1, %rax

    jmp _inicioFor
    
    _fimFor:
    movq m, %rdi
    movq $60, %rax
    syscall