/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include <iostream>
#include <iomanip> 
#include <cmath>

#define PRECISION 10
#define MAX_ITERACIONES 100

using namespace std;
double f(double x);   
double f_derivada(double x); 

int main()
{
    double epsilon, x0, x1, error;   
    int iteracion; 
    bool converge = true;
    cout << setprecision(PRECISION);  
    cout << "\n \t\tMETODO NEWTON-RAPHSON\n";
    cout << "\nIngrese punto inicial \n x0= ";
    cin >> x0;
    cout << "Ingrese valor epsilon= ";
    cin >> epsilon;
    
    cout << "x0 = " << x0 << "\n"
        << "f(x0) = " << f(x0) << "\n"
        << "f'(x0) = " << f_derivada(x0) << endl;
    cout << "\nIt \t x \t\t error" << endl;
    iteracion = 1;
    do 
	{
		
        if (iteracion > MAX_ITERACIONES) 
		{
            converge = false;   
            break;
        } else 
		{
            x1 = x0 - f(x0) / f_derivada(x0); 
            error = fabs(x1 - x0);     
			cout << " " << iteracion<< "\t" <<x1<< "\t" << error<<endl;

        if (error <= epsilon) 
			{ 
                converge = true;
                break;                
            } else {
                x0 = x1;
                iteracion++;
            }
        }
    } 
	while (1);
    
    if (converge)
	 {
        cout << "\n\nCon Epsilon " << epsilon << " la raiz de f es: " << x1 << endl;
    
    } else 
	{
        cout << "\n " << endl;
    }
    
    cin.get();
    cin.get();
    return 0;
}

double f(double x)
{
    return pow(x,3)+2*pow(x,2)+10*x-20;

}

double f_derivada(double x)
{
    return 3*pow(x,2)+4*x+10;
}
