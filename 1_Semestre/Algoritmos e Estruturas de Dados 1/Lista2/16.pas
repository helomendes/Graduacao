program fibonacci;
var
        n, ultimo, penultimo, soma, i : integer;
begin
        read(n);
        ultimo := 1;
        penultimo := 0;
	i := 2;
        soma := 0;
        while i <= n do
                begin
                        soma := penultimo + ultimo;
                        penultimo := ultimo;
                        ultimo := soma;
                        i := i + 1;
                end;
        writeln(soma);
end.
