//Metodo de Newton-Raphson
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	float i,error, xi, x0, j=1;
	int  a, b, c, d;
	cout<<"\nTu funcion debe de ser una te tercer grado\nax^3 + bx^2 +cx +d"; 
	cout<<"\nIngresa el valor de a : "; cin>>a;
	cout<<"\nIngresa el valor de b : "; cin>>b;
	cout<<"\nIngresa el valor de c : "; cin>>c;
	cout<<"\nIngresa el valor de d : "; cin>>d;
	cout<<"\nIngresa el valor de tu x inicial: "; cin>>x0;
	cout<<"\nIngresa el valor de la tolerancia: "; cin>>i;
	cout<<"\nNo.It \txi \t Error\n";
	
	do{
		xi=x0-( ((a*(pow(x0,3)))+(b*(pow(x0,2))) +(c*(x0)) +d)/ (((a*3)*(pow(x0,2)))+((b*2)*(x0)) +c) );
		error= xi-x0;
		if(error<0){
			error=error*-1;
		}
		cout<<j<<"\t"<<xi<<"\t"<<error<<"\n";
		j=j+1;
		if (error < i) { // Condición de terminación 
               break;
     	}
		else {
			x0=xi;
		}
		
	}while(1);
	
	return 0;
}
