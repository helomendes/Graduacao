program triang;
var	a, b, c, n : integer;
	teste : longint;
	triangular : boolean;
begin
	read(n);
	a := 1;
	b := 2;
	c := 3;
	triangular := false;
	while c <= (n/2) do
	begin
		teste := a * b * c;
		if teste = n then
			triangular := true;
		a := a+ 1;
		b := b + 1;
		c := c+1;
	end;
	if triangular then
		writeln('1')
	else
		writeln('0');
end.
