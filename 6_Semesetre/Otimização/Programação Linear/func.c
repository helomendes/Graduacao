#include <stdio.h>
#include <stdlib.h>

void printVars(int n, int m, float *v, float *pq, float *c) {
    printf("N: %d\nM: %d\n", n, m);

    for (int i = 0; i < n; i++)
        printf("V[%d]: %.2f\t", i, v[i]);
    printf("\n");


    for (int i = 0; i < m*2; i += 2)
        printf("PQ[%d]: %.2f, PQ[%d]: %.2f\n", i, pq[i], i+1, pq[i+1]);

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("C[%d][%d]: %.2f\t", i, j, c[index]);
            index++;
        }
        printf("\n");
    }
}

void processString(char ch, float *aux) {
	float temp = (float)(ch - '0');
	if (*aux == 0)
		*aux = temp;
	else
		*aux = *aux * 10 + temp;
}

float *allocFloat(int size) {
    float *array = (float *)malloc(size * sizeof(float));
    if (array == NULL) {
        perror("Unable to alloc array");
        exit(1);
    }
    return array;
}

void freeAll(float *v, float *pq, float *c) {
    free(v);
    free(pq);
    free(c);
}

