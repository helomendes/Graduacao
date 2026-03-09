program divisao;
var
	numero, divisor, vezes : integer;
begin
	read(numero, divisor);
	vezes := 0;
	while (numero >= divisor) and (numero mod divisor = 0) do
		begin
			numero := numero div divisor;
			vezes := vezes + 1;
		end;
	writeln(vezes);
end.
