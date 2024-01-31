program seq;
var
	n, nant, soma : longint;
	cont : integer;
begin
	read(n);
	soma := n;
	cont := 1;
	if (n = 0) then 
		begin
			read(n);
			soma := n;
			cont := 2;
		end;
	while (n <> nant * 2) and (n <> nant/2) do
		begin
			nant := n;
			read(n);
			cont := cont + 1;
			if (n = 0) then 
				begin
					read(n);
					soma := soma + n;
					cont := cont + 1;
				end
			else
				soma := soma + n;
		end;
	writeln(cont, ' ', soma, ' ', nant, ' ', n);
end.
