program parouimpar;
var
	numero : longint;
begin
	read(numero);
	if (numero mod 2 <> 0) and (numero < -20) or (numero mod 2 = 0) and (numero > 7) then
	writeln('SIM')
	else writeln('NAO');
end.
