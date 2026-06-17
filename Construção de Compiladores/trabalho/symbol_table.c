#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

void printTable(SymbolNode *table) {
    printf("\n============== TABELA DE SÍMBOLOS ==============\n");
    printf("%-15s | %-10s | %-10s | %-8s | %-15s\n", "Identificador", "Tipo", "Tipo Simbolo", "Escopo", "Reg LLVM");
    printf("------------------------------------------------\n");

    SymbolNode *sym_table = table;
    if (sym_table == NULL) {
        printf("\t(EMPTY TABLE)\n");
    }

    while (sym_table != NULL) {
        char *str_type;
        switch(sym_table->symbol->type) {
            case T_INTEIRO:
                str_type = "INTEGER";
                break;
            case T_REAL:
                str_type = "REAL";
                break;
            case T_VAZIO:
                str_type = "VAZIO";
                break;
            default:
                str_type = "UNKNOWN";
        }

        char *sym_type;
        switch(sym_table->symbol->sym_type) {
            case T_VARIAVEL:
                sym_type = "VARIABLE";
                break;
            case T_FUNCAO:
                sym_type = "FUNCTION";
                break;
            case T_PROCEDURE:
                sym_type = "PROCEDURE";
                break;
            default:
                sym_type = "UNKNOWN";
        }

        printf("%-15s | %-10s | %-10s | %-8d | %-15s\n", 
           sym_table->symbol->id, 
           str_type, 
           sym_type,
           sym_table->symbol->scope, 
           sym_table->symbol->llvm_reg ? sym_table->symbol->llvm_reg : "Nenhum");

        sym_table = sym_table->next;
    }
    printf("================================================\n\n");
}

Symbol *create_symbol(char* id, Type type, SymbolType sym_type, int scope, char* llvm_reg) {
    Symbol *aux = malloc(sizeof(Symbol));
    if (aux == NULL) {
        perror("malloc");
        exit(1);
    }
    aux->id = strdup(id);
    aux->type = type;
    aux->sym_type = sym_type;
    aux->scope = scope;
    aux->llvm_reg = llvm_reg ? llvm_reg : NULL;

    return aux;
}

SymbolNode* join_lists(SymbolNode* list_1, SymbolNode* list_2) {
    if (list_1 == NULL)
        return list_2;

    SymbolNode* aux = list_1;
    while (aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = list_2;

    return list_1;
}

void free_node(SymbolNode *node) {
    free(node->symbol->id);
    free(node->symbol->llvm_reg);
    free(node->symbol);
    free(node);
}

const char* convert_type(Type type) {
    switch(type) {
        case T_INTEIRO:
            return "i32";
        case T_REAL:
            return "double";
        default:
            return "void";
    }
}

SymbolNode* insert_symbol(SymbolNode *structure, Symbol* symbol) {
    for (SymbolNode *aux = structure; aux != NULL; aux = aux->next) {
        Symbol *sym_aux = aux->symbol;
        if(strcmp(sym_aux->id, symbol->id) == 0 && sym_aux->scope == symbol->scope) {
            fprintf(stderr, "Semantic error: Variable '%s' already declared in this scope\n", symbol->id);
            exit(1);
        }
    }

    SymbolNode *new_node = malloc(sizeof(SymbolNode));
    if (new_node == NULL) {
        perror("malloc");
        exit(1);
    }

    new_node->symbol = symbol;
    new_node->next = structure;

    return new_node;
}

SymbolNode* insert_symbol_list(SymbolNode *structure, SymbolNode *list) {
    for (SymbolNode* aux = list; aux != NULL; aux = aux->next) {
        Symbol *sym_aux = aux->symbol;
        structure = insert_symbol(structure, sym_aux);
    }

    return structure;
}

SymbolNode* search_symbol(SymbolNode *structure, char *id) {
    SymbolNode *aux = structure;
    
    for (SymbolNode* aux = structure; aux != NULL; aux = aux->next) {
        if (strcmp(aux->symbol->id, id) == 0) {
            return aux;
        }
    }
    return NULL;
}

SymbolNode* list_insert_symbol(SymbolNode* list, Symbol* sym) {
    SymbolNode* new_node = malloc(sizeof(SymbolNode));
    new_node->symbol = sym;
    new_node->next = list;

    return new_node;
}

void update_symbol_list_type(SymbolNode* list, Type type) {
    for (SymbolNode* aux = list; aux != NULL; aux = aux->next) {
        aux->symbol->type = type;
    }
}

void update_symbol_list_scope(SymbolNode* list, int scope) {
    for (SymbolNode* aux = list; aux != NULL; aux = aux->next) {
        aux->symbol->scope = scope;
    }
}

SymbolNode* remove_scope(SymbolNode *table, int scope) {
    SymbolNode *cur = table;
    SymbolNode *last = NULL;

    while (cur != NULL) {
        if (cur->symbol->scope == scope) {
            SymbolNode *aux = cur;
            if (last == NULL) {
                table = cur->next;
            } else {
                last->next = cur->next;
            }

            cur = cur->next;

            free_node(aux);

        } else {
            printf("\n");
            last = cur;
            cur = cur->next;
        }
    }

    return table;
}
