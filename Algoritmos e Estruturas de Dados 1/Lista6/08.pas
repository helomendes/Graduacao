program media_alunos;
var	i, n, p1, p2, p3, media : longint;
function media_ponderada(var p1, p2, p3 : longint) : longint;
var	soma : longint;
begin
	soma := p1 + p2*2 + p3*3;
	media_ponderada := soma div 6;
end;

function aprovado(var media : longint) : boolean;
begin
	if media < 50 then
		aprovado := false
	else
		aprovado := true;
end;

begin
    read (n);
    for i:= 1 to n do
    begin
        read (p1, p2, p3);
        media:= media_ponderada (p1, p2, p3);
        if aprovado (media) then
            writeln ('aluno ',i,' aprovado com media: ', media)
        else
            writeln ('aluno ',i,' reprovado com media: ', media);
    end;
end.
