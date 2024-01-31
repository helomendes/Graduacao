program carro;
var
    fabrica : integer;
     imposto, distribuidor, consumidor : real;
begin
    read(fabrica);
    imposto := (45 * fabrica) div 100;
    distribuidor := (28 * fabrica) div 100;
    consumidor := fabrica + imposto + distribuidor;
    writeln(consumidor :0:0);
end.
