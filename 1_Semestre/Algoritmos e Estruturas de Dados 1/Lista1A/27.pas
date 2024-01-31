program carro;
var
    placa, digito : integer;
begin
    read(placa);
    digito := placa mod 1000 mod 100 mod 10;
    writeln(digito);
end.
