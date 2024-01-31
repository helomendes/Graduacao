program xadrez;
var L, C : integer;
begin
	read(L, C);
	if (L mod 2 = 0) and (C mod 2 = 0) then
		writeln('BRANCA')
	else
		if (L mod 2 = 0) and (C mod 2 <> 0) then
			writeln('PRETA')
		else
			if (L mod 2 <> 0) and (C mod 2 = 0) then
				writeln('PRETA')
			else
				writeln('BRANCA');	
end.
