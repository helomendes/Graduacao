program cozinha;
var
        azulejo, area, quant, caixas : real;
begin
        read(azulejo, area);
        if azulejo = 1 then
                begin
                        quant := area/0.2;
                        caixas := quant / 10;
                        writeln(caixas :0:0, ' caixas');
                end
        else
                if azulejo = 2 then
                        begin
                                quant := area/0.3;
                                caixas := quant/10;
                                writeln(caixas :0:0, ' caixas');
                        end
                else
                        if azulejo = 3 then
                                begin
                                        quant := area/0.4;
                                        caixas := quant/10;
                                        writeln(caixas :0:0, ' caixas');
                                end;
end.
