program converte;
var	n, pot : longint;
function converte_decimal (b : longint): real;
var	soma : longint;
	i : integer;
begin
	soma := 0;
	i := 0;
	pot := 1;
	if b = 0 then
		converte_decimal := 0
	else
		if b = 1 then
			converte_decimal := 1
		else
		begin
			while b <> 0 do
			begin
				i := i + 1;
				if (b mod 10) = 1 then
					soma := soma + pot;
				b := b div 10;
				pot := pot*2;
				if (b = 1) then
				begin
					soma := soma + pot;
					b := 0;
				end;
			end;
			converte_decimal := soma;
		end;
end;
begin
	read(n);
	writeln(converte_decimal(n):0:0);
end.
