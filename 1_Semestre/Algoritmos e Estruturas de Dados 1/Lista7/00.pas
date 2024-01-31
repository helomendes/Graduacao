program vatores;
var 	v : array [1..200] of real;
	i, n : integer;
	pares, impares : real;
begin
	pares := 0;
	impares := 0;
	read(n);
	if n > 0 then
	begin
		for i := 1 to n do
		begin
			read(v[i]);
			if (i mod 2 = 0) then
			begin
				if v[i] > 0 then
					pares := pares + v[i];
			end
			else
			begin
				if v[i] < 0 then
					impares := impares + v[i];
			end;
		end;
		if impares <> 0 then
			writeln(pares/impares :0:2)
		else
			writeln('divisao por zero');
	end
	else
		writeln('vetor vazio');	
end.
