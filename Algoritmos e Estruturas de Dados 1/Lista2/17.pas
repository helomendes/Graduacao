program maiormenor;
var
        numero, maior, menor : longint;
begin
        read(numero);
        menor := numero;
        maior := numero;
        while numero <> 0 do
                begin
                        if numero > maior then
                                maior := numero
                        else
                                if numero < menor then
                                        menor := numero;
                        read(numero);
                end;
        writeln(maior, ' ', menor);
end.
