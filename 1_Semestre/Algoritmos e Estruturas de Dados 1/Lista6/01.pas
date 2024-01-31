program testa_binario;
var n : longint;
function eh_binario(x : longint) : boolean;
begin
	if x = 0 then
		eh_binario := true
	else
	begin
		while (x <> 0) do
		begin
			if (x mod 10) <= 1 then
			begin
				x := x div 10;
				eh_binario := true;
			end
			else
			begin	
				eh_binario := false;
				x := 0;
			end;
		end;
	end;
end;
begin
	read(n);
	if eh_binario(n) then
		writeln('sim')
	else
		writeln('nao');
end.
