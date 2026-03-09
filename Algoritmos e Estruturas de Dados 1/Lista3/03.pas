program sequenciareais;
var
	m, n, soma, media, x : real;
begin
	read(m);
	n := 0;
	x := 1;
	soma := 0;
	while (x <= m) do
		begin
			read(n);
			soma := soma + n;
			x := x + 1;
		end;
	media := soma / m;
	writeln(trunc(media));
end.
