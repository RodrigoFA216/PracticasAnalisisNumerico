#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

double Obtener_XM(double, double);
double Evaluar_XM(double);
double Valores_XM[20]={0};

using namespace std;

main()
{
	double Xi,Xd,tol,XM,Fxm,Error;
	Xi = 1;
	Xd = 2;
	tol= 0.001;
	int it=1;
	
    cout<<"\tB I S E C C I O N "<<endl;
    cout<<"it\tXi\tXd\tXM\tF(XM)\tError"<<endl;
	
	XM = Obtener_XM(Xi,Xd); //Se realiza el primer ciclo aparte para no mostrar el primer error
	Fxm = Evaluar_XM(XM);
	Valores_XM[it] = XM;
	cout<<fixed<<setprecision(4)<<it<<"\t"<<Xi<<"\t"<<Xd<<"\t"<<XM<<"\t"<<Fxm<<"\t"<<endl;
	it ++;
	if(Fxm >0)
	{
		Xd = XM; 
	}
	else
	{
		Xi = XM;
	}
    
	do
	{
		XM = Obtener_XM(Xi,Xd);// a partir del segundo ciclo ya se calcula el error y se imprime de acuerdo a la formula
		Fxm = Evaluar_XM(XM);
		Valores_XM[it] = XM;
		Error = fabs(Valores_XM[it]-Valores_XM[it-1]);
		cout<<fixed<<setprecision(4)<<it<<"\t"<<Xi<<"\t"<<Xd<<"\t"<<XM<<"\t"<<Fxm<<"\t"<<Error<<endl;
		it ++;
		if(Fxm >0)
		{
			Xd = XM; 
		}
		else
		{
			Xi = XM;
		}
		
	}while(Error>tol);
    //|XM+1-XM| = |1.5-1| = 0.5 || |1.5-2| =0
	
}

double Obtener_XM(double Xi, double Xd)
{
	double XM;
	
	XM = (Xi+Xd)/2;
	
	return XM;
}

double Evaluar_XM(double XM)
{
	double evaluacionXM;
	
	evaluacionXM = (pow(XM,3))+((2)*(pow(XM,2)))+(10*XM)-20;
	
	return evaluacionXM;

}

