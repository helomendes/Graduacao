program coordenadas;
var
        x,y : longint;
begin
        read(x,y);
        if (x > 0) and (y > 0) then
               writeln('1')
        else
                if (x < 0) and (y > 0) then
                        writeln('2')
                else
                        if (x < 0) and (y < 0) then
                                writeln('3')
                        else
                                if (x >0) and (y < 0) then
                                        writeln('4')
                                else
                                        if (x = 0) and ( y <> 0) then
                                                writeln('Y')
                                        else
                                                if (y = 0) and (x <> 0) then
                                                        writeln('X')
                                                else
                                                        if (x = 0) and (y = 0) then
                                                                writeln('O');
end.
