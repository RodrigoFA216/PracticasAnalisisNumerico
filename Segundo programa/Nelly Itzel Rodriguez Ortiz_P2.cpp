/*ANALISIS NUMERICO 4CM11
PROGRAMADORA: RODRIGUEZ ORTIZ NELLY ITZEL
TEMA:	METODO DE BISECCION
PRIMER PARCIAL
FECHA:22/03/2021*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
	return pow(x, 3) + (2 * pow(x, 2)) + (10 * x) - 20;
}

int main() {
	char salir;
	int i;
	double xi = 0, xd = 0, xm = 0, n = 0, E = 0, ri1 = 0, rd1 = 0, xm1 = 0, vc = 0, res2 = 0;
	double e = 0.001;
	do {
		cout << "\t\t\t*****METODO DE BISECCION*****" << endl;
		cout << "\t\t\t*****RODRIGUEZ ORTIZ NELLY ITZEL*****" << endl;
		cout << "\t\t\tf(x) = x^3 + 2x^2 + 10x - 20" << endl;
		cout << "Ingrese Xi: "; cin >> xi;
		cout << "\nIngrese Xd: "; cin >> xd;
		n = (log(xd - xi) - log(e)) / (log(2));
		n = ceil(n);
		cout << "\nNumero de iteraciones a realizar: " << n << endl;
		cout << "\n#Iteraciones" << setw(10) << "\t Xi" << setw(10) << "\t Xd" << setw(10) << "\t Xm" << setw(10) << "\t f(Xm)" << setw(20) << "\t E" << endl;
		ri1 = xi;
		rd1 = xd;
		i = 1;
		while (i <= n) {
			xm = (xi + xd) / 2;
			xm1 = xm;
			E = ri1 - xm1;
			E = fabs(E);
			cout << "\t" << i << "\t" << setw(10) << xi << "\t" << setw(10) << xd << "\t" << setw(10) << xm << "\t" << setw(10) << f(xm) << setw(20) << E << endl;
			if (f(xi) * f(xm) < 0) {
				xi = xi;
				xd = xm;
			}
			else {
				xi = xm;
				xd = xd;
			}
			vc = res2;
			res2 = ri1;
			ri1 = xm1;
			i++;
		}
		cout << "\nDesea salir s/n: ";
		cin >> salir;
	} while (salir != 's' && salir != 'S');
	return 0;
}