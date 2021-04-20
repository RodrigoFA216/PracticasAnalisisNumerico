/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

double funcion(double x);   
double errorAbsoluto(double b, double a) ;

double x0, x1, xi, error;
int iteracion=0; 
int main()
{
    double epsilon, x0, x1, error;       
    cout << "\n \t\tMETODO SECANTE\n";
    cout << "\nIngrese x0= ";
    cin >> x0;
    cout << "\nIngrese x1=  ";
    cin >> x1;
    cout << "Ingrese valor epsilon= ";
    cin >> epsilon;
	cout << "\nIt \t x \t\t error" << endl;

 do {

 xi = x1 - ((funcion(x1)*(x0-x1)) / (funcion(x0)-funcion(x1)));
error = fabs(x1 - x0);
 x0 = x1;
 x1 = xi;
 	iteracion++;
	cout << " " << iteracion<< "\t" <<x1<< "\t\t" << error<<endl;
 } 
 while (error > epsilon);
 return x1;
}

double funcion(double x) 
{
 return pow(x,3)+2*pow(x,2)+10*x-20;
}

double errorAbsoluto(double b, double a) 
{
 return abs((a - b) / a) * 100;
}


