/*METODO DE POSICION FALSA
RODRIGUEZ ORTIZ NELLY ITZEL
ANALISIS NUMERICO 4CM11
FECHA: 23 DE ABRIL DE 2021
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

double tol, Xi, Xf,q0,q1,p,q,E;
int i,n;

double funcion(double x) {
	return  pow(x, 3) + (2 * pow(x, 2)) + (10 * x) - 20;
}

int main() {
	cout << "\t\t\tMETODO DE POSICION FALSA" << endl;
	cout << "\t\t\t*****RODRIGUEZ ORTIZ NELLY ITZEL*****" << endl;
	cout << "\n\nf(x) = x^3 + 2x^2 + 10x - 20" << endl;
	cout << "\nIngrese X0:" << endl;
	cin >> Xi;
	cout << "\nIngrese X1:" << endl;
	cin >> Xf;
	cout << "\nIngrese la tolerancia del error (epsilon):" << endl;
	cin >> tol;
	cout << "\nIngrese el numero de iteraciones:" << endl;
	cin >> n;

	i = 0;
	q0 = funcion(Xi);
	q1 = funcion(Xf);

	while (i < n) {
		p = Xf - q1*(Xf - Xi) / (q1 - q0);
		E = abs(p - Xf);
		if (E<tol){
			cout << "\n\nIteracion " << i + 1;
			cout << "\n\nXi= " << Xi << " f(" << Xi << ")= " << q0 << "\nXf= " << Xf << " f(" << Xf << ") = " << q1;
			cout << "\nXm= " << p << "\nE=" << E<<" < "<<tol;
			cout << "\n\nLa raiz es " << p << " en la iteracion " << i+1;
			break;
		}else{
			cout << "\n\nIteracion " << i+1;
			cout << "\n\nXi= " << Xi << " f(" << Xi << ")= " << q0 << "\nXf= " << Xf << " f(" << Xf << ") = " << q1;
			cout << "\nXm= " << p<<"\nE="<<E << " > " << tol;
		}
		i = i + 1;
		q = funcion(p);
		if ((q * q1) < 0) {
			Xi = Xf;
			q0 = q1;
		}
		Xf = p;
		q1 = q;
	}
	if (i >= n) {
		cout << "\n\nEl metodo fallo despues de " << n << "iteraciones";
	}
	cout << "\n\n";
	return 0;
}


