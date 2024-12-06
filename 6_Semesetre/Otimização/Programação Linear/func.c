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

void readNM(char *buf, size_t bufsize, size_t chars, int *n, int *m) {
	chars = getline(&buf, &bufsize, stdin);
	float aux = 0;
	for (int c = 0; c < chars; c++) {
		if (buf[c] != ' ' && buf[c] != '\n') {
			float temp = (float)(buf[c] - '0');
			if (aux == 0)
				aux = temp;
			else
				aux = aux*10 + temp;
		}
		else {
			if (*n == 0)
				*n = aux;
			else
				*m = aux;
			aux = 0;
		}
	}
}

void readV(char *buf, size_t bufsize, size_t chars, float *v) {
	chars = getline(&buf, &bufsize, stdin);
	int x = 0;
	float aux = 0;
	for (int c = 0; c < chars; c++) {
		if (buf[c] != ' ' && buf[c] != '\n')
			processString(buf[c], &aux);
		else {
			v[x] = aux;
			aux = 0;
			x++;
		}
	}
}

void readPQ(char *buf, size_t bufsize, size_t chars, float *pq, int m) {
	int x = 0;
	float aux = 0;
	for (int l = 0; l < m; l++) {
		chars = getline(&buf, &bufsize, stdin);
		for (int c = 0; c < chars; c++) {
			if (buf[c] != ' ' && buf[c] != '\n')
				processString(buf[c], &aux);
			else {
				pq[x] = aux;
				aux = 0;
				x++;
			}
		}
	}
}

void readC(char *buf, size_t bufsize, size_t chars, float *c, int n) {
	int x = 0;
	float aux = 0;
	for (int l = 0; l < n; l++) {
		chars = getline(&buf, &bufsize, stdin);
		int flag = 0;
		float comma = 0;
		for (int ch = 0; ch < chars; ch++) {
			if (buf[ch] == '.' || buf[ch] == ',') {
				comma = aux;
				flag = 1;
				aux = 0;
			}
			else if (buf[ch] != ' ' && buf[ch] != '\n')
				processString(buf[ch], &aux);
			else {
				if (flag)
					aux = comma + aux/10;
				c[x] = aux;
				aux = 0;
				x++;
			}
		}
	}
}

void freeAll(float *v, float *pq, float *c) {
    free(v);
    free(pq);
    free(c);
}
