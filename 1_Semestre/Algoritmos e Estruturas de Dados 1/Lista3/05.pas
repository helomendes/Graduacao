program linhas;
var
	valor, peso, mediapond, dividendo, soma : real;
begin
	read(valor, peso);
	dividendo := peso;
	soma := valor * peso;
	while (valor <> 0) and (peso <> 0) do
		begin
			read(valor, peso);
			soma := soma + (valor * peso);
			dividendo := dividendo + peso;
		end;
	mediapond := soma / dividendo;
	writeln(mediapond :0:2);
end.
