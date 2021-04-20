#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double R1,R2,error,fx,ffx,x0,x_1;
   int x3,x2,x,n,i=1;
   
	cout << "\ningresa la ecuacion N x^3+ N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nnumero que acompaña a x^3 = "; cin >> x3;
    cout << "\nnumero que acompaña a x^2 = "; cin >> x2;
    cout << "\nnumero que acompaña a x = "; cin >> x;
    cout << "\nnumero que acompaña = "; cin >> n;
    
    system("cls");
    
    cout << "\nIngrese el punto inicial " << endl;
    cout << "\nX0 = ";
    cin >> x0;
    cout << "\nX1 = ";
    cin >> x_1;
    
    fx=f(x0,x3,x2,x,n);
    ffx=f(x_1,x3,x2,x,n);
    system("cls");
   
    
	cout << "\n error: "; cin >> error;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		R1=x_1-(((x_1-x0)*ffx)/(ffx-fx));
		R2=fabs(R1-x_1);
		cout << i << "\t\t" << R1 << "\t\t" << R2 << "\n\n";
		
		i++;
		x0=x_1;
		x_1=R1;
		
		fx=f(x0,x3,x2,x,n);
    	ffx=f(x_1,x3,x2,x,n);
	}  
	while (R2>error);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}

