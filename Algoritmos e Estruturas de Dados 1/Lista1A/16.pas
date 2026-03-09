program div3;
var
    numero : longint;
begin
    read(numero);
    if (numero) mod 3 = 0 then
    writeln('SIM');
    if (numero) mod 3 <> 0 then
    writeln('NAO');
end.
