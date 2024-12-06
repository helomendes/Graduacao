#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {
	char *buf;
	size_t bufsize = 32;
	size_t chars;
	int n, m;
	n = m = 0;
	float *v, *pq, *c;

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

	printVars(n, m, v, pq, c);

	// agora a parte de formatação da saída

	free(buf);
	freeAll(v, pq, c);

	return 0;
}
