#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

float factorial (float);
float errores (float, float);

int main ()
{
	float e,x,i,r,s,p,d,erp; //s es la suma, e el exponencial
	int n;
	e=2.718218288;
	
	cout<<"\n                  << S E R I E  D E  M A C L A U R I N >>"<<endl;
	cout<<"\n  > Ingrese el valor de x: ";
	cin>>x;
	cout<<"  > Ingrese el numero de elemtos: ";
	cin>>n;
	//valor de la exponencial elevada
	e=pow(e,x);
	cout<<"\n   Valor de e elevado a la x es: "<<e<<"\n"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"        Numero de elementos         p*           ERROR ERP"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		if(i>1)
		{
			r = factorial (i);
			p = pow(x,i);
			d = p/r;
			s=s+d;
			erp = errores(s,e);
		}
		else
		{
			if(i==0)
			{
				s=1;
				erp = errores(s,e);
			}
			else
			{
				s=s+x;
				erp = errores(s,e);	
			}		
		}
		cout<<"                "<<i+1<<"                  "<<s<<"          "<<erp<<endl;
	}
	cout<<"--------------------------------------------------------------------------"<<endl;
	
	cout<<"\n\n    ZÚÑIGA SANCHEZ ENRIQUE - GRUPO 4CM11";
}

float factorial (float N)
{
	float f;
	if(N == 0 || N==1)
	{
		return (1);
	}
	else
	{
		f = N*factorial(N-1);
	}
	return(f);
}

float errores (float a, float b) //a es la p* y b es p
{
	float e,ea, er, erp;
	e=a-b;
	ea=(e)*(-1);
	er=ea/b;
	erp=er*100;
	return erp;
}






