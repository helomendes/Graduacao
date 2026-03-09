program agenciagovernamental;
var
        x, tres, nove, vinte, mais, total : real;
begin
        read(x);
        tres := 0;
        nove := 0;
        vinte := 0;
        mais := 0;
        total := 0;
        while x <> 0 do
                begin
                        if x <= 3*450 then
                                tres := tres + 1
                        else
                                if (x >= 4*450) and (x <= 9*450) then
                                        nove := nove + 1
                                else
                                        if (x >= 10*450) and (x <= 20*450) then
                                                vinte := vinte + 1
                                        else
                                                mais := mais + 1;
                        total := total + 1;
                        read(x);
                end;
        writeln((tres*100)/total :0:2);
        writeln((nove*100)/total :0:2);
        writeln((vinte*100)/total :0:2);
        writeln((mais*100)/total :0:2);
end.
