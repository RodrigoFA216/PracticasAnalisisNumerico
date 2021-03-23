#include <iostream>
#include <cmath>
using namespace std;
	double X=0;

	double PrimerasDosIteraciones=0;
	double Resultado=0;
	double BucleDeMaclaurin=0;
	double Numerador=0;
	double Denominador=0;
	int NumeroDeIteracionesN=0;

int main(){
	
	cout<<"	**TAREA 1**	"<<endl;
	cout<<"PROGRAMA SERIE DE MACLAURIN"<<endl;
	cout<<"e^x = 1+x+((x^2)/2!)+((x^3)/3!)+((x^4)/4!)+...+((x^n)/n!)"<<endl;
	cout<<endl;
	cout<<"ASIGNA EL VALOR DE X: ";
	cin>>X;
	cout<<"INDICA EL NUMERO DE VECES QUE QUIERAS QUE SE REPITA: ";
	cin>>NumeroDeIteracionesN;
	
	switch(NumeroDeIteracionesN){
		case 0:
			cout<<"EL RESULTADO ES: 0"<<endl;
		system("pause");
		break;

		case 1:
			cout<<"EL RESULTADO ES: 1"<<endl;
		system("pause");
		break;

		case 2:
			PrimerasDosIteraciones=1+X;
			cout<<"EL RESULTADO ES: "<<PrimerasDosIteraciones<<endl;
		system("pause");
		break;

		default:
			PrimerasDosIteraciones=1+X;
			for(int i=2; i<=NumeroDeIteracionesN; i++){
				Numerador=pow(X,i);
				Denominador=tgamma(i+1);
				BucleDeMaclaurin += Numerador/Denominador;
				Porcentaje=NumeroDeIteracionesN  - BucleDeMaclaurin ;
				POR2=Porcentaje/BucleDeMaclaurin;
				erp=POR2*100;
				
				cout<<BucleDeMaclaurin<<endl;
			}
			
			Resultado=PrimerasDosIteraciones+BucleDeMaclaurin;
			
			cout<<"RESULTADO DE LA ULTIMA REPETICION: "<<Resultado;
	}
	
}
