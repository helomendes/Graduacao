%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "llvm.h"

int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(const char *s);
FILE *output_file;

SymbolNode *symbol_table = NULL;
int cur_scope = 0;
int temp_count = 0;

%}

// Faz com que os erros sintaticos sejam bem detalhados
%define parse.error detailed

%code requires {
    #include "symbol_table.h"
    #include "llvm.h"
}

%union {
    char *lexema;
    int val_type;
    struct SymbolNode *symbol_list;
    Type type;
    struct LLVMData llvm_data;
}

// Lista de TOKENS da gramatica. No caso, apenas simbolos terminais
%token PROGRAM VAR 
%token INTEIRO REAL
%token FUNCTION PROCEDURE BEGIN_TOKEN END 
%token IF THEN ELSE WHILE DO 
%token OPERADOR_ATRIBUICAO OPERADOR_RELACIONAL MAIS MENOS OR
%token ABRE_PARENTESES FECHA_PARENTESES
%token PONTO_FINAL PONTO_VIRGULA VIRGULA DOIS_PONTOS
%token <lexema> ID NUM OPERADOR_MULTIPLICATIVO

%type <symbol_list> LISTA_DE_IDENTIFICADORES ARGUMENTOS LISTA_DE_PARAMETROS
%type <type> TIPO
%type <llvm_data> VARIAVEL FATOR EXPRESSAO EXPRESSAO_SIMPLES TERMO

// Define a associatividade dessas operacoes. A precedencia ja esta incluida na gramatica
%left MAIS MENOS OR

%%

PROGRAMA: PROGRAM ID ABRE_PARENTESES LISTA_DE_IDENTIFICADORES FECHA_PARENTESES PONTO_VIRGULA {
	    symbol_table = insert_symbol_list(symbol_table, $4);
	}
        DECLARACOES 
        DECLARACOES_DE_SUBPROGRAMAS
        ENUNCIADO_COMPOSTO 
        PONTO_FINAL {
	    fprintf(
		output_file,
		"\tret i32 0\n}\n"
	    );
	}
        ;

LISTA_DE_IDENTIFICADORES: ID {
			    // construção explicita do SymbolNode para o primeiro identificador
			    $$ = list_insert_symbol(NULL, create_symbol($1, T_VAZIO, T_VARIAVEL, cur_scope, NULL));
			}
                        | LISTA_DE_IDENTIFICADORES VIRGULA ID {
			    $$ = list_insert_symbol($1, create_symbol($3, T_VAZIO, T_VARIAVEL, cur_scope, NULL));
			}
                        ;

DECLARACOES: DECLARACOES VAR LISTA_DE_IDENTIFICADORES DOIS_PONTOS TIPO PONTO_VIRGULA {
	    update_symbol_list_type($3, $5);
	    symbol_table = insert_symbol_list(symbol_table, $3);

	    SymbolNode* aux = $3;
	    while(aux) {
		fprintf(
		    output_file,
		    "\t%%%s = alloca %s\n",
		    aux->symbol->id,
		    convert_type(aux->symbol->type)
		);
		aux = aux->next;
	    }
	   }
           | /* empty */ 
           ;

TIPO: INTEIRO {
	$$ = T_INTEIRO;
    }
    | REAL {
	$$ = T_REAL;
    }
    ;

DECLARACOES_DE_SUBPROGRAMAS: DECLARACOES_DE_SUBPROGRAMAS DECLARACAO_DE_SUBPROGRAMA PONTO_VIRGULA
                           | /* empty */
                           ;

DECLARACAO_DE_SUBPROGRAMA: CABECALHO_DE_SUBPROGRAMA DECLARACOES ENUNCIADO_COMPOSTO {
			    symbol_table = remove_scope(symbol_table, cur_scope);
			    cur_scope--;
			 }
                         ;

CABECALHO_DE_SUBPROGRAMA: FUNCTION ID ARGUMENTOS DOIS_PONTOS TIPO PONTO_VIRGULA {
			    symbol_table = insert_symbol(symbol_table, create_symbol($2, $5, T_FUNCAO, cur_scope, NULL));
			    cur_scope++;
			    symbol_table = insert_symbol(symbol_table, create_symbol($2, $5, T_VARIAVEL, cur_scope, NULL));
			    update_symbol_list_scope($3, cur_scope);
			    symbol_table = insert_symbol_list(symbol_table, $3);

			    fprintf(
				output_file,
				"define %s @%s(",
				convert_type($5),
				$2
			    );

			}
                        | PROCEDURE ID ARGUMENTOS PONTO_VIRGULA {
			    symbol_table = insert_symbol(symbol_table, create_symbol($2, T_VAZIO, T_PROCEDURE, cur_scope, NULL));
			    cur_scope++;
			    update_symbol_list_scope($3, cur_scope);
			    symbol_table = insert_symbol_list(symbol_table, $3);
			}
                        ;

ARGUMENTOS: ABRE_PARENTESES LISTA_DE_PARAMETROS FECHA_PARENTESES {
	    $$ = $2;
	  }
          | /* empty */ {
	    $$ = NULL;
	  }
          ;

LISTA_DE_PARAMETROS: LISTA_DE_IDENTIFICADORES DOIS_PONTOS TIPO {
		    update_symbol_list_type($1, $3);
		    $$ = $1;
		   }
                   | VAR LISTA_DE_IDENTIFICADORES DOIS_PONTOS TIPO {
		    update_symbol_list_type($2, $4);
		    $$ = $2;
		   }
                   | LISTA_DE_PARAMETROS PONTO_VIRGULA LISTA_DE_IDENTIFICADORES DOIS_PONTOS TIPO {
		    update_symbol_list_type($3, $5);
		    $$ = join_lists($1, $3);
		   }
                   | LISTA_DE_PARAMETROS PONTO_VIRGULA VAR LISTA_DE_IDENTIFICADORES DOIS_PONTOS TIPO {
		    update_symbol_list_type($4, $6);
		    $$ = join_lists($1, $4);
		   }
                   ;

ENUNCIADO_COMPOSTO: BEGIN_TOKEN ENUNCIADOS_OPCIONAIS END 
                  ;

ENUNCIADOS_OPCIONAIS: LISTA_DE_ENUNCIADOS
                    | /* empty */
                    ;

LISTA_DE_ENUNCIADOS: ENUNCIADO
                   | LISTA_DE_ENUNCIADOS PONTO_VIRGULA ENUNCIADO
                   ;

ENUNCIADO: VARIAVEL OPERADOR_ATRIBUICAO EXPRESSAO {
	    fprintf(
		output_file,
		"\tstore %s %s, ptr %%%s\n",
		convert_type($3.pascal_type),
		$3.value,
		$1.value
	    );
	 }
         | CHAMADA_DE_PROCEDIMENTO
         | ENUNCIADO_COMPOSTO
         | IF EXPRESSAO THEN ENUNCIADO ELSE ENUNCIADO
         | WHILE EXPRESSAO DO ENUNCIADO
         ;

VARIAVEL: ID {
	    SymbolNode* aux = search_symbol(symbol_table, $1);
	    if (aux == NULL || aux->symbol->sym_type != T_VARIAVEL)
		yyerror("Semantic error: variable not declared\n");

	    $$ = create_llvmdata($1, aux->symbol->type);
	}
        ;

CHAMADA_DE_PROCEDIMENTO: ID {
			SymbolNode* aux = search_symbol(symbol_table, $1);
			if (aux == NULL || (aux->symbol->sym_type != T_FUNCAO && aux->symbol->sym_type != T_PROCEDURE))
			    yyerror("Semantic error: procediment not declared\n");
		       }
                    | ID ABRE_PARENTESES LISTA_DE_EXPRESSOES FECHA_PARENTESES {
			SymbolNode* aux = search_symbol(symbol_table, $1);
			if (aux == NULL || (aux->symbol->sym_type != T_FUNCAO && aux->symbol->sym_type != T_PROCEDURE))
			    yyerror("Semantic error: procediment not declared\n");
		    }
                    ;

LISTA_DE_EXPRESSOES: EXPRESSAO 
                   | LISTA_DE_EXPRESSOES VIRGULA EXPRESSAO  
                   ;

EXPRESSAO: EXPRESSAO_SIMPLES
         | EXPRESSAO_SIMPLES OPERADOR_RELACIONAL EXPRESSAO_SIMPLES
         ;

EXPRESSAO_SIMPLES: TERMO {
		    $$ = $1;
		 }
                 | SINAL TERMO {
		    $$ = $2;
		 }
                 | EXPRESSAO_SIMPLES MAIS EXPRESSAO_SIMPLES {
		    char* left = $1.value;
		    char* right = $3.value;

		    if ($1.pascal_type == T_VAZIO || $3.pascal_type == T_VAZIO) {
			yyerror("invalid operator type");
		    }

		    if ($1.pascal_type == T_INTEIRO && $3.pascal_type == T_INTEIRO) {
			char* temp = new_temp(&temp_count);

			fprintf(
			    output_file,
			    "\t%s = add i32 %s, %s\n",
			    temp,
			    left,
			    right
			);

			$$ = create_llvmdata(temp, T_INTEIRO);
		    } else {
			if ($1.pascal_type == T_INTEIRO) {
			    char* cast = new_temp(&temp_count);
			    
			    fprintf(
				output_file,
				"\t%s = sitofp i32 %s to double\n",
				cast,
				left
			    );

			    left = cast;
			}
			if ($3.pascal_type == T_INTEIRO) {
			    char* cast = new_temp(&temp_count);
			    
			    fprintf(
				output_file,
				"\t%s = sitofp i32 %s to double\n",
				cast,
				right		
			    );

			    right = cast;
			}

			char* temp = new_temp(&temp_count);

			fprintf(
			    output_file,
			    "\t%s = fadd double %s, %s\n",
			    temp,
			    left,
			    right
			);

			$$ = create_llvmdata(temp, T_REAL);
		    }
		 }
                 | EXPRESSAO_SIMPLES MENOS EXPRESSAO_SIMPLES {
		    char* left = $1.value;
		    char* right = $3.value;

		    if ($1.pascal_type == T_VAZIO || $3.pascal_type == T_VAZIO) {
			yyerror("invalid operator type");
		    }

		    if ($1.pascal_type == T_INTEIRO && $3.pascal_type == T_INTEIRO) {
			char* temp = new_temp(&temp_count);

			fprintf(
			    output_file,
			    "\t%s = sub i32 %s, %s\n",
			    temp,
			    left,
			    right
			);

			$$ = create_llvmdata(temp, T_INTEIRO);
		    } else {
			if ($1.pascal_type == T_INTEIRO) {
			    char* cast = new_temp(&temp_count);
			    
			    fprintf(
				output_file,
				"\t%s = sitofp i32 %s to double\n",
				cast,
				left
			    );

			    left = cast;
			}
			if ($3.pascal_type == T_INTEIRO) {
			    char* cast = new_temp(&temp_count);
			    
			    fprintf(
				output_file,
				"\t%s = sitofp i32 %s to double\n",
				cast,
				right		
			    );

			    right = cast;
			}

			char* temp = new_temp(&temp_count);

			fprintf(
			    output_file,
			    "\t%s = fsub double %s, %s\n",
			    temp,
			    left,
			    right
			);

			$$ = create_llvmdata(temp, T_REAL);
		    }

		 }
                 | EXPRESSAO_SIMPLES OR EXPRESSAO_SIMPLES {
		    if ($1.pascal_type != T_INTEIRO || $3.pascal_type != T_INTEIRO) {
			yyerror("operator OR requires integer operands");
		    }
		 }
                 ;

TERMO: FATOR
     | TERMO OPERADOR_MULTIPLICATIVO FATOR {
	struct LLVMData left = $1;
	char* op_str = $2;
	struct LLVMData right = $3;

	char* temp = new_temp(&temp_count);

	if (strcmp(op_str, "*") == 0) {
	    if (left.pascal_type == T_VAZIO|| right.pascal_type == T_VAZIO) {
		yyerror("Invalid operand type");
	    }
	    if (left.pascal_type == T_REAL || right.pascal_type == T_REAL) {
		char* left_casting = left.value;
		char* right_casting = right.value;

		if (left.pascal_type == T_INTEIRO) {
		    char* left_temp = new_temp(&temp_count);
		    fprintf(
			output_file,
			"\t%s = sitofp i32 %s to double\n",
			left_temp,
			left.value
		    );
		    left_casting = left_temp;
		}

		if (right.pascal_type == T_INTEIRO) {
		    char* right_temp = new_temp(&temp_count);
		    fprintf(
			output_file,
			"\t%s = sitofp i32 %s to double\n",
			right_temp,
			right.value
		    );
		    right_casting = right_temp;
		}

		fprintf(
		    output_file,
		    "\t%s = fmul double %s, %s\n",
		    temp,
		    left_casting,
		    right_casting
		);
		$$ = create_llvmdata(temp, T_REAL);

	    } else {
		fprintf(
		    output_file,
		    "\t%s = mul i32 %s, %s\n",
		    temp,
		    left.value,
		    right.value
		);
		$$ = create_llvmdata(temp, T_INTEIRO);
	    }
	} else if (strcmp(op_str, "/") == 0) {
	    if (left.pascal_type == T_VAZIO || right.pascal_type == T_VAZIO) {
		yyerror("Invalid operand type");
	    }

	    char* left_casting = left.value;
	    char* right_casting = right.value;

	    if (left.pascal_type == T_INTEIRO) {
		char* left_temp = new_temp(&temp_count);
		fprintf(
		    output_file,
		    "%s = sitofp i32 %s to double\n",
		    left_temp,
		    left.value
		);
		left_casting = left_temp;
	    }

	    if (right.pascal_type == T_INTEIRO) {
		char* right_temp = new_temp(&temp_count);
		fprintf(
		    output_file,
		    "%s = sitofp i32 %s to double\n",
		    right_temp,
		    right.value
		);
		right_casting = right_temp;
	    }

	    fprintf(
		output_file,
		"\t%s = fdiv double %s, %s\n",
		temp,
		left_casting,
		right_casting
	    );

	    $$ = create_llvmdata(temp, T_REAL);
	} else if (strcmp(op_str, "div") == 0) {
	    if (left.pascal_type == T_VAZIO|| right.pascal_type == T_VAZIO) {
		yyerror("Invalid operand type");
	    }

	    if (left.pascal_type != T_INTEIRO || right.pascal_type != T_INTEIRO) {
		yyerror("Cannot div double value");
	    }

	    fprintf(
		output_file,
		"\t%s = sdiv i32 %s, %s\n",
		temp,
		left.value,
		right.value
	    );

	    $$ = create_llvmdata(temp, T_INTEIRO);
	} else if (strcmp(op_str, "mod") == 0) {
	    if (left.pascal_type == T_VAZIO|| right.pascal_type == T_VAZIO) {
		yyerror("Invalid operand type");
	    }

	    if (left.pascal_type != T_INTEIRO || right.pascal_type != T_INTEIRO) {
		yyerror("Cannot div double value");
	    }

	    fprintf(
		output_file,
		"\t%s = srem i32 %s, %s\n",
		temp,
		left.value,
		right.value
	    );
	    $$ = create_llvmdata(temp, T_INTEIRO);
	} else {
	    yyerror("Unknown multiplicative operator");
	}
     }
     ;

FATOR: ID  {
	SymbolNode* aux = search_symbol(symbol_table, $1);
	if (aux == NULL)
	    yyerror("Semantic error: identifier not declared\n");

	char* temp = new_temp(&temp_count);

	fprintf(
	    output_file,
	    "\t%s = load %s, ptr %%%s\n",
	    temp,
	    convert_type(aux->symbol->type),
	    $1
	);

	$$ = create_llvmdata(temp, aux->symbol->type);

     }
     | ID ABRE_PARENTESES LISTA_DE_EXPRESSOES FECHA_PARENTESES {
	SymbolNode* aux = search_symbol(symbol_table, $1);
	if (aux == NULL)
	    yyerror("Semantic error: identifier not declared\n");
     }
     | NUM {
	struct LLVMData fator;

	if (strchr($1, '.') || strchr($1, 'e') || strchr($1, 'E')) {
	    fator = create_llvmdata($1, T_REAL);
	} else {
	    fator = create_llvmdata($1, T_INTEIRO);
	}

	$$ = fator;
     }
     | ABRE_PARENTESES EXPRESSAO FECHA_PARENTESES {
	$$ = $2;
     }
     ;

SINAL: MAIS
     | MENOS
     ;


%%

int main(int argc, char ** argv) {

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        yylineno=1;

	output_file = fopen("output.ll", "w");

	if (!output_file) {
	    fprintf(stderr, "Error creating output file 'a.out'\n");
	    return 1;
	}

	fprintf(
	    output_file,
	    "define i32 @main() {\nentry:\n"
	);

	symbol_table = insert_symbol(
	    symbol_table,
	    create_symbol("read", T_VAZIO, T_FUNCAO, cur_scope, NULL)
	);
	symbol_table = insert_symbol(
	    symbol_table,
	    create_symbol("write", T_VAZIO, T_FUNCAO, cur_scope, NULL)
	);

	if (yyparse() == 0) {
	    printf("[SUCCESS] The file is syntactically valid\n");
	    printTable(symbol_table);
	} else {
	    printf("[FAIL] Syntax error found\n");
	}

	fclose(yyin);
	fclose(output_file);

    } else {
        fprintf(stderr, "Arquivo de entrada nao foi fornecido\n");
	return 1;
    }    

    return 0;
}

void yyerror(const char *s) {
  fprintf(stderr, "Erro na linha %d: %s\n", yylineno,s);
  exit(1);
}

