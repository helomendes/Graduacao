program testa_se_primo;
var i : longint;
function eh_primo(n : longint) : boolean;
var	divisor : longint;
	divs : integer;
begin
	divs := 0;
	for divisor := n downto 1 do
		if (n mod divisor = 0) then
			divs := divs + 1;
	if divs <= 2 then
		eh_primo := true
	else
		eh_primo := false;
end;
begin
	for i := 1 to 10000 do
		if eh_primo(i) then
			writeln(i);
end.
