program coincidencia;
var
	x, soma, c, d : integer;
	mult, n : longint;
begin
	read(x);
	mult := x * 37;
	n := mult;
	soma := 0;
	c := n div 100;
	n := n mod 100;
	d := n div 10;
	n := n mod 10;
	soma := c+d+n;
	if (soma = x) then
		writeln('SIM')
	else
		writeln('NAO');
end.
