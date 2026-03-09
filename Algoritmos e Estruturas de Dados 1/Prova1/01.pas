program um;
var
	A, B, divisor : longint;
	divisores : integer;
begin
	read(A, B);
	divisores := 1;
	divisor := 2;
	while (divisor <= A) and (divisor <= B) do
	begin
		if A mod divisor = 0 then
		begin
			if B mod divisor = 0 then
				divisores := divisores + 1;
		end;
		divisor := divisor + 1;
	end;
	if divisores = 1 then
		writeln('sao primos entre si')
	else
		writeln('nao sao primos entre si');
end.
