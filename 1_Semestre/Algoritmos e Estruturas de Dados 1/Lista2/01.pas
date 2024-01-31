program luz;
var
    area, potencia : integer;
begin
    read(area);
    potencia := 80 + 15*(area-3);
    if (area <= 6) then
    writeln('100');
    if (area > 6) then
    writeln(potencia);
end.
