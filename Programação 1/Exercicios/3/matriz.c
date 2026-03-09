#include <stdio.h>
#define LIN 3
#define COL 3
int main()
{
	int M[LIN][COL];
        int i=0, j=0;
	printf("Insira uma matriz de 9 elementos: ");
	while (i<LIN)
	{
		j=0;
		while(j < COL)
		{	
			scanf("%d", &M[i][j]);
			j++;
		}
		i++;
	}
	i=0;
	j=0;
	while (i<LIN)
	{
		j=0;
		while(j < COL)
		{
			printf("%d\t", M[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

