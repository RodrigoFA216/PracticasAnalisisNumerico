#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double factorial(int n);
double maclaurin(int , float x);

int main(){
	int n;
	float x;
	cout<<"Ingresa el valor del elemento: "; cin>>n;
	cout<<"Ingresa el valor de x: "; cin>>x;
	printf("El valor de Maclaurin para n = %d, x = %.2f es = %f\n", n,x, maclaurin(n, x));
	system("pause");
}

double maclaurin(int n, float x){
	double m, s=0;
	for(int i=0; i<n; i++){
		m=pow(x,i)/ factorial(i);
		s += m;
		printf("Elemento = %d\t p* = %f\n", i+1, s);
	}
	return s;
}

double factorial(int n){
	double fac=1;
	for(int i=2; i<=n; i++){
		fac *=i;
	}
	return fac;
}
