#include <stdlib.h>
#include<stdio.h>
#include <math.h>
#include<conio.h>


int main(){
	
	double E=0.001,e,x;
	double xo=0, r1, r2, func, dfunc;
	int nitera=1;
	
	printf("\t\t\t\tSuarez Flores Irais\n");
	printf("\t\t\t\tMetodo de Newton-Raphson\n\n");

	printf("Ingrese Xo: ");
	scanf("%lf",&xo);
	
	
	func=(pow(xo,3))+(2*(pow(xo,2)))+(10*(xo))-20;
	
	dfunc=3*(pow(xo,2))+(4*(xo))+10;
	
	printf("\n\nError= 0.001\n |# Iteracion|     \t |Xo|          \t |xi+1|        \t  |Error|\n");
	
	x=xo-(func/dfunc);
	e=fabs(x-xo);
	printf("\n     %i           \t %lf      \t %lf      \t %lf",nitera,xo,x,e);
	
	xo=x;
	
	while(e>E){
		
		func=(pow(xo,3))+(2*(pow(xo,2)))+(10*(xo))-20;
		dfunc=3*(pow(xo,2))+(4*(xo))+10;
		x=xo-(func/dfunc);
		e=fabs(x-xo);
		nitera=nitera+1;
		printf("\n     %i           \t %lf      \t %lf      \t %lf",nitera,xo,x,e);
		xo=x;
		
	}
	
}
