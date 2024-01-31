program carro;
var
    placa, digito : integer;
begin
    read(placa);
    digito := placa mod 1000 div 100;
    writeln(digito);
end.
