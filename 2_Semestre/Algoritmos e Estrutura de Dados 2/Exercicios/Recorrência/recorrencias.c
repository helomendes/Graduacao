#include <stdio.h>
#include <math.h>

int main(){
	int n = 100000;
	int Ins, ins;
	int sel;
	int merge;
	int Quick, quick;
	int Heap, heap;

	ins = n - 1;
	Ins = (n*n + n - 2)/2;

	sel = (n*n - n)/2;

//	merge = n*log2(n);

//	quick = n*log2(n);
	Quick = (n*n + n - 2)/2;

	heap = 0;
//	Heap = n + 2*n*log2(n);

	printf("insertion: %d <= c <= %d\nselection: %d\nmerge: n da\nquick: n da <= c <= %d\nheap: %d <= c <= n da\n", ins, Ins, sel, Quick, heap);

	return 0;
}
