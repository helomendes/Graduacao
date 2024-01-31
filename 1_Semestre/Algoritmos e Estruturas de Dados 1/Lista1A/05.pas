program sucant;
var
    antecessor, inicial, sucessor : integer;
begin
    read(inicial);
    antecessor := inicial - 1;
    sucessor := inicial + 1;
    writeln(sucessor, ' ', antecessor);
end.
