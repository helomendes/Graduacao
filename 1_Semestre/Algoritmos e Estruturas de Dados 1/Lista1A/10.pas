program timer;
var
    segundos, h, min, s : Longint;
begin
    read(segundos);
    h := segundos div 3600;
    min := segundos mod 3600 div 60;
    s := segundos mod 3600 mod 60;
    writeln(h, ':', min, ':', s);
end.
