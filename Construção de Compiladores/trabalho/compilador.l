%option yylineno 

%{
#include "compilador.tab.h" // para utilizar os TOKENS criados pelo BISON

%}

ID [a-zA-Z][a-zA-Z0-9_]*
NUM [0-9]+(\.[0-9]+)?([Ee][+-]?[0-9]+)?

%%

"program"	{ return PROGRAM; }
"var"		{ return VAR; }

"integer"	{ return INTEIRO; }
"real"		{ return REAL; }

"function"	{ return FUNCTION; }
"procedure"	{ return PROCEDURE; }
"begin"		{ return BEGIN_TOKEN; }
"end"		{ return END; }

"if"		{ return IF; }
"then"		{ return THEN; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
"do"		{ return DO; }

":="		{ return OPERADOR_ATRIBUICAO; }
">"		{ return OPERADOR_RELACIONAL; }
"<"		{ return OPERADOR_RELACIONAL; }
"="		{ return OPERADOR_RELACIONAL; }
"<>"		{ return OPERADOR_RELACIONAL; }
"<="		{ return OPERADOR_RELACIONAL; }
">="		{ return OPERADOR_RELACIONAL; }
"+"		{ return MAIS; }
"-"		{ return MENOS; }
"*"		{  yylval.lexema = strdup("*"); return OPERADOR_MULTIPLICATIVO; }
"/"		{ yylval.lexema = strdup("/"); return OPERADOR_MULTIPLICATIVO; }
"div"		{ yylval.lexema = strdup("div"); return OPERADOR_MULTIPLICATIVO; }
"mod"		{ yylval.lexema = strdup("mod"); return OPERADOR_MULTIPLICATIVO; }
"or"		{ return OR; }

"("		{ return ABRE_PARENTESES; }
")"		{ return FECHA_PARENTESES; }

"."		{ return PONTO_FINAL; }
";"		{ return PONTO_VIRGULA; }
","		{ return VIRGULA; }
":"		{ return DOIS_PONTOS; }

{ID} { // Ação léxica associada ao token
    yylval.lexema = strdup(yytext);
    return ID;
}

{NUM} {
    yylval.lexema = strdup(yytext);
    return NUM;
}

[ \t]+ {/*ignorar espacos em branco, incluindo tabs*/}

\n { yylineno++; }

. { printf("Unrecognized character ignored: %s in line %d\n", yytext, yylineno); }

%%

// Sem codigo aqui, flex sera usado pelo bison e nao 'standalone'
