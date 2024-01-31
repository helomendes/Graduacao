program nperfeito;
var	K, cont, som_div : integer;
	n, a : longint;
begin
	read(K);
	cont := 0;
	som_div := 1;
	a := 2;
	n := 2;
	while cont < K do
	begin
		while (a < n) do
		begin
			if n mod a = 0 then
				som_div := som_div + a;
			a := a + 1;
		end;
		if som_div = n then
		begin
			write(n, ' ');
			cont := cont + 1;
		end;
		a := 2;
		som_div := 1;
		n := n + 1;
	end;
end.
