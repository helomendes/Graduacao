program contrario;
var n, m: longint;

function contrario(var n, m : longint) : boolean;
var x, i, y, copyn, novo, exp: longint;
begin
	i := 0;
	novo := 0;
	y := n;
	copyn := n;
	exp := 1;

	while y <> 0 do
	begin
		y := y div 10;
		i := i + 1;
	end;

	while i <> 0 do
	begin
		exp := exp * 10;
		i := i - 1;
	end;

	exp := exp div 10;

	while copyn > 0 do
	begin
		x := copyn mod 10;
		novo := novo + (x * exp);
		copyn := copyn div 10;
		exp := exp div 10;
	end;

	if (novo = m) then
		contrario := true
	else
		contrario := false;
end;

begin
	read (n, m);
	if contrario (n, m) then
		writeln (n, ' eh o contrario de ', m)
	else
		writeln (n, ' nao eh o contrario de ', m);
end.
