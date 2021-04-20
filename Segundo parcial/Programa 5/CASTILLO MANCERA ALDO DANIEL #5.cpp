//Castillo Mancera Aldo Daniel


#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>


using namespace std;

double f(double,int,int,int,int);
int main()
{
   double R1,R2,mstk,fx,dfx,x0,x_1;
   int x3,x2,x,n,i=1;
   
	cout << "\ningresa la ecuacion __x^3+ __x^2 + __x + __ = 0\n ingresa el signo junto con el numero\n";
    cout << "\nCoeficiente de x^3 = "; cin >> x3;
    cout << "\nCoeficiente de x^2 = "; cin >> x2;
    cout << "\nCoeficiente de x = "; cin >> x;
    cout << "\nUltimo digito sin exponente = "; cin >> n;
    
    system("cls");
    
    cout << "\nIngrese el punto inicial. " << endl;
    cout << "\nX0 = ";
    cin >> x0;
    cout << "\nX1 = ";
    cin >> x_1;
    
    fx=f(x0,x3,x2,x,n);
    dfx=f(x_1,x3,x2,x,n);
   
	cout << "\n ERROR: "; cin >> mstk;
	
	cout << "iteracion\tXn\t\t error \n\n";
	do 
	{
		R1=x_1-(((x_1-x0)*dfx)/(dfx-fx));
		R2=fabs(R1-x_1); //Valor absoluto
		cout << i << "\t\t" << R1 << "\t\t" << R2 << "\n\n";
		
		i++;
		x0=x_1;
		x_1=R1;
		
		fx=f(x0,x3,x2,x,n);
    	dfx=f(x_1,x3,x2,x,n);
	}  
	while (R2>mstk);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}

