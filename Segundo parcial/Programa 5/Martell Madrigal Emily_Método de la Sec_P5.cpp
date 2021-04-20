#include <iostream>        // Martell Madrigal Emily
#include <iomanip>
#include <cmath> 

using namespace std; 

double f(double x)
{
	return pow(x,3)+pow(2*x,2)+pow(10*x,1)-20;
}

int main()
{
	char salir;
	int n, nmax;
	double x0,x1,x2,error, E;
	do 
	  {
	  	cout<<"\n\t\t\t\t ° Metodo de la secante °"<<endl;
	  	cout<<"\n Ingrese x0: ";
	  	cin>>x0;
	  	cout<<"\n Ingrese x1: ";
	  	cin>>x1;
	  	cout<<"\n Ingrese el error: ";
	  	cin>>error;
	  	cout<<"\n Numero max. de iteraciones: ";
	  	cin>>nmax;
	  	n=1;
	  	cout<<"\n Iteraciones"<<endl;
	  	 while(abs(x1-x0)>error*(abs(x1)+1)&&n<nmax)
		    {
		    	x2=x1-(f(x1)*(x0-x1))/(f(x0)-f(x1));
		    	x0=x1;
		    	x1=x2;
		    	cout<<"\t"<<n<<"\t"<<setprecision(10)<<x2<<endl;
		    	n++;
			} 
		 cout<<"\n\t Quiere salir? si(s) / no(n) "; 
		 cin>>salir;	
	  } while(salir!='s'&& salir!='S');
	    return 0;
}


