#include <conio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	float xi,gxi,error,x0, z,y=0;;
	int a,b,c,opc, i,iter;
	do {	
		cout<<"\nTu funcion es f(x)= 2x^2 -x -5"; 
		cout<<"\nIngresa el valor de tu x inicial: "; cin>>x0; 
		cout<<"\nIngresa el valor del numero maximo de iteraciones: "; cin>>iter;
		cout<<"\nIngresa el valor del valor tolerado: "; cin>>error;
		cout<<"\nTus posibles despejes son:";
		cout<<"\n1.  x=(2x^2-5)";
		cout<<"\n2.  x=raiz((x+5)/2)";
		cout<<"\n3.  x=5/(2x-1)";
		cout<<"\n4.  Salir";	
		cout<<"\nElige tu despeje:"; cin>>opc;
		switch(opc){
			case 1:				
				cout<<"It \txi \tg(xi) \t error";
				for(i=0; i<=iter; i++){
					xi=x0;
					gxi=2*xi*xi-5;
					z=x0;
					error=y-z;
					cout<<"\n"<<i<<"\t"<<xi<<"\t"<<gxi<<"\t"<<error;
					y=xi;
					x0=gxi;
					i+1;	
				}
			break;
			case 2:
				cout<<"It \txi \t\tg(xi) \t\t error";
				for(i=0; i<=iter; i++){
					xi=x0;
					gxi=sqrt((xi+5)/2);
					z=x0;
					error=y-z;
					printf("\n%d \t%f \t%f \t%f", i, xi, gxi, error);
					y=xi;
					x0=gxi;				
					i+1;			
				}
			break;
			case 3:				
				cout<<"It \txi \t\tg(xi) \t\t error";
				for(i=0; i<=iter; i++){
					xi=x0;
					gxi=5/(2*xi-1);
					z=x0;
					error=y-z;
					printf("\n%d \t%f \t%f \t%f", i, xi, gxi, error);
					y=xi;
					x0=gxi;				
					i+1;			
				}
			break;
			default:
			break;			
		}
	
	}while(opc!=4);
	return 0;
}
