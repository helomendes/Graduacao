program ano;
var
        nasc, idade : integer;
begin
        read(nasc);
        idade := 2020 - nasc;
        writeln(idade);
        if (idade < 16) then
                writeln('NAO')
        else writeln('SIM');
        if (idade < 18) then
                writeln('NAO')
        else writeln('SIM');
end.
