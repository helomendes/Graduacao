#ifndef STRUCTS_H
#define STRUCTS_H

struct pedido{
    char ingrediente;
    struct pedido *prox;
};

struct pilha{
    struct pedido *cabeca;
};

struct clientes {
    int count;
    int qual;
    struct clientes *prox;
    struct clientes *anterior;
};


struct fila {
    struct clientes *inicio;
    struct clientes *fim;
};

#endif //STRUCT_H