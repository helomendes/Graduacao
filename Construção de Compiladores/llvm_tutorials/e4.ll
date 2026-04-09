define i64 @safe_div(i64 %n, i64 %d) {
    %1 = icmp eq i64 %d, 0
    %2 = udiv i64 %n, %d
    %3 = select i1 %1, i64 -1, i64 %2
    ret i64 %3
}

define i64 @safe_div_br(i64 %n, i64 %d) {
    %1 = icmp eq i64 %d, 0
    br i1 %1, label %equal_zero, label %not_equal

    equal_zero:
	ret i64 -1

    not_equal:
	%2 = udiv i64 %n, %d
	ret i64 %2
}
