.section .data
V: .quad 10
T: .quad 5
.section .text
.global _start

_multiplos
pushq %rbp
movq %rsp, %rbp
