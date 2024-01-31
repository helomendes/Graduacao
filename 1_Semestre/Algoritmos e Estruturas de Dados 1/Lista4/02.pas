program populacoes;
var	anos : integer;
	pa, pb, ta, tb : real;
	superar : boolean;
begin
	read(pa, pb, ta, tb);
	superar := false;
	anos := 0;
	if pa < pb then
		if ta > tb then
		begin
			superar := true;
			while pa <= pb do
			begin
				pa := pa + (pa * ta);
				pb := pb + (pb * tb);
				anos := anos + 1;
			end;
		end
		else
			superar := false
	else
		if tb > ta then
		begin
			superar := true;
			while pb <= pa do
			begin
				pa := pa + (pa * ta);
				pb := pb + (pb * tb);
				anos := anos + 1;
			end;
		end
		else
			superar := false;
	if superar then
		writeln(anos)
	else
		writeln('0');
end.
