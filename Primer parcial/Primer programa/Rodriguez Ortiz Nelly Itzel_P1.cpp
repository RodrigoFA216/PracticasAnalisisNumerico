/*ANALISIS NUMERICO 4CM11
PROGRAMADORA:   RODRIGUEZ ORTIZ NELLY ITZEL
TEMA:   ERRORES - SERIE DE MACLAURIN
PRIMER PARCIAL
FECHA 22/03/2021
*/

#include <iostream>
#include <cmath>

using namespace std;

double x,E,EA,ER,ERP,p,px,it,den,macla,num;
int n;

long long factorial(long long n);
int main()
{
	cout << "\t\t\t*****SERIE DE MACLAURIN*****\n" << endl;
	cout << "\t\t\t*****RODRIGUEZ ORTIZ NELLY ITZEL*****\n" << endl;
	cout << "Ingrese el valor de x: " ;
	cin >> x;
	cout << "\nIngrese el # de elementos: ";
	cin >> n;

	p = exp(x);
	cout << "\nExponencial de " << x << ": " << p<<endl;
	cout << "\n\n# elementos	   p*       	  ERP" << endl;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			px = 1;
			cout << "   " << i << "		" << px << "		" <<"---" << endl;
		}
		else if (i == 2) {
			px = 1 + x;
			E = px - p;
			EA = abs(E);
			ER = EA / p;
			ERP = ER * 100;
			cout << "   " << i << "		" << px << "		" << ERP << endl;
		}else{
			it = 1 + x;
			for (int j = 2; j <= n; j++) {
				num = pow(x, j);
				j = j + 1;
				den = factorial(j);
				macla += num / den;
			}
			px = it+macla;
			E = px - p;
			EA = abs(E);
			ER = EA / p;
			ERP = ER * 100;
			cout <<"   "<< i << "		" << px << "		" << ERP << endl;
		}
		
	}
	cout << endl;
	return 0;
}

long long factorial(long long n){
	long long fact = 1;
	for (long long i =1;i<=n;i++){
		fact *= i;
	}
	return fact;
}


