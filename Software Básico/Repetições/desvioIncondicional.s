.section .text
.global _start
_start:
	movq $0, %rdi
	jmp _finaliza
	movq $1, %rdi
_finaliza:
	movq $60, %rax
	syscall
