/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include <iostream>
#include <iomanip>
#include <cmath> 
#define Eps 4
using namespace std;

void rangoo(double Xi, double Xd);
double f(double x);

int main()
{
    double Xi, Xd, Ep;
	cout << setprecision(Eps);
    cout << "\n\t\tMETODO POSICION FALSA\n";
    cout << "Ingrese el intervalo(rango) [Xi, Xf]" << endl;
    cout << "Xi= ";
    cin >> Xi;
    cout << "Xf= ";
    cin >> Xd;
    rangoo(Xi, Xd);
    
    cout << "\nIntroduzca los valores correctos, es decir cuando exista un cambio de signo en f(x)\n";
    cout << "\nXi = ";
    cin >> Xi;
    cout << "Xf = ";
    cin >> Xd;
    double xr, xa = 0; 
    
    if (f(Xi) * f(Xd) > 0) 
	{
        cout << "\nNo se puede ejecutar Metodo de la falsa posicion\n";
        cout << "f(" << Xi << ") y f(" << Xd << ") tienen el mismo signo\n";
    } 
	else 
	{
        cout << "Introduzca valor de Epsilon= ";
        cin >> Ep;
        cout << "\n Xi \t Xf \t f(Xi) \t \t f(Xf) \t \t Xm \t \t f(Xm)\n";
        do 
		{
            xr = Xd - f(Xd) * ((Xd - Xi) / (f(Xd) - f(Xi)));
            cout << Xi << "\t" << Xd << "\t" << f(Xi) << "\t \t" << f(Xd) << "\t \t "<< xr << "\t \t" << f(xr) <<"\n";
            if (fabs(xr - xa) / fabs(xr) <= Ep) 
			{
                cout << "\n\nCon epsilon de " << Ep << " la raiz de f es: " << xr << endl;
                break;    
            } 
			else 
			{
                xa = xr; 
                if (f(xr) * f(Xi) > 0) 
				{
                    Xi = xr;
                } 
				else if (f(xr) * f(Xd) > 0) 
				{
                    Xd = xr;
                }
            }
        } while (1);
    }
    
    cin.get();
    cin.get();
    return 0;
}
#define INTERVALOS 10
void rangoo(double Xi, double Xd)
	 {
	 int puntos = INTERVALOS + 1;
	 double ancho = (Xd - Xi) / INTERVALOS;
	 cout << "\n\t x \t f(x)" << endl;
	 for (int i = 0; i < puntos; i++) 
	 {
	 cout << "\t" << Xi << "\t" << f(Xi) << endl;
	 Xi = Xi + ancho;
   	 }
	 }
double f(double x)
{
    return pow(x,3)+2*pow(x,2)+10*x-20;
}
