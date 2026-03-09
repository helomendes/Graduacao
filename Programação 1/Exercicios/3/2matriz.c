#include <stdio.h>
#define LIN 3
#define COL 3
int main()
{
	int M[LIN][COL];
        int i, j;
	printf("Insira os elementos: ");
	for (int i=0; i < COL; i++)
	{
		for(int j=0; j < LIN; j++)
			scanf("%d", &M[i][j]);
	}
	for (int i = 0; i < COL; i++)
	{
		for(int j=0; j < LIN; j++)
			printf("%d\t", M[i][j]);
		printf("\n");
	}
}

