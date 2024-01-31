.section .text
.global _start
_start:
	movq $60, %rax
	movq $69, %rdi
	syscall
