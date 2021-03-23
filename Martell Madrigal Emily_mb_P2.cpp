#include <iostream>                                                                   //Martell Madrigal Emily
#include <cmath>    //almacena funciones para poder realizar operaciones matemáticas
#include <iomanip> //setprecision

using namespace std; 

double f(double x) 
{
	return pow(x,3)+pow(2*x,2)+pow(10*x,1)-20;
}

int main()
{
	char salir;
	int i,n;
	double a,b,p=0.001,e; 
	do 
	{
		cout<<"\n\t\t ° Metodo de Biseccion ° ";
		cout<<"\n\n Ingrese el intervalo inicial [a, b]. "<<endl;
		cout<<"\nIngrese a: ";
		cin>>a;
		cout<<"Ingrese b: ";
		cin>>b;
		cout<<"Ingrese el # de Iteraciones: ";
		cin>>n;
		i=1;
		cout<<"\n  # Iteraciones"<<"\t\t"<<setw(20)<<"\t\t\t"<<setw(8)<<"Error"<<endl;
		while(i<=n)
		{
			p=(a+b)/2.0;
			e=fabs(a-b);
			cout<<"\n\t"<<i<<"\t"<<setw(8)<<a<<"\t"<<setw(8)<<b<<"\t"<<setw(8)<<p<<"\t"<<setw(8)<<e<<endl;
			if(f(a)*f(p)<0)
			{
				a=a;
				b=p;
			}
			else
			{
			 	a=p;
			 	b=b;
			}
			i++;
		}
		cout<<"\n\t Desea salir? Si=s/No=n: ";
		cin>>salir;
	}
	while(salir!='s' && salir!='N');
	
}

