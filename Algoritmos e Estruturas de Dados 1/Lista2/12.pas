program conjunto;
var
        i : integer;
        a, b, c : real;
begin
        read (i, a, b, c);
        if i = 1 then
                begin
                        if (a < b) and (b < c) then
                                writeln(a:0:0, ' ',b:0:0, ' ', c:0:0)
                        else
                                if (c < b) and (b < a) then
                                        writeln(c:0:0, ' ', b:0:0, ' ', a:0:0)
                                else
                                        if (b < c) and (c < a) then
                                                writeln(b:0:0, ' ',c:0:0, ' ',a:0:0)
                                        else
                                                if (b < a) and (a < c) then
                                                        writeln(b:0:0, ' ',a:0:0, ' ',c:0:0)
                                                else
                                                    if (a < c) and (c < b) then
                                                        writeln(a:0:0, ' ', c:0:0, ' ', b:0:0);
                end
        else
                if i = 2 then
                        begin
                                if (a > b) and (b > c) then
                                        writeln(a:0:0, ' ',b:0:0, ' ', c:0:0)
                                else
                                        if (c > b) and (b > a) then
                                                writeln(c:0:0, ' ', b:0:0, ' ', a:0:0)
                                        else
                                                if (b > c) and (c > a) then
                                                        writeln(b:0:0, ' ',c:0:0, ' ',a:0:0)
                                                else
                                                        if (b > a) and (a > c) then
                                                                writeln(b:0:0, ' ',a:0:0, ' ',c:0:0)
                                                    else
                                                        if (a > c) and (c > b) then
                                                            writeln(a:0:0, ' ', c:0:0, ' ', b:0:0);                        
                        end
                else
                        if i = 3 then
                                begin
                                        if (a < b) and (b < c) then
                                                writeln(a:0:0, ' ',c:0:0, ' ', b:0:0)
                                        else
                                                if (c < b) and (b < a) then
                                                        writeln(b:0:0, ' ', a:0:0, ' ', c:0:0)
                                                else
                                                        if (b < c) and (c < a) then
                                                                writeln(b:0:0, ' ',a:0:0, ' ',c:0:0)
                                                        else
                                                                if (b < a) and (a < c) then
                                                                        writeln(a:0:0, ' ',c:0:0, ' ',b:0:0)
                                                                else
                                                                    if (a < c) and (c < b) then
                                                                        writeln(a:0:0, ' ', b:0:0, ' ', c:0:0);
                                end;
end.
