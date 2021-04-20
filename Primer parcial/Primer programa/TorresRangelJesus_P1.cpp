#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){
	
	int iteraciones;
	double x,  rcp, itera;
	double res, macla, num, deno;
	
	iteraciones=0;
	res=0; 
	macla=0; 
	num=0; 
	deno=0;
	x=0;
	rcp=0; 
	itera=0;

	cout<<"\t\t\t\tTorres Rangel Jesus"<<endl;
	cout<<"\t\t\t\t Analisis Numerico"<<endl;
	
	cout<<"\t\t\t\tSerie de Maclaurin"<<endl;
	cout<<" \n Ingrese la variable a calcular: ";
	cin>>x;
	cout<<" Ingrese el numero de iteraciones: ";
	cin>>iteraciones;
	
	switch(iteraciones){
		case 0:
			{
				cout<<"\nResultado : 0"<<endl;
		        getch();
			}
    	break;
		case 1:
			{
				
				cout<<"\nResultado : 1";
	        	getch();
			}
		break;
		case 2:
			{
			    itera=1+x;
			    cout<<"\nResultado : "<<itera<<endl;
		        getch();
			}
		break;
		default:
			itera=1+x;
			for(int i=2; i<=iteraciones; i++){
				num=pow(x,i);
				deno=tgamma(i+1);
				macla += num/deno;
	
			}
			res=itera+macla;
			cout<<"\nIteracion\t|  P*\n";
			cout<<iteraciones<<"\t\t|"<<res;
	}
	
}


