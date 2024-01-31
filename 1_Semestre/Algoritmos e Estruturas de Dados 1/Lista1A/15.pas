program parouimpar;
var
    N : integer;
begin
    read(N);
    if (N) mod 2 = 0 then
    writeln('PAR');
    if (N) mod 2 <> 0 then
    writeln('IMPAR');
end.
