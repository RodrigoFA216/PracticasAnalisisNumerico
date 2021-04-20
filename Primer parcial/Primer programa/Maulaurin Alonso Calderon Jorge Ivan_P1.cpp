#include <iostream>
#include <cmath>

using namespace std;

long long factorial(long long n);
double exp_maclaurin(int terminos, double x);

int main() {

	int T;
	float x;
	cout <<"Valor de x: ";cin>>x;
	cout <<"Numero de terminos: ";cin>>T;
	cout <<"\n";
	
	for (int i = 1;	i <= T; i++) {
		cout << "e^x=p con " << i << " terminos: " << exp_maclaurin(i, x) << endl;
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


