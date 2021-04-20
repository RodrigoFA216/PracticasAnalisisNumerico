//Garcia Patricio Roberto Manuel
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

long int factorial(int);
float maclaurin(float,int );
float ERP(float,float);
int main ()
{
	int n;
	float y,mc=1,error,x;
	cout << "\nDigita el valor de x: ";
	cin >> x;
	
	cout << "\nDigite el numero de elementos a calcular: ";
	cin >> n;
	
	y=exp(x);
	cout << "\ne^2: " << y << "\n";
	
	cout << "\n\tnumero de elementos\t\tp*\t\tERP\n";
	
	error=ERP(y,mc);
	
	for (int i;i<n;i++)
	{
		cout << "\n\t\t" << i+1 <<"\t\t\t"<< mc <<"\t\t"<< error <<"%\n";
		if(mc==1)
		{
			mc=mc+x;
			error=ERP(y,mc);
		}
		else
		mc=mc+maclaurin(x,i+1);	
		error=ERP(y,mc);
	}
	system("pause");
}

long int factorial(int n)
{
	if (n>1)
	{
		return n*factorial(n-1);
	}
	else 
		return 1;
}

float maclaurin (float x,int n)
{
	
	if (n>1)
	{
		return (pow(x,n)/factorial(n));
	}
	else 
		return 0;
}
float ERP(float p,float p1)
{
		return ((fabs(p1-p)/p))*100;
	
}
