program soma_dos_pares;
var x, n, m, soma : integer;
begin
	read(n, m);
	soma := 0;
	x := n + 1;
	while x < m do
	begin
		if x mod 2 = 0 then
			soma := soma + x;
		x := x + 1;
	end;
	writeln(soma);
end.
