.section .data
V: .quad 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.section .text
.global _start

_soma_vetor:
pushq %rbp
movq %rsp, %rbp


_start:
pushq %rbp
movq %rsp, %rbp
movq V, %rbx
pushq %rbx
call _soma_vetor