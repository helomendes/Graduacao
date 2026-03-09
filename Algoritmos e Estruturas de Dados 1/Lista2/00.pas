program agua;
var
    tempf : integer;
    tempc : real;
begin
    read(tempf);
    tempc := (5*tempf - 160)/9;
    writeln(tempc :0:2);
    if (tempc <= 0) then
    writeln('solido');
    if (tempc > 0) and (tempc < 100) then
    writeln('liquido');
    if (tempc >= 100) then
    writeln('gasoso');
end.
