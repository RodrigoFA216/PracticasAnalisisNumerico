#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double a,R1,R2,error,fx,dfx;
   int x3,x2,x,n,x_2,x_1,n_1,i=1;
   
	cout << "\ningresa la ecuacion N x^3+ N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nnumero que acompaña a x^3 = "; cin >> x3;
    cout << "\nnumero que acompaña a x^2 = "; cin >> x2;
    cout << "\nnumero que acompaña a x = "; cin >> x;
    cout << "\nnumero que acompaña = "; cin >> n;
    
    system("cls");
    
    cout << "\nIngrese el punto inicial " << endl;
    cout << "\na = ";
    cin >> a;
    
    fx=f(a,x3,x2,x,n);
    system("cls");
    
    cout << "\ningresa la derivada N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nnumero que acompaña a x^2 = "; cin >> x_2;
    cout << "\nnumero que acompaña a x = "; cin >> x_1;
    cout << "\nnumero que acompaña = "; cin >> n_1;

  	dfx=f(a,0,x_2,x_1,n_1);
    
	cout << "\n error: "; cin >> error;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		R1=a-(fx/dfx);
		R2=fabs(R1-a);
		cout << i << "\t\t" << R1 << "\t\t" << R2 << "\n\n";
		
		i++;
		a=R1;
		
		fx=f(a,x3,x2,x,n);
		dfx=f(a,0,x_2,x_1,n_1);
	}  
	while (R2>error);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}


