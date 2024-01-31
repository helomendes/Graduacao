program banco;
var
        sm, per : real;
begin
        read(sm);
        if sm <= 200 then
                begin
                        per := 0;
                        writeln(sm:0:0);
                        writeln(per:0:0);
                end
        else
                if sm <= 400 then
                        begin
                                per := 20;
                                writeln(sm:0:0);
                                writeln(per:0:0, '%');
                        end
                else
                        if sm <= 600 then
                                begin
                                        per := 30;
                                        writeln(sm:0:0);
                                        writeln(per:0:0, '%');
                                end
                        else
                                if sm > 600 then
                                        begin
                                                per := 40;
                                                writeln(sm:0:0);
                                                writeln(per:0:0, '%');
                                        end;
end.
