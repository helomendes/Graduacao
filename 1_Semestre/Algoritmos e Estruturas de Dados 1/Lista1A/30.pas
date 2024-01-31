program carro;
var
    placa, algarismo : integer;
begin
    read(placa);
    algarismo := placa mod 1000 mod 100 div 10;
    writeln(algarismo);
end.
