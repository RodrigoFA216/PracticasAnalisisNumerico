#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

double Calculo_numeroe(double,double); //calculo de e^x
double Calculo_Aproximacion(double, double); //serie de mclaurin o P*

using namespace std;

main()
{
	double x, elementos, numeroe,p, P_aprox,conteo, errorRP;
	
	cout<<"Ingrese el valor de x: "<<endl;
	cin>>x;
	cout<<"Ingrese el numero de elementos a tomar: "<<endl;
	cin>>elementos;
	numeroe = 2.718281;
	conteo = 1;
	
	p = Calculo_numeroe(x,numeroe);
	
	cout<<"\tS E R I E D E M A C L A U R I N "<<endl;
    cout<<"#elementos\tP*\tError RP"<<endl;
	
	do
	{
		P_aprox= Calculo_Aproximacion(x,conteo);
		errorRP= ((fabs(P_aprox - p))/p)*100;
		cout<<fixed<<setprecision(4)<<conteo<<"\t\t"<<P_aprox<<"\t"<<errorRP<<endl;
		conteo++;
		
	}while(conteo<=elementos);
	
	
    
    
}

double Calculo_numeroe(double x,double numeroe)
{
	double valorp;
	
	valorp = pow(numeroe,x);
	
	return valorp;
}

double Calculo_Aproximacion(double x, double conteo)
{
	double valorp_aproximacion,factorial = 1;
	
	if(conteo==1)
	{
		valorp_aproximacion = 1;
		return valorp_aproximacion;
	}
	
	else if(conteo ==2)
	{
		valorp_aproximacion = 1 + x;
		return valorp_aproximacion;
		
	}
	else
	{
		
		valorp_aproximacion = 1 + x;
		for(int i=2;i<conteo;i++)
		{
			factorial=1;
			for(int j=1;j<=i;j++)
			{
				factorial = factorial*j;
			}
			valorp_aproximacion = (valorp_aproximacion)+((pow(x,i))/factorial);
			
		}
		return valorp_aproximacion;	
	}
		
	
}




