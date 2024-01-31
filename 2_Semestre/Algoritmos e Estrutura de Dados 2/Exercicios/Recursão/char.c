#include <stdio.h>
#include <string.h>

unsigned int mudaTipo(char txt[], int i)
{
	if (i<0)
		return 0;
	return (mudaTipo(txt, i-1)*10 + (txt[i]-48));
}

int main()
{
	char txt[200];
	fgets(txt, 200, stdin);
	txt[strcspn (txt, "\n")] = '\0';

	printf("%u\n", mudaTipo(txt, strlen(txt)-1));
	return 0;
}
