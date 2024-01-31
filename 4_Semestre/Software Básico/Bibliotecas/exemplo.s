.section .data
PRINTDATA: .string "Nr: %d\n"
.section .text
.global _start
_start:
movq $PRINTDATA, %rdi
movq $0, %r11
movq %r11, %rsi
call printf
movq %r11, %rsi
movq $PRINTDATA, %rdi
call printf
movq $0, %rdi
movq $60, %rax
syscall
