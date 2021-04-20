/*ANALISIS NÚMERICO
TEMA: METODO DEL PUNTO FIJO
PROGRAMADORA: NELLY ITZEL RODRIGUEZ ORTIZ
FECHA 29 DE MARZO DE 2021*/

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

double p0, E, N,p,e;
int i;


int main() {
	cout << "\t\t\t\tMETODO DEL PUNTO FIJO";
	cout << "\n\t\tNELLY ITZEL RODRIGUEZ ORTIZ" << endl;
	cout << "\n\t\tf(x)=2x^2 - x - 5";
	cout << "\t\tg(x)=[(x+5)/2]^1/2";
	cout << "\n\nIngrese punto inicial: ";
	cin >> p0;
	cout << "\nIngrese error: ";
	cin >> E;
	cout << "\nIngrese # iteraciones: ";
	cin >> N;
	cout << "\n";

	i = 1;
	cout << "\n# Iteraciones" << setw(10) << "\t Xi" << setw(10) << "\t g(Xi)" << setw(20) << "\t E" << endl;
	while (i <= N) {
		p = sqrtf((p0 + 5) / 2);
		e = abs(p - p0);
		if (e < E) {
			cout << "\nLA APROXIMACION DE LA RAIZ ES " << p << " EN LA ITERACION " << i;
			break;
		}
		cout << "\t" << i << "\t" << setw(10) << p0 << "\t" << setw(10) << p << setw(20) << e << endl;
		i++;
		p0 = p;
	}
	cout << "\n";
	system("pause");
}
	