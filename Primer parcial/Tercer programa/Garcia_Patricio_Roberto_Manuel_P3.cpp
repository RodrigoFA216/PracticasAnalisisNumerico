//Garcia Patricio Roberto M.

#include <math.h>
#include <iostream>
#include<stdlib.h>

using namespace std;

float func(int);
float despeje(double);

int main()
{
	double  error,fx,gx,x0,aux=1;
	
	cout<<"\t\t-Vamos a utilizar el metodo punto fijo de una funcion-";
	cout << "\n\nEscribe el punto x0: ";
	cin >> x0;
	cout << "\nEscribe el error: ";	
	cin >> error;
	
	system ("cls");	
	
		fx=despeje(x0);
		gx=x0-fx;
		cout <<"\nx\t\tg(x)\t\terror\n";
		cout << x0 <<"\t\t"<<fx<<"\t\t"<<gx;
	
	do
	{
		x0=fx;
		fx=despeje(fx);
		gx=(x0-fx);
		if(gx<0)
		{
			gx=gx*-1;
		}
		if(gx-error<0)
		{
			aux=0;
		}
		cout <<"\n" <<x0 <<"\t\t"<<fx<<"\t\t"<<gx;
	}
	while(aux!=0 );
	
	cout<<"\n";
	system ("pause");

}

float func(int n)
{
	return (2*(pow(n,2)))-n-5;
}
float despeje(double n)
{
	return sqrt((n+5)/2);	
}
