program seriess;
var
	x, potx, multx, fat, fx, tant, sinal, proxfat, t, fim : real;
begin
	read(x);
	(*inicializa variaveis*)
	(*termo anterior*)
	potx := x;
	multx := 5;
	fat := 2;
	fx := 2.5 * x;
	tant := fx;
	(*termo atual*)
	sinal := -1;
	proxfat := 3;
	t := fx;
	fim := 1;
	
	while (fim > 0.0000001) do
	begin
		(*calcula a prox potencia de x*)
		potx := potx * x;
		(*denominador depende do sina*)
		if (sinal = -1) then
			multx := multx + 1
		else
			multx := multx + 5;
		(*calcula o termo atual*)
		fat := fat * proxfat;
		t := sinal * (multx * potx)/fat;
		fx := fx + t;
		(*proximo fatorial*)
		proxfat := proxfat + 1;

		sinal := -sinal;

		fim := abs(tant - 1);
		tant := t;
	end;
	writeln(fx:0:5);
end.
