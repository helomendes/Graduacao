program poligono;
var
        num, lado, areaq, perimetrot : integer;
begin
        read(num, lado);
        areaq := lado * lado;
        perimetrot := num * lado;
        if num = 3 then
                writeln('TRIANGULO ', perimetrot)
        else
                if num = 4 then
                        writeln('QUADRADO ', areaq)
                else
                        if num = 5 then
                                writeln('PENTAGONO')
                        else
                                if (num < 3) or (num > 5) then
                                        writeln('ERRO');
end.
