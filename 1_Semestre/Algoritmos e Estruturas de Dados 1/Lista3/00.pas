program soma50;
var
        x, n, soma : longint;
begin
        x := 0;
        soma := 0;
        while x <= 50 do
                begin
                        n := x*x;
                        soma := soma + n;
                        x := x + 1;
                end;
        writeln(soma);
end.
