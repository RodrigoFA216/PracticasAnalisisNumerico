#include <math.h>
#include <iostream>

using namespace std;

float desp(double);

int main()
{
	double  error,fx,gx,x0,aux=1;
	
	cout << " f(X): 2x^2-x-5";
	cout << "\ndespeje g(X): raiz cuadrada de (x+5)/2";
	cout << "\ningresa el punto x0: ";
	cin >> x0;
	cout << "\ningresa el error: ";	
	cin >> error;
	
	system ("cls");	
	
		fx=desp(x0);
		gx=x0-fx;
		cout <<"\nx\t\tg(x)\t\terror\n";
		cout << x0 <<"\t\t"<<fx<<"\t\t"<<gx;
	
	do
	{
		x0=fx;
		fx=desp(fx);
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

float desp(double n)
{
	return sqrt((n+5)/2);	
}
