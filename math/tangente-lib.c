#include <stdio.h>
#include <math.h>
#define eps 1e-6
#include "tangente-lib.h"

double f(double x){
	double a = log(x)-1;
	return a;
}

double fp(double x){
	double a = 1/x;
	return a;
}

double racine(double x0){
	double a, x = x0, y;
	y = f(x);
	while(fabs(y)>eps){
		a = fp(x);
		x -= y/a;
		y = f(x);
	}
	return x;
}

double secante(double a,double b){
	double s=b;
	while(f(s)>eps){
		
		if(f(a)*f(s)>0){return NAN;}
		
		s=(fabs(f(a))*s+f(s)*a)/(fabs(f(a))+f(s));		
	}
	return s;
}
