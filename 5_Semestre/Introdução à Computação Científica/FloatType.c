#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef union
{
	int32_t i;
	float f;
	struct
	{
		uint32_t mantissa : 23;
		uint32_t exponent : 8;
		uint32_t sign : 1;
	} parts;
} Float_t;

void printFloat_t(Float_t num)
{
	printf("f:%1.9e, ix:0x%08X, s:%d, e:%d, mx:0x%06X\n",
			num.f, num.i, num.parts.sign, num.parts.exponent, num.parts.mantissa);
}

Float_t calculaEpsilonRelativo(Float_t num)
{
	Float_t epsilon;
	epsilon.f = num.f / 2.0f;
	while (num.f + epsilon.f / 2.0f > num.f)
		epsilon.f /= 2.0f;

	return epsilon;
}

int AlmostEqualRelative(Float_t A, Float_t B)
{
	Float_t diff, largest, relEpsilon;
	diff.f = fabs(A.f - B.f);
	A.f = fabs(A.f);
	B.f = fabs(B.f);

	largest.f = (B.f > A.f) ? B.f : A.f;
	relEpsilon.f = largest.f * FLT_EPSILON;

	printf("\tThe difference: ");
	printFloat_t(diff);

	printf("\trel. Epsilon: ");
	printFloat_t(relEpsilon);

	if (diff.f <= relEpsilon.f)
		return 1;
	return 0;
}

int AlmostEqualUlps(Float_t A, Float_t B, int maxULPs)
{
	if (A.parts.sign != B.parts.sign) {
		if (A.f == B.f)
			return 1;
		return 0;
	}

	int ulpsDiff = abs(A.i - B.i);
	printf("\tULPs diff: %d\n", ulpsDiff);
	   	
	if (ulpsDiff < maxULPs)
		return 1;
	return 0;
}

int main()
{
	Float_t num, num2;
	num.f = 1.0f;
	num2.f = 1000.0f;

	printf("\nEpsilon: %1.15f, Epsilon: %1.19e\n", FLT_EPSILON, FLT_EPSILON);

	printf("\nDigite um numero: ");
	scanf("%f", &num.f);
	printf("\n Epsilon: ");
	printFloat_t(calculaEpsilonRelativo(num));

	printf("\n\n****************************************\n\n");

	printf("\nDigite um número: ");
	scanf("%f", &num.f);
	for (int i = 0; i<5; i++) {
		Float_t next, diff;
		next.i = num.i+1;
		diff.f = fabs(next.f -num.f);
		printf("\n");
		printFloat_t(num);
		printFloat_t(next);
		printFloat_t(diff);

		num = next;
	}

	printf("\n\n****************************************\n\n");
	
	printf("Digite dois números reais: ");
	while (scanf("%f %f", &(num.f), &(num2.f)) == 2) {
		printf("\nEpsilon: %1.15f, Epsilon: %1.9e\n", FLT_EPSILON, FLT_EPSILON);
        
        printf("\nOs numeros :\n\t");
        printFloat_t(num); printf("\t");
        printFloat_t(num2);
        
        Float_t diff;
        diff.f = fabs(num.f - num2.f);
        printf("\n\tSubtraidos: "); 
        printFloat_t(diff);
        
        printf("\n\n\tComparacao Epsilon Relativo: \n");
        AlmostEqualRelative(num, num2);
            

        printf("\n\n\tComparacao ULPs: \n");
        AlmostEqualUlps(num, num2, 10);

        printf("\nDigite dois numeros reais: ");
	}

	return 0;
}
