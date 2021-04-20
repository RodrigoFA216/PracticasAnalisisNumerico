//Garcia Patricio Roberto Manuel

#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <stdlib.h>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double z,R1,R2,error,fx,f_x1;
   int x3,x2,x,n,x_2,x_1,n_1,i=1;
   
	cout << "\n\t\tingresa la ecuacion N x^3+ N x^2 + N x + N = 0\n \ningresa el signo junto con el numero\n";
    cout << "\nCoeficiente de x^3 = "; cin >> x3;
    cout << "\nCoeficiente de x^2 = "; cin >> x2;
    cout << "\nCoeficiente de x = "; cin >> x;
    cout << "\nConstante = "; cin >> n;
    
    system("cls");
    
    cout << "\nIngrese el punto inicial " << endl;
    cout << "\na = ";
    cin >> z;
    
    fx=f(z,x3,x2,x,n);
    system("cls");
    
    cout << "\ningresa la derivada N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nCoeficiente de x^2 = "; cin >> x_2;
    cout << "\nCoeficiente de x = "; cin >> x_1;
    cout << "\nConstante = "; cin >> n_1;

  	f_x1=f(z,0,x_2,x_1,n_1);
    
	cout << "\n error: "; cin >> error;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		R1=z-(fx/f_x1);
		R2=fabs(R1-z);
		cout << i << "\t\t" << R1 << "\t\t" << R2 << "\n\n";
		
		i++;
		z=R1;
		
		fx=f(z,x3,x2,x,n);
		f_x1=f(z,0,x_2,x_1,n_1);
	}  
	while (R2>error);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}


