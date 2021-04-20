/*METODO DE NEWTON - RAPHSON
ALUMNA:RODRIGUEZ ORTIZ NELLY ITZEL
MATERIA: ANALISIS NUMERICO
FECHA: 19 DE ABRIL DE 2021
GRUPO: 4CM11*/

#include <iostream>
#include <cmath>
#include<stdlib.h>
#include<iomanip>

#define PRECISION 10
#define MAX_ITERACIONES 100
#define INTERVALOS 6

double f(double x);	// Retorna el valor de la función evaluada en x
double f_derivada(double x); // Retorna la derivada de la función evaluada en x


using namespace std;

double x, xb, y, dy, e,tol;	/*X=valor actual de x, XB=valor anterior de x, Y=valor de la funcion de x, DY= derivada de y, I=contador*/
int n,j,i;
int g[20], M[20], P[20];
bool converge = true;

int main() {
	cout << "\t\t\t* * * * *METODO DE NEWTON-RAPHSON* * * * *"<<endl;
	cout << "\t\t\tRodriguez Ortiz Nelly Itzel" << endl;
	cout << "\nIngrese el grado de la funcion polinomial (ax^3+bx^2+cx+d): ";
	cin >> n;
	for (i = 0; i <=n; i++){
		for(j=n;j>=0;j--){
			cout << "Ingrese el coeficiente del termino x^" << j << "(con signo): ";
			cin >> g[j];
		}
		break;
	}
	cout << "La funcion f(x) es:\n";
	for (i = 0; i <= n; i++) {
		for (j = n; j >= 0; j--) {
			if (j == 0) {
				cout << g[j] << "x^" << j;
			}else{
				cout << "+"<<g[j] << "x^" << j;
			}
		}
		break;
	}
	cout << "\n\nIngrese el grado de la derivada de la funcion polinomial: ";
	cin >> n;
	for (i = 0; i <= n; i++) {
		for (j = n; j >= 0; j--) {
			cout << "Ingrese el coeficiente del termino x^" << j << "(con signo): ";
			cin >> g[j];
		}
		break;
	}
	cout << "La funcion f'(x) es:\n";
	for (i = 0; i <= n; i++) {
		for (j = n; j >= 0; j--) {
			if (j == 0) {
				cout << g[j] << "x^" << j;
			}
			else {
				cout << "+" << g[j] << "x^" << j;
			}
		}
		break;
	}

	cout << "\nIngrese el valor de tolerancia de error: ";
	cin >> tol;
	cout << "\nIngrese el valor de X0: ";
	cin >> x;
	xb = x;
	i = 0;
	
	i = 1;
	do {

		if (i > MAX_ITERACIONES) {
			converge = false;	// Se sobrepasó la máxima cantidad de iteraciones permitidas
			break;

		}
		else {
			x = x - f(xb) / f_derivada(xb); // Cálculo de la siguiente aproximación
			e = fabs(x - xb);	// El error es la diferencia entre dos aproximaciones sucesivas

			// Se imprimen los valores de la siguiente aproximación x1, f(x1), f_derivada(x1), error
			cout << "\nIteracion #" << i << endl;
			cout << "x" << i<< " = " << x << "\n"
				<< "f(x" << i << ") = " << f(x) << "\n"
				<< "f'(x" << i << ") = " << f_derivada(x) << "\n"
				<< "error = " << e << endl;

			
			if (e <= tol) { // Condición de terminación
				converge = true;
				break;
				// Si no se cumple el criterio de terminación, se pasa a la siguiente iteración
			}
			else {
				xb = x;
				i++;
			}
		}

	} while (1);
	// Respuesta final
	if (converge) {
		cout << "\n\nPara una tolerancia de " << tol << " la raiz de f es: " << x << endl;

	}
	else {
		cout << "\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
	}

	cin.get();
	cin.get();
	return 0;
}

double f(double x)
{
	return pow(x, 3) + (2 * pow(x, 2)) + (10 * x) - 20;
}

double f_derivada(double x)
{
	return (3*pow(x, 2)) + (4 * x) + 10;
}
