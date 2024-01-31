.section .data
    V: .quad 10
    T: .quad 5
.section .text
.global _start
multiplos:
    pushq %rbp
    movq %rsp, %rbp
    pushq $1
    movq T, %rbx
    pushq $2
    _inicio_for:
        cmp %rbx, -16(%rbp)
        jg _fim_for
	movq $0, %rax
	movq -16(%rbp), %rdx
        divq V
        cmp $0, %rdx
        jne _fim_if
        addq $1, -8(%rbp)
        _fim_if:
            addq $1, -16(%rbp)
            jmp _inicio_for
    _fim_for:
        addq $8, %rsp
        popq %rax
        popq %rbp
        ret
_start:
    call multiplos
    movq %rax, %rdi
    movq $60, %rax
    syscall
