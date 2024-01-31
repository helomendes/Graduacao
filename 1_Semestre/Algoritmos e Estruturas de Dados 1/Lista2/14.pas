program seilaproduto;
var
        n, x, produto : longint;
begin
        read(n);
        x := 2;
        produto := 1;
        while x <= n*2 do
                begin
                        produto := produto * x;
                        x := x + 2;
                end;
        writeln(produto);
end.
