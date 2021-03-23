/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include <iostream>
#include <cmath>

using namespace std;

float p (float x);
float factorial(int n);
float Maclaurin(int elementos, float x);
float Eabsoluto (int elementos, float x) ;
float Erelativop (int elementos, float x);

int main() 
{
int elementos;
float ex;
	cout<< "\t\tSERIE MACLAURIN"<<endl;
	cout <<" Introduzca el valor para X: "<<endl;
	cin >> ex;
	cout <<" Introduzca el numero de elemteos: "<<endl;
	cin >> elementos;

	cout << " \nExponencial de x=  " << exp(ex);
	cout << " \n e^x=P=  " << exp(ex) << endl<<endl;
	//p=exp(ex);
	cout << "\n #Elementos	P*		EA			ERP" << endl;
	for (int i = 1;	i <= elementos; i++) {
		cout << "   " << i
			 << "\t\t" << Maclaurin(i, ex) 
			 << "\t\t" << Eabsoluto(i, ex)
			 //<<"\t\t "<<exp_maclaurin (i, ex) <<"-"<<p(ex)<<"="<<error_absoluto(i, ex)
			 <<"\t\t"<<Erelativop(i, ex)<<"%"<<endl;
	}
	cout << endl;
	return 0;
}
float p (float x)
{
	float aprox;
	aprox=exp(x);
}
float factorial(int n)
 {
	float fact = 1;
	for (int i = 1; i <= n; i++) 
	{
		fact=fact*i;
	}
  return fact;
}

float Maclaurin(int elementos, float x) 
{
	float sumatoria = 0;
	for (int n = 0; n <elementos; n++) 
	{
		sumatoria += pow(x, n) / factorial(n);
	}
	return sumatoria;
}

float Eabsoluto (int elementos, float x) 
 { 
	float EA=0.0;
	for (int n = 0; n <=elementos-1; n++) 
	{
		EA = abs(Maclaurin(elementos, x)-p(x));
 	}
 	return EA;
 }
float Erelativop (int elementos, float x)
{
	float ER=0.0;
	for (int n = 0; n <=elementos-1; n++) 	
	{
		ER=((Eabsoluto(elementos, x)/p(x))*100);
	}
}
