program intervalo;
var
    numero : longint;
begin
    read(numero);
    if (numero > -15) and (numero < 30) then
    writeln(numero - numero - numero);
    if (numero <= -15) or (numero >= 30) then
    writeln(numero);
end.
