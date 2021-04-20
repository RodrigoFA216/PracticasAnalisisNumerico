//Metodo de la Secante
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	float i,error, xi, x1, x0;
	int  a, b, c, d, j=1;
	cout<<"\nTu funcion debe de ser una te tercer grado\nax^3 + bx^2 +cx +d"; 
	cout<<"\nIngresa el valor de a : "; cin>>a;
	cout<<"\nIngresa el valor de b : "; cin>>b;
	cout<<"\nIngresa el valor de c : "; cin>>c;
	cout<<"\nIngresa el valor de d : "; cin>>d;
	cout<<"\nIngresa el valor de tu x0: "; cin>>x0;
	cout<<"\nIngresa el valor de tu x1: "; cin>>x1;
	cout<<"\nIngresa el valor de la tolerancia: "; cin>>i;
	cout<<"\nNo.It \txi \t Error\n";
	
	do{
		xi= x1 - (( (x1-x0)*( a*pow(x1,3) + b*pow(x1,2) + c*x1 + d ) ) / ( (a*pow(x1,3) + b*pow(x1,2) + c*x1 + d) - (a*pow(x0,3) + b*pow(x0,2) + c*x0 + d) ));
		error= xi-x1;
		if(error<0){
			error=error*-1;
		}
		cout<<j<<"\t"<<xi<<"\t"<<error<<"\n";
		j=j+1;
		x0=x1;
			x1=xi;
		if (error < i) { // Condición de terminación 
               break;
     	}
		
	}while(1);
	
	return 0;
}
