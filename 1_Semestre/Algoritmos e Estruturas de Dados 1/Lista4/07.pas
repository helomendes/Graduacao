program numeros;
var
	i, j, k, soma : integer;
	media : real;
begin
	read(i, j, k);
	soma := i + j + k;
	media := soma / 3;
	if (j mod i = 0) and (k mod j = 0) then
		writeln(soma)
	else
		if (j = i + 1) and (k = j + 1) then
			writeln(k, ' ', j, ' ', i)
		else
			if (j = i - 1) and (k = j - 1) then
				writeln(i, ' ', j, ' ', k)
			else
				writeln(media:0:0);
end.
