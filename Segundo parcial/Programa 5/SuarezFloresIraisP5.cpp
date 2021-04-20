#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include<conio.h>

  double f(int x);

double f(double x){
	
	double f;
	
	f=(pow(x,3))+(2*(pow(x,2)))+(10*(x))-20;
	return f;
}

int main(){
	
	double E=0,e=10;
	double xo=0, x1=0,x2=0,x3=0;
	int nitera=1;
	
	printf("\t\t\t\tSuarez Flores Irais\n");
	printf("\t\t\t\tMetodo de la Secante\n\n");
	
	printf("Ingrese Xo: ");
	scanf("%lf",&xo);
	printf("\nIngrese X1: ");
	scanf("%lf",&x1);
	printf("\nIngrese Epsilon: ");
	scanf("%lf",&E);
	
	printf("\n\n |# Iteracion|     \t |X1|          \t |xi|        \t  |Error|\n");
	
	while(e>E){
		
		x2=x1-(f(x1)*(xo-x1))/(f(xo)-f(x1));
		e=fabs(x2-x1);
		printf("\n     %i           \t %lf      \t %lf      \t %lf",nitera,x1,x2,e);
		xo=x1;
		x1=x2;
		x2=x3;
		nitera=nitera+1;
	}
	
}
