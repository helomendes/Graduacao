program positivoimpar;
var
	A, B, x, produto : longint;	
begin
	read(A);
	read(B);
	x := A;
	produto := 1;
	while x <= B do
		begin
			produto := produto * x;
			x := x + 2;
		end;
	writeln(produto);
end.
