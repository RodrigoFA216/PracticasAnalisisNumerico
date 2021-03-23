#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

double fac(int n);
double maclaurin(int n, double x);
void imprimir(int n, double x, double p);
int main()
{
	int n;
	double x,p;
	p=exp(x);
	cout<<"Ingresa el numero de elementos: ", cin>>n;
	cout<<"Ingresa la x: "; cin>>x;
	p=exp(x);
	printf("p= e^x = %.9f\n",p);
	printf("El valor de Taylor para n=%d, x=%f es = %f\n",n,x,maclaurin(n,x));
	//imprimir(n,x,p);
	system("pause");
}
/*void imprimir(int n, double x, double p)
{ ///Errores////
	double e=0,ea=0,er=0,erp=0;
  //Error
  e= maclaurin(n,x)	- p;
  printf("\n%f",e);
  //Error Absoluto
  ea= abs(e);
  cout<<"\n%f",ea;
  //Error Relativo
  er=ea/p;
  cout<<"\n%f",er;
  //Error Relativo Porcentual
  erp=er*100; 
  cout<<"\n%f",erp;
	cout<<"\n #Elementos	 p*		ERP"; 
}*/
double maclaurin(int n, double x)
{
	double t,s=0;
	double e=0,ea=0,er=0,erp=0;
	for(int i=0;i<n; i++)
	{
		t=pow(x,i)/fac(i);
		s+=t;
		
	}
	
	return (s);
}

double fac(int n)
{
	double f=1;
	for(int i=2;i<=n;i++)
	{
		f*=i;
	}
	return f;
}
