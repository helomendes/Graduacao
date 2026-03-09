program produtoimpar;
var
        n, x, soma : integer;
begin
        read(n);
        x := 1;
        soma := 0;
        while x <= n*2 do
                begin
                        soma := soma + x;
                        x := x + 2;
                end;
        writeln(soma);
end.
