program multiplode7;
var
	n, a : longint;
begin
	read(n);
	a := 0;
	if (n mod 7 = 0) then
	begin
		if a < n then
			a := n;
	end;
	while n <> 0 do
	begin
		read(n);
		if (n mod 7 = 0) then
		begin
			if a < n then
				a := n;
		end;
	end;
	writeln(a);
end.
