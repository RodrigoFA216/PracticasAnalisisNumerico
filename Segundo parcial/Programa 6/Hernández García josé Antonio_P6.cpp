#include <iostream>
#include <iomanip> 
#include <math.h>

#define PRECISION 6
#define INTERVALOS 10


void tabula(double a, double b);
double f(double x);

   int main()
{
	cout << setprecision(PRECISION);
	cout << "\n metodo de la falsa posicion\n";
	cout << "\nIngrese el intervalo inicial [a,b]:" << endl;
	
	double a, b, tolerancia;
	
cout << "\na = ";
cin >> a;

cout << "b = ";
cin >> b;

tabula(a, b);
	
	cout << "\ncual es el intervalo" << endl;
	cout << "\na = ";
	cin >> a;
	
	cout << "b = ";
	cin >> b;
	
	double xr; // La soluci�n
	double xa = 0; // Soluci�n anterior
	
	if (f(a) * f(b) > 0) {
		cout << "\nNo se puede aplicar el metodo de la falsa posicion\n";
		cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
	
	} else {
		cout << "Tolerancia = ";
		cin >> tolerancia;
		
		cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
		do {
			xr = b - f(b) * ((b - a) / (f(b) - f(a)));
			
			cout << a << "\t" << b << "\t" << xr << "\t" << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;
			
			// if (fabs(f(xr)) <= tolerancia) {
			if (fabs(xr - xa) / fabs(xr) <= tolerancia) {
				cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << xr << endl;
				break;
			
			} else {
				xa = xr; // Se guarda el valor de la aproximaci�n anterior
				if (f(xr) * f(a) > 0) {
					a = xr;
			
				} else if (f(xr) * f(b) > 0) {
					b = xr;
				}
			}
		
		} while (1);
	}
	
	cin.get();
	cin.get();
	return 0;
}

void tabula(double a, double b)
{
	int puntos = INTERVALOS + 1;
	
	double ancho = (b - a) / INTERVALOS;
	
	cout << "\n\tx\tf(x) " << endl;
	for (int i = 0; i < puntos; i++) {
		cout << "\t" << a << "\t" << f(a) << endl;
		a = a + ancho;
	}
}

double f(double x)
{
	
	return pow(x,3)+2*pow(x,2)+10*x-20;
}
