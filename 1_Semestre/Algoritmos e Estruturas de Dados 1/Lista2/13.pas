program IR;
var
        salario, imposto, x : real;
begin
        read(salario);
        if salario <= 540 then
                writeln('NAO')
        else
                if salario <= 1424 then
                        begin
                                imposto := 0;
                                x := imposto * salario;
                                writeln(1, ' ', x :0:2);
                        end
                else
                        if salario <= 2150 then
                                begin
                                        imposto := 0.075;
                                        x := imposto * salario;
                                        writeln(2, ' ', x :0:2);
                                end
                        else
                                if salario <= 2866 then
                                        begin
                                                imposto := 0.15;
                                                x := imposto * salario;
                                                writeln(3, ' ', x :0:2);
                                        end
                                else
                                        if salario <= 3582 then
                                                begin
                                                        imposto := 0.225;
                                                        x := imposto * salario;
                                                        writeln(4, ' ', x :0:2);
                                                end
                                        else
                                                if salario > 3582 then
                                                        begin
                                                                imposto := 0.275;
                                                                x := imposto * salario;
                                                                writeln(5, ' ', x :0:2);
                                                        end;
end.
