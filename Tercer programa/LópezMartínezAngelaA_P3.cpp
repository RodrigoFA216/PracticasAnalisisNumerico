/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ER 0.0001
using namespace std;

double uno(double x);
double funo(double x, double er, int n);
double dos(double x);
double fdos(double x, double er, int n);
double tres(double x);
double ftres(double x, double er, int n);
main ()
{

double X0;//er;
int i, N, OK, op;

cout<<"\tMETODO PUNTO FIJO\n";
cout<<"Punto inicial=  ";
cin>> X0;
cout<<"Numero iteraciones aproximadas: ";
cin>>N;
cout<<"Elija un despeje para 2x^2-x-5: \n";
cout<<"1.- d= 2x^2-5\n";
cout<<"2.- d= raiz cuadra ((x+5)/2)\n";
cout<<"3.- d= 5/(2x-1)\n";
cin>> op;
switch (op)
{
	case 1: 
	funo(X0, ER, N);
	break;
	
	case 2: 
	fdos(X0, ER, N);
	break;
	
	case 3: 
	ftres(X0, ER, N);
	break;
}

}

double funo(double x, double er, int n)
{
	int i = 1, OK = 1;
	double P, b;
cout<<"\n\nIt\t\tg(xi)\n";
while(i <= n && OK == 1)
{
P = uno(x);
cout<<" "<<i<<"\t\t"<<P<<"\n";
b = fabs(P - x);
if(b < er)
{

cout<<"Valor final g(xi)="<<P<<"\n";
cout<<"Numero de iteraciones  N = "<< i+1<<"\n";
OK = 0;
}
else
{
i++;
x = P;
}
}
if(OK == 1)
cout<<"\n\nEl metodo va en aumento con N = "<<n<<"\n\n";

system("pause");
return 0;
}

double fdos(double x, double er, int n)
{
	int i = 0, OK = 1;
	double P2, b2, pr;
cout<<"\n\nIt\t\tg(xi)\n";
while(i <= n && OK == 1){
P2 = dos(x);
cout<<" "<<i<<"\t\t"<<P2<<"\n";
b2 = fabs(P2 - x);
if(b2 < er)
{
cout<<"Valor final g(xi)="<<P2<<"\n";
cout<<"Numero de iteraciones N ="<<i+1<<"\n";
OK = 0;
}
else
{
i++;
x = P2;
}
}

if(OK == 1)

system("pause");
return 0;
}

double ftres(double x, double er, int n)
{
	int i = 1, OK = 1;
	double P3, b3;
cout<<"\n\nIt\t\tg(xi)\n";
while(i <= n && OK == 1){
P3 = tres(x);
cout<<" "<<i<<"\t\t"<<P3<<"\n";
b3 = fabs(P3 - x);
if(b3 < er)
{
cout<<"Valor final g(xi)="<<P3<<"\n";
cout<<"Numero de iteraciones N ="<<i+1<<"\n";
OK = 0;
}
else
{
i++;
x = P3;
}
}
if(OK == 1)

system("pause");
return 0;
}


double uno(double x)
	{
double d1;
d1= 2*pow(x,2)-5;
return d1;
	}
	
double dos(double x)
	{
double d2;
d2= sqrt ((x+5)/2);
return d2;
	}

double tres(double x)
	{
double d3;
d3= 5/(2*x-1);
return d3;
	}

