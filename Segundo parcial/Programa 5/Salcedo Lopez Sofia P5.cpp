/*Programa 5. Método de la secante
Salcedo López Sofía
Análisis numérico 4CM11 
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double x){
	return pow(x,3)+2*pow(x,2)+10*x-20;
}
int main(){
	char salir;
	int n, nmax;
	double x0,x1,x2,tol;
	
	do{
		cout<<"Programa que muestra el uso del Método de la secante con la funcion: "<<endl;
		cout<<"f(x)= x^3+2x^2+10x-20"<<endl;
		cout<<"\n\tIngresar x0: ";
		cin>>x0;
		cout<<"\tIngresar x1: ";
		cin>>x1;
		cout<<"\tIngresar tolerancia: ";
		cin>>tol;
		cout<<"\tNro. max de iteraciones: ";
		cin>>nmax;
		n=1;
		
		cout<<"\n\tIteracion\n";
		
		while(abs(x1-x0)>tol*(abs(x1)+1)&& n<nmax){
			x2 = x1-(f(x1)*(x0-x1))/(f(x0)-f(x1));
			x0=x1;
			x1=x2;
			cout<<"\t\t"<<n<<"\tx "<<n+1<<" = "<<""<<x2<<endl;
			n++;
		}
		
		cout<<"\n\tDesea salir?  s/n";
	cin>>salir;
	}while(salir!='s'&& salir !='S');
	
	return 0;
}
