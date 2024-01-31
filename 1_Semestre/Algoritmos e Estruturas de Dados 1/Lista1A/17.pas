program faixa;
var
    numero : integer;
begin
    read (numero);
    if (numero > 20) and (numero < 90) then
    writeln('SIM');
    if (numero <= 20) or (numero >= 90) then
    writeln('NAO');
end.
