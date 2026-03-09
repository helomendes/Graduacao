program casa;
var
    comprimento, largura, area : integer;
begin
    read(comprimento, largura);
    area := comprimento * largura;
    write(area, ' ');
    writeln(area * 18);
end.
