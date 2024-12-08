#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

char *allocString(int size) {
	char *buf = (char *)malloc(size * sizeof(char));
	if (buf == NULL) {
		perror("Unable to alloc array");
		exit(1);
	}
	return buf;
}

char *gain(int n, int m, float *v, float *pq, float *c, int i) {
	char *ret;
    ret = allocString(50);
	int offset = 0;
	float sum = 0;

	for (int j = 0; j < m; j++) {
		sum += pq[2*j] * c[3*i + j];
	}
	offset = snprintf(ret + offset, sizeof(ret), "(%.2f)", v[i]-sum);
	offset = snprintf(ret + offset, sizeof(ret), "x%d", i+1);
	if (i < n-1) {
		if ( > 0)
			offset = snprintf(ret + offset, sizeof(ret), " + ");
		else
			offset = snprintf(ret + offset, sizeof(ret), " - ");
	}

	return ret;
}

char *restrictions(int n, int m, float *v, float *pq, float *c, int i, int j) {
	char *ret = allocString(50);
	int offset = 0;
	offset = snprintf(ret + offset, sizeof(ret), "%.2f", c[3*i + j]);
	offset = snprintf(ret + offset, sizeof(ret), "x%d", i+1);

	return ret;
}
