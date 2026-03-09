.section .data
PRINTDATA: .string "Argumento: %s\n"

.section .text
.global main
main:
pushq %rbp
movq %rsp, %rbp
movq %rsi, %rbx
addq $8, %rbx

loop_i:
cmpq $0, (%rbx)
je loop_f
movq $PRINTDATA, %rdi
movq (%rbx), %rsi
call printf
addq $8, %rbx
jmp loop_i

loop_f:
popq %rbp
movq $0, %rdi
movq $60, %rax
syscall
