#include <stdio.h>
#include <stdlib.h>

typedef struct presente{
	int valor;       /* Valor sentimental do presente. */
	int peso;        /* Peso do presente. */
	int id;          /* Indice do presente no v_presentes. */
} presente_t;

typedef struct saco{
    int valor;       /* Soma do valor sentimental de todos os presentes no saco. */
    int peso;        /* Soma do peso de todos os presentes no saco. */
    presente_t *v;   /* Vetor de ponteiros para presentes. */
    int it;          /* Inteiro para guardar o indice do ultimo presente no em *v. */
} saco_t;

void le_presentes(int n, presente_t v[]){
	int i, valor, peso;
	for (i = 0; i < n; i++){
		scanf("%d %d", &valor, &peso);
		v[i].valor = valor;
		v[i].peso = peso;
		v[i].id = i;
	}
}

/* Retorna um presente que tem -1 em todos os seus parametros.
 * Eh usado -1 porque o id pode ser 0 na linguagem C. */
presente_t presente_nulo(){
    presente_t presente;
    presente.id = -1;
    presente.peso = -1;
    presente.valor = -1;
    return presente;
}

/* Inicializa o saco com presentes "nulos". */
void inicializa_saco(saco_t *atual, int n){
    int i;
    presente_t presente = presente_nulo();
    for (i = 0; i < n; i++){
        atual->v[i] = presente;
    }
}

saco_t *cria_saco(int n){
    saco_t *atual = malloc(sizeof(saco_t));
    if (!atual)
        return NULL;
    atual->v = malloc(sizeof(presente_t)*(n + 1));
    if (!atual->v)
        return NULL;
    inicializa_saco(atual, n);
    atual->peso = 0;
    atual->valor = 0;
    atual->it = 0;
    return atual;
}

void passar_saco(saco_t *saco1, saco_t *saco2, int n){
    int i = 0;
    inicializa_saco(saco2, n);
    while (saco1->v[i].id != -1){
        saco2->v[i] = saco1->v[i];
        i++;
    }
    saco2->peso = saco1->peso;
    saco2->valor = saco1->valor;
}

void adicionar_presente(saco_t *atual, presente_t presente){
    int i = atual->it;
    atual->v[i] = presente;
    atual->it++;
    atual->peso = atual->peso + presente.peso;
    atual->valor = atual->valor + presente.valor;
}

void remover_presente(saco_t *atual){
    int i = atual->it - 1;
    presente_t presente = atual->v[i]; 
    atual->v[i] = presente_nulo();
    atual->it--;
    atual->peso = atual->peso - presente.peso;
    atual->valor = atual->valor - presente.valor;
}

void imprime_saco(saco_t *saco){
    int i = 0;
    if (saco->v[i].id == -1){
        printf("Saco vazio\n");
        return;
    }
    /* Loop para imprimir os id's. */
    while (saco->v[i].id != -1){
        printf("%d ", saco->v[i].id);
        i++;
    }
    printf("\n");
    printf("%d\n", saco->valor);
}

saco_t *destroi_saco(saco_t *saco){
    free(saco->v);
    free(saco);
    return NULL;
}

saco_t *melhor_saco(int pmax, int n, int i, saco_t *atual, saco_t *melhor, presente_t v[]){
    /* Caso base. */
    if (atual->peso + v[i].peso > pmax)
        return atual;
    adicionar_presente(atual, v[i]);
    if (melhor->valor < (atual)->valor)
        passar_saco(atual, melhor, n);
    i++;
    /* Loop para testar diferentes combinacoes. */
    for (i=i; i<n; i++)
        /* Chamada recursiva. */
        melhor_saco(pmax, n, i, atual, melhor, v);
    remover_presente(atual);
    return melhor;
}

saco_t *solucao(int pmax, int n, int i, saco_t *atual, saco_t *melhor, presente_t v[]){
	for(i=i; i<n; i++)
		melhor_saco(pmax, n, i, atual, melhor, v);
	return melhor;
}

int main(){
    int n, pmax;
    scanf("%d %d", &n, &pmax);
    saco_t *atual = cria_saco(n);
    saco_t *melhor = cria_saco(n);
    presente_t v_presentes[n];
    le_presentes(n, v_presentes);
    int i = 0;
    /* Loop para mudar o primeiro presente do saco. */
    solucao(pmax, n, i, atual, melhor, v_presentes);
    imprime_saco(melhor);
    atual = destroi_saco(atual);
    melhor = destroi_saco(melhor);
    return 0;
}
