program triangulo;
var
    a, b, c : integer;
    p, area : real;
begin
    read(a, b, c);
    p := (a+b+c)/2;
    area := sqrt(p*(p-a)*(p-b)*(p-c));
    writeln(area :0:3);
end.
