struct unit;

struct fila;

void inicializarFila(struct fila **f);

void criarElemento(struct unit **novo);

void enqueue(struct fila **f);

void dequeue(struct fila **f);

void imprimirFila(struct fila **f);
