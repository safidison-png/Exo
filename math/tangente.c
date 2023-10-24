#include <stdio.h>
#include <math.h>
#define eps 1e-6
#include "tangente-lib.h"

int main(){
	double x0 = 1, a = 0, b = 0;
	double r = 0;
	r = racine(x0);
	printf("La racine par la methode de Newton est %lf\n", r);
	printf("\nPar la methode de Descart, entrer les deux bornes x0 = ");
	scanf("%lf", &a);
	printf("x1 = ");
	scanf("%lf", &b);
	r = secante(a, b);
	printf("La racine par la methode de Descart est %lf", r);
	
	
	return 0;
}
