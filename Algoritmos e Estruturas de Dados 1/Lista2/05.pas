program faculdade;
var
    media, P1, P2, P3, faltas : real;
begin
    read(P1, P2, P3, faltas);
    media := (P1+P2+P3)/3;
    if (faltas >= 10) then
    writeln('NAO')
    else if (faltas < 10) and (media < 4.0) then
    writeln('NAO');
    if (faltas < 10) and (media >= 4.0) and (media < 7.0) then
    writeln('TALVEZ');
    if (faltas < 10) and (media >= 7.0) then
    writeln('SIM');
end.
