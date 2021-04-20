//Garcia Patricio ROberto Manuel

#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <stdlib.h>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double R1,R2,error,fx,f_2x,x0,x_1;
   int x3,x2,x,n,i=1;
   
	cout << "\n\t\t\tDigita la ecuacion N x^3+ N x^2 + N x + N = 0\n Tomar en cuenta el signo\n";
    cout << "\nCoeficiente de x^3 = "; cin >> x3;
    cout << "\Coeficiente de x^2 = "; cin >> x2;
    cout << "\nCoeficiente de x = "; cin >> x;
    cout << "\nConstante = "; cin >> n;
    
    system("cls");
    
    cout << "\n\t\tDigite el punto inicial " << endl;
    cout << "\nX0 = ";
    cin >> x0;
    cout << "\nX1 = ";
    cin >> x_1;
    
    fx=f(x0,x3,x2,x,n);
    f_2x=f(x_1,x3,x2,x,n);
    system("cls");
   
    
	cout << "\n error: "; cin >> error;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		R1=x_1-(((x_1-x0)*f_2x)/(f_2x-fx));
		R2=fabs(R1-x_1);
		cout << i << "\t\t" << R1 << "\t\t" << R2 << "\n\n";
		
		i++;
		x0=x_1;
		x_1=R1;
		
		fx=f(x0,x3,x2,x,n);
    	f_2x=f(x_1,x3,x2,x,n);
	}  
	while (R2>error);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}

