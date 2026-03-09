/* Constantes */

#define DBL_FIELD "%15.10lg"
#define SEP_RES "\n\n\n"

#define DEF_SIZE 128
#define BASE 32

#define ABS(num) ((num) < 0.0 ? -(num) : (num))

#define UF 8
#define BK 32

/* Tipos para matrizes e vetores */

typedef double real_t;

typedef real_t *MatRow;
typedef real_t *Vetor;

/* ----------- FUNÇÕES ---------------- */

MatRow geraMatRow_otimizada(int m, int n, int zerar);
Vetor geraVetor_otimizada(int n, int zerar);

void multMatVet_otimizada(MatRow restrict mat, Vetor restrict v, int m, int n, Vetor restrict res);
void multMatMat_otimizada(MatRow restrict A, MatRow restrict B, int n, MatRow restrict C);
