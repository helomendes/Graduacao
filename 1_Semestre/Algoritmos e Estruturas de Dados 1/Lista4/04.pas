program vvalorquadrado;
var
	n, nant : longint;
	valorquadrado : boolean;
begin
	read(n); 
	valorquadrado := false;
	while (n <> 0) do
		begin
			nant := n;
			read(n);
			if (n = nant*nant) then
			begin			
				valorquadrado := true;
				read(n);
			end
			else
			begin
				valorquadrado := false;
				n := 0;
			end;
		end;
	if valorquadrado then
		writeln('1')
	else
		writeln('0');
end.
