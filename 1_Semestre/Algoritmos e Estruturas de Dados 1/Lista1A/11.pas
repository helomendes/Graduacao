program pagamentos;
var
    valor, troco : integer;
begin
    read(valor);
    troco := valor div 100;
    writeln(troco);
end.
