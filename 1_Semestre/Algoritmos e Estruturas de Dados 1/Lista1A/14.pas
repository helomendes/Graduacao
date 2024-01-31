program divisivel;
var
    numero : longint;
begin
    read(numero);
    if (numero) div 5 = (numero) / 5 then
    writeln('SIM');
    if (numero) div 5 <> (numero) / 5 then
    writeln('NAO');
end.
