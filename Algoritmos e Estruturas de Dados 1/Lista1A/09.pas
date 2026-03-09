program mediafinal;
var
    P1, P2, P3, soma : integer;
    media : real;
begin
    read(P1, P2, P3 );
    soma := P1 + (P2 * 2) + (P3 * 3);
    media := soma / (1+2+3);
    writeln(media :0:0);
end.
