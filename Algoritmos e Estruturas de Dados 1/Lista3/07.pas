program seila;
var
	N, a, b : integer;
begin
	read(N);
	a := 0;
	b := 0;
	while a < N do
	begin
		while b < N do
		begin
			if (a + b = N) then
			begin
				writeln(a, ' ', b);
				b := b + 1;
			end
			else
				b := b + 1;
		end;
		a := a + 1;
		b := 0;
	end;
end.
