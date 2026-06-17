#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {
    T_INTEIRO,
    T_REAL,
    T_VAZIO
} Type;

typedef enum {
    T_VARIAVEL,
    T_FUNCAO,
    T_PROCEDURE
} SymbolType;

typedef struct Symbol {
    char *id;
    Type type;
    SymbolType sym_type;
    int scope;
    char *llvm_reg;
} Symbol;

typedef struct SymbolNode {
    struct Symbol *symbol;
    struct SymbolNode *next;
} SymbolNode;

void printTable(SymbolNode *table);

Symbol *create_symbol(char* id, Type type, SymbolType sym_type, int scope, char* llvm_reg);
SymbolNode* join_lists(SymbolNode* list_1, SymbolNode* list_2);
void free_node(SymbolNode *node);
const char* convert_type(Type type);

SymbolNode* insert_symbol(SymbolNode *structure, Symbol* symbol);
SymbolNode* insert_symbol_list(SymbolNode *structure, SymbolNode *list);

SymbolNode* list_insert_symbol(SymbolNode* list, Symbol* sym);
void update_symbol_list_type(SymbolNode* list, Type type);
void update_symbol_list_scope(SymbolNode* list, int scope);

SymbolNode* search_symbol(SymbolNode *structure, char *id);
SymbolNode* remove_scope(SymbolNode *table, int scope);

#endif
