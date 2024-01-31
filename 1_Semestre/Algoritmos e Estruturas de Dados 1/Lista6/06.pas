program calcula_percentual;
var	antigo, atual : real;
function aumento_percentual(var antigo, atual : real) : real;
var	diferenca, porcentagem : real;
begin
	diferenca := atual - antigo;
	porcentagem := (100*diferenca)/antigo;
	aumento_percentual := porcentagem/100;
end;
begin
	read(antigo, atual);
	while (antigo <> 0) or (atual <> 0) do
	begin
		writeln(aumento_percentual(antigo, atual):0:2);
		read(antigo, atual);
	end;
end.
