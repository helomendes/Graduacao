define i32 @main() {
entry:
	%c = alloca i32
	%b = alloca i32
	%a = alloca i32
	store i32 10, ptr %a
	%t0 = sdiv i32 10, 3
	store i32 %t0, ptr %b
	%t1 = load i32, ptr %a
	%t2 = load i32, ptr %b
	%t3 = mul i32 %t2, 5
	%t4 = add i32 %t1, %t3
	%t5 = load i32, ptr %a
	%t6 = load i32, ptr %b
	%t7 = add i32 %t6, 10
	%t8 = sdiv i32 %t5, %t7
	%t9 = sub i32 %t4, %t8
	store i32 %t9, ptr %c
	%t10 = load i32, ptr %c
	ret i32 0
}
