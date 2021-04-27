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
	double xi=0, xf=0,xm=0,xm1=0,fxm=0,fxi=0,fxf=0;
	int nitera=1;
	
	printf("\t\t\t\tSuarez Flores Irais\n");
	printf("\t\t\t\tMetodo de Posicion Falsa\n\n");
	
	printf("Ingrese Xi: ");
	scanf("%lf",&xi);
	printf("\nIngrese Xf: ");
	scanf("%lf",&xf);
	printf("\nIngrese el valor de Epsilon: ");
	scanf("%lf",&E);
	
	printf("\n\n |# Iteracion|  \t |Xi|      \t |fxi|   \t |Xf|      \t |fxf| \t |Xm|      \t |fxm|    \t  |Error|\n");	
	

		while(e>E){
			
		fxi=f(xi);
		fxf=f(xf);
		xm=xf-(f(xf)*(xi-xf))/(f(xi)-f(xf));
		fxm=f(xm);
		e=fabs(xm-xm1);
		printf("\n   %i      \t %lf   \t %lf   \t %lf   \t %lf   \t %lf   \t %lf \t%lf",nitera,xi,fxi,xf,fxf,xm,fxm,e);
		xm=xm1;
		nitera=nitera+1;
	}
	
	
}
