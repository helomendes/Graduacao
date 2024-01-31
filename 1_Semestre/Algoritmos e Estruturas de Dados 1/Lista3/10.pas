program digitos;
var 	m : longint;
	n, cont : integer;
begin
	read(n, m);
	cont := 0;
	while m >= 10 do
		begin
			if m mod 10 = n then
				cont := cont + 1;
			m := m div 10;
		end;
	if m = n then
		cont := cont + 1;
	if cont > 0 then
		writeln(cont)
	else
		writeln('NAO');
end.
