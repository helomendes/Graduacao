program expoente;
var
    numero, quadrado, cubo : integer;
begin
    read(numero);
    quadrado := numero*numero;
    cubo := numero*numero*numero;
    if (numero) >= 0 then
    writeln(cubo);
    if (numero) < 0 then
    writeln(quadrado);
end.
