program empresa;
var
        salario, novo, aumento, code : real;
begin
        read(salario, code);
        if code = 101 then
                begin
                        aumento := 0.1;
                        novo := (salario * aumento) + salario;
                        writeln(salario:0:2);
                        writeln(novo:0:2);
                        writeln(aumento*salario:0:2);
                end
        else
                if code = 102 then
                        begin
                                aumento := 0.2;
                                novo := (salario*aumento)+salario;
                                writeln(salario:0:2);
                                writeln(novo:0:2);
                                writeln(aumento*salario:0:2);
                        end
                else
                        if code = 103 then
                                begin
                                        aumento := 0.3;
                                        novo := (salario*aumento)+salario;
                                        writeln(salario:0:2);
                                        writeln(novo:0:2);
                                        writeln(aumento*salario:0:2);
                                end
                        else
                                begin
                                        aumento := 0.4;
                                        novo := (salario*aumento)+salario;
                                        writeln(salario:0:2);
                                        writeln(novo:0:2);
                                        writeln(aumento*salario:0:2);
                                end;
end.
