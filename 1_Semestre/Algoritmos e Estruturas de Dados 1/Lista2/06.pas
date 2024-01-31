program venda;
var
        codigo, quant : integer;
        preco, valor : real;
begin
        read(codigo);
        read(quant);
        if codigo = 1001 then
            begin
                preco := 5.32;
                valor := quant * preco;
                writeln(valor:0:2);
            end
        else
                if codigo = 1324 then
                    begin
                        preco := 6.45;
                        valor := quant * preco;
                        writeln(valor:0:2);
                    end
                else
                        if codigo = 6548 then
                            begin
                                preco := 2.37;
                                valor := quant * preco;
                                writeln(valor:0:2);
                            end
                        else
                                if codigo = 987 then
                                    begin
                                        preco := 5.32;
                                        valor := quant * preco;
                                        writeln(valor:0:2);
                                    end
                                else
                                        if codigo = 7623 then
                                            begin
                                                preco := 6.45;
                                                valor := quant * preco;
                                                writeln(valor:0:2);
                                            end
                                        else
                                                writeln('ERRO');
end.
