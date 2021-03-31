#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

long int fac(int);
float serie(float,int );
float ERP(float,float);
int main ()
{
	int elemento;
	float y,mc=1,mistake,x;
	cout << "ingresa x: ";
	cin >> x;
	
	cout << "\nColoque el numero de elementos: ";
	cin >> elemento;
	
	y=exp(x);
	cout << "\ne^2: " << y << "\n";
	
	cout << "\n\t N° de elementos\t\tp*\t\tERP\n";
	
	mistake=ERP(y,mc);
	
	for (int i;i<elemento;i++)
	{
		cout << "\n\t" << i+1 <<"\t\t\t"<< mc <<"\t\t"<< mistake<<"%\n";
		if(mc==1)
		{
			mc=mc+x;
			mistake=ERP(y,mc);
		}
		else
		mc=mc+serie(x,i+1);	
		mistake=ERP(y,mc);
	}
	system("pause");
}

long int fac(int n)
{
	if (n>1)
	{
		return n*fac(n-1);
	}
	else 
		return 1;
}

float serie (float x,int n)
{
	
	if (n>1)
	{
		return (pow(x,n)/fac(n));
	}
	else 
		return 0;
}
float ERP(float p,float p1)
{
		return ((fabs(p1-p)/p))*100;
	
}
