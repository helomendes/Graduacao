#ifndef FILACERTO_H
#define FILACERTO_H
#include "structs.h"

int getPedido (struct fila *ordem_pedidos, int *num_cliente);

void pop_fila (struct fila *pedido_feito);

void imprimirTodosPedidos(struct fila *pedido_impresso);

void checarpedido(int *pedido, struct fila *meuspedidos);

#endif //FILACERT0_H
