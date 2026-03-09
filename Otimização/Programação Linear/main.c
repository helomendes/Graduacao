#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "linprog.h"

int main() {
	char *buf;
	size_t bufsize = 32;
	size_t chars = 0;
	int n, m;
	n = m = 0;
	float *v, *pq, *c;
	FILE* arq;

	buf = (char *)malloc(bufsize * sizeof(char));
	if (buf ==  NULL) {
		perror("Unable to allocate buffer");
		exit(1);
	}

	readNM(buf, bufsize, chars, &n, &m);

	v = allocFloat(n);
	pq = allocFloat(2*m);
	c = allocFloat(n*m);

	readV(buf, bufsize, chars, v);
	readPQ(buf, bufsize, chars, pq, m);
	readC(buf, bufsize, chars, c, n);

	//printVars(n, m, v, pq, c);
	printf("\n");


	arq = fopen("output.lp", "w");
	if (!arq) {
		perror("Unable to create output file");
		exit(2);
	}

	for (int i = 0; i < n; i++) {
		char *str;
		str = gain(n, m, v, pq, c, i);
		fprintf(arq, "%s", str);
		free(str);
	}
	fprintf(arq, ";\n\n");

	// restrictions
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			char *str;
			str = restrictions(n, m, v, pq, c, i, j);
			fprintf(arq, "%s", str);
			if (i < n-1)
				fprintf(arq, " + ");
			free(str);
		}
		fprintf(arq, " <= %.2f;\n", pq[2*j + 1]);
	}

	for (int i = 0; i < n; i++)
		fprintf(arq, "x%d >= 0;\n", i+1);


	fclose(arq);
	free(buf);
	freeAll(v, pq, c);

	return 0;
}
