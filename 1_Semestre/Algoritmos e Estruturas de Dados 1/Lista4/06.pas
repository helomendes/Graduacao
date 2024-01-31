program ehprimo;
var
	x, divi, sd : integer;
begin
	read(x);
	divi := 2;
	sd := 1;
	if (x = 0) then
		sd := 2;
	while (divi < x) do
		begin
			if (x mod divi = 0) then
				sd := sd + divi;
			divi := divi + 1;
		end;
	if (sd > 1) then
		writeln('NAO')
	else
		writeln('SIM');
end.
