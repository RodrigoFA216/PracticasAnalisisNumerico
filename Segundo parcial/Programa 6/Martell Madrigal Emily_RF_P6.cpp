#include <stdio.h>                //Martell Madrigal Emily
#include <stdlib.h>
#include <math.h>


double xu,xi;
float el;
double PI=acos(-1.0);

double evaluar(double x)
 {
 return pow(x,3)+pow(2*x,2)+pow(10*x,1)-20;
 }

void algoritmo(double e0, int i)
{
	double fu,fi,fm,xm,e;
	fu=evaluar(xu);
	fi=evaluar(xi);
	xm=xu-((fu*(xi-xu))/(fi-fu));
	fm=evaluar(xm);
	e=((xm-e0)/xm)*100;
	printf("\n     %d         %.5f      %.5f      %.5f      %.5f      %.5f      %.5f      %.5f\n ", i,xi,xu,xm,fi,fu,fm,e);
	if(fm*fi>0)
	 xi=xm;
	else
	 xu=xm;
	if(e<el)
	 {
	 	printf("\nTermina\n");
	 }
	 else
	   {
	   	e0=xm;
	   	algoritmo(e0, ++i);
		} 
	 
}
int main()
{
	printf("\n\t\t\t\t ° Metodo de posicion falsa °");
	printf("\n\nIngrese el punto inicial:\n ");
	scanf("%lf", &xi);
	printf("Ingrese el punto final: \n ");
	scanf("%lf", &xu);
	printf("Ingrese el error: \n ");
	scanf("%f", &el);
	printf("\n  Iteracion       xi           xu          xr          f(xi)          f(xu)          f(xm)        Error \n");
	algoritmo(0,1);
	return 0;
}
