//PROGRAMA PARA FUNCION DE PUNTO FIJO


#include <math.h>
#include <iostream>

using namespace std;

float funcion(int);
float despeje(double);

int main()
{
	double  err,fx,x,x0,hp=1;
	
	
	
	cout << "f(x)= 2x^2-x-5 ";
	cout << "\nDespeje de g(X): sqrt(x+5)/2";
	cout << "\ningresa el punto x: ";
	cin >> x0;
	cout << "\ningresa el error: ";	
	cin >> err;
	system ("cls");	
		fx=despeje(x0);
		x=x0-fx;
		cout <<"\nx\t\tg(x)\t\terror\n";
		cout << x0 <<"\t\t"<<fx<<"\t\t"<<x;
	do
	{
		x0=fx;
		fx=despeje(fx);
		x=(x0-fx);
		if(x<0)
		{
			x=x*-1;
		}
		if(x-err<0)
		{
			hp=0;
		}
		cout <<"\n" <<x0 <<"\t\t"<<fx<<"\t\t"<<x;
	}
	while(hp!=0);
	
	cout<<"\n";
	system ("pause");

}

float despeje(double n)
{
	return sqrt((n+5)/2);	
}
