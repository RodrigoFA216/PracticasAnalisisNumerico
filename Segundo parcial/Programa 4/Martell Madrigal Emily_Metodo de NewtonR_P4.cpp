#include <iostream>             //   Martell Madrigal Emily
#include <cmath>

using namespace std;

double f(double x)    // --->  f(x)
{
	 return pow(x,3)+pow(2*x,2)+pow(10*x,1)-20;
};
double df(double x)   //  ---> f'(x)
{
	return (double)pow(3*x,2)+pow(4*x,1)+10; 
};


int main()       
{                                  //declaracion de constantes y variables
	double E, ancho,error;
	int puntos, iteraciones=0;
	double  x0, xi;
	bool converge=true;   //bool: declara un tipo especial de variable que solo tiene 2 valores (cierto o falso) 
	cout<<" \t\t\t ° Metodo de Newton Raphson ° "<<endl;
	cout<<"\n\tCon f(x)=x^3+2x^2+10x-20"<<endl;

	
	cout<<"\nIngrese el error: ";
	cin>>E;
	
	cout<<"\nDefine el punto inicial:";
	cin>>x0;
	
	cout<<"\nAproximacion inicial: ";  //  ---> se ve la primera aproximacion
	cout<<"x0 = "<<x0<<"\n\n"<<"f(x0) = "<<f(x0)<<"\n"<<"f'(x0) = "<<df(x0)<<endl;
	iteraciones ++;
	
	do
	{
		if(iteraciones>150)   //si las iteraciones son mayores a 150 el programa no converge y se detiene
		{
			converge=false;
			break;
		}
		else
		  {
		  	xi=x0-f(x0)/df(x0);
		  	error=fabs(xi-x0);
		  	cout<<"\n Iteracion No. "<<iteraciones<<endl;   // se muestran las iteraciones
		  	cout<<"\n\tx"<<iteraciones<<" = "<<xi<<"\t\t"<<"f(x"<<iteraciones<<") = "<<f(xi)<<"\t\t"<<"f'(x"<<iteraciones<<") = "<<df(xi)<<"\t\t"<<"error = "<<error<<endl;
		  	 
			   if (error<=E)  // si el error < ó = E se termina el programa
		  	  {
		  		converge=true;
		  		break;
			  }
			   else    // de no ser asi, sigue iterando
			     {
					x0=xi;
			     	iteraciones ++;
				 }
		  }
	} while(1);
	     if (converge)
		 {
		 	cout<<"\n\n Para un error de "<<E<<" la raiz de f es: "<<xi<<endl;
		 }
		 else 
		  {
		 	cout<<"\n\n Se sobrepaso la maxima cantidad de iteraciones permitidas "<<endl;
		  } 
		return 0;
}
