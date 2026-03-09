program progressao;
var
    n, r, a1, an : integer;
begin
    read(n, r, a1);
    an := a1 + ((n-1) * r);
    writeln(an);
end.
