compilador: compilador.y compilador.l symbol_table.c llvm.c
	bison -d compilador.y
	flex compilador.l
	clang -o compilador compilador.tab.c lex.yy.c symbol_table.c llvm.c -lfl

clean:
	rm -f lex.yy.c compilador compilador.tab.c compilador.tab.h
