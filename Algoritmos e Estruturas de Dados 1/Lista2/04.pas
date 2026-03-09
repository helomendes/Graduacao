program data;
var
    dia, mes, ano : integer;
begin
    read(dia, mes, ano);
    if (mes > 4) and (dia >= 29) then
    writeln(2020-ano);
    if (mes > 4) and (dia <= 29) then
    writeln(2020-ano);
    if (mes = 4) and (dia > 29) then
    writeln(2020-ano);
    if (mes = 4) and (dia = 29) then
    writeln(2021-ano);
    if (mes = 4) and (dia < 29) then
    writeln(2021-ano);
    if (mes < 4) then
    writeln(2021-ano);
end.
