program poligono;
var
	n, lados, soma, a : integer;
begin
	read(n);
	lados := 0;
	soma := n;
	a := n;
	while n <> 0 do
		begin
			read(n);
			lados := lados + 1;
			soma := soma + n;
		end;
	if (lados >= 3) then
		begin
			if (a * lados = soma) then
				writeln('SIM')
			else
			    writeln('NAO');
		end
	else
		writeln('NAO');
end.
