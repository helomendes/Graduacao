program retangulos;
var n, x, y, xm, ym, xa, ya, xma, yma, xf, yf, xmf, ymf, i :integer;
	interseccao : boolean;
begin
	read(n);
	interseccao := true;
	while n <> 0 do
		begin
			read(x, y, xm, ym);
			i := 1;
			if n = 1 then
				begin
					xf := x;
					yf := y;
					xmf:= xm;
					ymf := ym;
				end;
			if n > 1 then
				begin
					while (i < n) do
						begin
							read(xa, ya, xma, yma);
							if (xa <= xm) and (xma > x) then
								begin
									if (ya <= ym) and (yma > y) then
										begin
											if (xa >= x) then
												x := xa
											else
												x := x;
											if (ya >= y) then
												y := ya
											else
												y := y;
											if (xma <= xm) then
												xm := xma
											else
												xm := xm;
											if (yma <= ym) then
												ym := yma
											else
												ym := ym;
										end
									else
										interseccao := false;
								end
							else
								interseccao := false;
							i := i+ 1;
						end;
					xf := x;
					yf := y;
					xmf := xm;
					ymf := ym;
				end;
				if interseccao then
					writeln(xf, yf, xmf, ymf)
				else
					writeln('nenhum');
				read(n);
		end;
end.
