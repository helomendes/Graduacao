program tresesete;
var
    numero : longint;
begin
    read(numero);
    if (numero mod 3 = 0) and (numero mod 7 = 0) then
    writeln('SIM');
    if (numero mod 3 <> 0) or (numero mod 7 <> 0) then
    writeln('NAO');
end.
