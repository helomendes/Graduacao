program banco;
var
	saldo : real;
begin
	read(saldo);
	if saldo < 0 then
			writeln(saldo:0:2);
	while (saldo <> 0) do
	begin
		read(saldo);
		if saldo < 0 then
			writeln(saldo:0:2);
	end;
end.
