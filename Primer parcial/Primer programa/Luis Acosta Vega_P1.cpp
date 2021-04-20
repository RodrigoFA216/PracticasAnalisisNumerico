#include <iostream>
#include <cmath>

using namespace std;

long long factorial(long long n);
double exp_maclaurin(int terminos, double x);

int main() {
	double numlaurin, terminos;
	cout <<"Ingrese el numero que desea calcular con la Serie de Maclaurin: ";
	cin >> numlaurin;
	cout << "Ingrese el numero de iteraciones a realizar: ";
	cin >> terminos;

	cout << "Exponencial de pi segun cmath: " << exp(numlaurin) << endl;

	for (int i = 1;	i <= terminos; i++) {
		cout << "Exponencial del numero con " << i
				 << " terminos: " << exp_maclaurin(i, numlaurin) << endl;
	}

	cout << endl;
	return 0;
}

long long factorial(long long n) {
	long long fact = 1;
	for (long long i = 1; i <= n; i++) {
		fact *= i;
	}
  return fact;
}

double exp_maclaurin(int terminos, double x) {
	double sumatoria = 0;
	for (int n = 0; n <= terminos; n++) {
		sumatoria += pow(x, n) / factorial(n);
	}
	return sumatoria;
}
