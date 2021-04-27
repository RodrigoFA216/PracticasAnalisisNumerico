//Garcia Patricio Roberto Manuel

#include <iostream>
#include <iostream>
#include <iomanip> 
#include <stdlib.h>
#include <cmath>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double R1,R2,error,error_2,fx,f2x,x0,x_1,aux=0;
   int x3,x2,x,n,i=1;
   
	cout << "\n\t\tDigita la ecuacion N x^3+ N x^2 + N x + N = 0\n tomando en cuenta el signo\n";
    cout << "\nCoeficiente de x^3 = "; cin >> x3;
    cout << "\nCoeficiente de x^2 = "; cin >> x2;
    cout << "\nCoeficiente de x = "; cin >> x;
    cout << "\nconstante = "; cin >> n;
    
    system("cls");
    
     cout << "\n\tDigite el punto inicial para tabular  " << endl;
    cout << "\nX0 = ";
    cin >> x0;
    cout << "\nX1 = ";
    cin >> x_1;
    
    cout << "x\t\tf(x)\n";
    
    for (int i=x0;i<=x_1;i++)
    {
    	fx=f(i,x3,x2,x,n);
    	cout <<"\n"<<i<<"\t\t"<<fx;
	}
    
    cout << "\n\Digite el punto inicial " << endl;
    cout << "\nXI = ";
    cin >> x0;
    cout << "\nXF = ";
    cin >> x_1;
    
    system("cls");
   
    
	cout << "\n error: "; cin >> error_2;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		fx=f(x0,x3,x2,x,n);
   		f2x=f(x_1,x3,x2,x,n);
   		
		R1=x_1-(((x_1-x0)*f2x)/(f2x-fx));
		R2=f(R1,x3,x2,x,n);
		error=fabs(R1-aux);
		aux=R1;
		cout << i << "\t\t" << R1 << "\t\t" << error << "\n\n";
		
		i++;
		if(R2<0)
		{
			x0=R1;		
		}
		if(R2>0)
		{
			x_1=R1;
		}
		
		fx=f(x0,x3,x2,x,n);
    	f2x=f(x_1,x3,x2,x,n);
	}  
	while (error>error_2);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}

