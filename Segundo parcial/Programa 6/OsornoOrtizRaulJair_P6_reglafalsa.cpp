#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

double Evaluar_funcion(double);
double Obtener_Xm(double,double,double,double);


using namespace std;

main()
{
	int i;
	double Xi,Xf,Fx,Fxi,Fxf,Xm,tol,Error,Fxm;
	double valores_Xi[10];
	double valores_Xm[10];
	cout<<"\t\tMETODO DE POSICION FALSA"<<endl;
	cout<<"Introduzca Xi: ";
	cin>>Xi;
	cout<<"Introduzca Xf: ";
	cin>>Xf;
	cout<<"Introduzca la tolerancia: ";
	cin>>tol;
	
	Fx= Evaluar_funcion(Xi);
	valores_Xi[i] = Fx;
	Fxi = Fx;
	Fx= Evaluar_funcion(Xf);
	Fxf = Fx;
	Xm = Obtener_Xm(Xi,Xf,Fxi,Fxf);
	valores_Xm[i] = Xm;
	cout<<"It\tXi\tF(xi)\t\tF(xf)\t\tXm\tF(xm)\t\tEr"<<endl;
	Fx= Evaluar_funcion(Xm);
	Fxm = Fx;
	cout<<fixed<<setprecision(5)<<i<<"\t"<<Xi<<"\t"<<Fxi<<"\t"<<Fxf<<"\t"<<Xm<<"\t"<<Fxm<<"\t"<<endl;
	Xi = Xm;
	i++;
	
	do
	{
		Fx= Evaluar_funcion(Xi);
		valores_Xi[i] = Fx;
		Fxi = Fx;
	 	Fx= Evaluar_funcion(Xf);
		Fxf = Fx;
		Xm = Obtener_Xm(Xi,Xf,Fxi,Fxf);
		valores_Xm[i] = Xm;
		Error=fabs((valores_Xm[i]-valores_Xm[i-1]));
		Fx= Evaluar_funcion(Xm);
		Fxm = Fx;
		cout<<fixed<<setprecision(5)<<i<<"\t"<<Xi<<"\t"<<Fxi<<"\t"<<Fxf<<"\t"<<Xm<<"\t"<<Fxm<<"\t"<<Error<<endl;
		Xi = Xm;
		i++;	
	}while(Error>tol);
	
	
	
	
}

double Evaluar_funcion(double X)
{
	double evaluacion;
	
	evaluacion = (((pow(X,3))+((2)*(pow(X,2)))+((10)*(X)))-20);
	return evaluacion;
}

double Obtener_Xm(double Xi,double Xf,double Fxi,double Fxf)
{
	double resultado;
	
	resultado =  (Xf-(((Xf-Xi)*(Fxf))/(Fxf-Fxi)));
	return resultado;
}
