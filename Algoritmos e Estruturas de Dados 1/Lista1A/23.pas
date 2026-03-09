program piraporinha;
var
	bruto, prestacao : real;
begin
	read(bruto, prestacao);
	if (prestacao <= bruto * 0.3) then
	writeln('SIM')
	else writeln('NAO');
end.
