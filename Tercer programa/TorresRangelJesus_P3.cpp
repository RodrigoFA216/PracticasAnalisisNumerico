#include <iostream>
#include <stdio.h>
#include <math.h>
#define e 2.718281828

double fun (double);
double fun(double x)
	{
		
        double a;
        a = (sqrt((x+5)/2));
        return a;
    }

int main ()
{
    double PuntoInicial,Tolerancia,ResultadoXi,error;
    int NumeroIteraciones, verificacion;
    int i;
    
    printf ("\t\t\tTORRES RANGEL JESUS\n");
    printf ("\t\t\t   Punto Fijo\n");
    printf("\n\nIndique la proximacion inicial Xi: ");
    scanf ("%lf", &PuntoInicial);
    printf("Indique la Tolerancia: ");
    scanf("%lf", &Tolerancia);
    printf("Indique el numero de iteraciones : ");
    scanf("%d", &NumeroIteraciones);

    i = 0;
    verificacion = 1;
 
    printf("\n\nI\tXi\t\t  g(Xi)\t\t Error\n");
    while(i <= NumeroIteraciones && verificacion == 1){

    ResultadoXi = fun (PuntoInicial);
    printf("%d\t%lf\t%12.8f\t%f\n", i,PuntoInicial, ResultadoXi, error);

    error = fabs(ResultadoXi - PuntoInicial);
    if(error < Tolerancia)
	{		
        printf("\nSolucion aproximada g(Xi) = %12.8f\n", ResultadoXi);
        printf("Numero de iteraciones necesarias  = %d\n", i+1);
        printf("Tolerancia = %lf\n\n", Tolerancia);
        verificacion = 0;
    }

    else
	{
        i++;
       PuntoInicial = ResultadoXi;
    }
    }

    if(verificacion == 1)
	{
    	printf("\n\nEl metodo fallo con un numero de iteraciones N = %d\n\n",NumeroIteraciones);
        system("pause");
        return 0;
	}

}
