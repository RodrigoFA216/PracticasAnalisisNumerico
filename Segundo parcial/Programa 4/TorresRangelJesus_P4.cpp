#include <iostream>
#include <iomanip> 
#include <cmath>

#define PRECISION 10
#define MAX_ITERACIONES 100
#define INTERVALOS 6

using namespace std;

void tabula(double a, double b, int intervalos);   
double f(double x);  
double f_derivada(double x); 

int main()
{
    double tolerancia; 
    double x0, x1, error;   
    int iteracion; 
    bool converge = true;
    
    cout << "\t\t\t\t\tJesus Torres Rangel\n ";
 	cout << "\t\t\t\t\tANALISIS NUMERICO\n ";
 	cout << "\t\t\t\t\tMETODO DE LA SECANTE\n\n ";
 	cout << "\tEcuacion: pow(x,2) - (2*pow(x,2)) + (10*x) - 20 \t Derivada:(3*pow(x,2)) + (4*x) + 10 ";
	cout << setprecision(PRECISION); 
    cout << "\n\nEscoja el punto inicial adecuado:   x0 = ";
    cin >> x0;
    cout << "Tolerancia = ";
    cin >> tolerancia;
    cout << "\nAproximacion inicial:\n";
    cout << "x0 = " << x0 << "\n"
        << "f(x0) = " << f(x0) << "\n"
        << "f'(x0) = " << f_derivada(x0) << endl;
    
    iteracion = 1;
    do {
    
        if (iteracion > MAX_ITERACIONES) {
            converge = false;  
            break;
        
        } else {
            x1 = x0 - f(x0) / f_derivada(x0);
            error = fabs(x1 - x0);    
            cout << "\nIteracion #" << iteracion << endl;
            cout << "x" << iteracion << " = " << x1 << "\n"
              << "f(x" << iteracion << ") = " << f(x1) << "\n"
              << "f'(x" << iteracion << ") = " << f_derivada(x1) << "\n"
              << "error = " << error << endl;
            if (error <= tolerancia)
			 {
                converge = true;
                break;
            } 
			else 
			{
                x0 = x1;
                iteracion++;
            }
        }
    
    } while (1);
    if (converge) {
        cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << x1 << endl;
    
    } else {
        cout << "\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
    }
    
    cin.get();
    cin.get();
    return 0;
}

void tabula(double a, double b, int intervalos)
{
    int puntos = intervalos + 1;
    
    double ancho = (b - a) / intervalos;
    
    cout << "\n\tx\t\tf(x) " << endl;
    for (int i = 0; i < puntos; i++) {
        cout << "\t" << a << "\t\t" << f(a) << endl;
        a = a + ancho;
    }
}

double f(double x)
{
    return pow(x,2) - (2*pow(x,2)) + (10*x) - 20;
  
}

double f_derivada(double x)
{
    return (3*pow(x,2)) + (4*x) + 10;
}
