#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double VariableX=0, Porcentaje=0, PrimerasDosIteraciones=0, Resultado=0, BucleDeMaclaurin=0, Numerador=0, Denominador=0;
	int NumeroDeIteracionesN=0;
	
	cout<<"Programa de serie de Maclaurin"<<endl;
	cout<<"e^x = 1+x+((x^2)/2!)+((x^3)/3!)+((x^4)/4!)+...+((x^n)/n!)"<<endl;
	cout<<endl;
	cout<<"Indica la variable x que deseas calcular: ";
	cin>>VariableX;
	cout<<"Indica el numero de iteraciones que quieras para aproximarte al numero: ";
	cin>>NumeroDeIteracionesN;
	
	switch(NumeroDeIteracionesN){
		case 0:
			cout<<"el Resultado es: 0"<<endl;
		system("pause");
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////
		case 1:
			cout<<"el Resultado es: 1"<<endl;
		system("pause");
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////
		case 2:
			PrimerasDosIteraciones=1+VariableX;
			cout<<"el Resultado es: "<<PrimerasDosIteraciones<<endl;
		system("pause");
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////
		default:
			PrimerasDosIteraciones=1+VariableX;
			for(int i=2; i<=NumeroDeIteracionesN; i++){
				Numerador=pow(VariableX,i);
				Denominador=tgamma(i+1);
				BucleDeMaclaurin += Numerador/Denominador;
			}
			Resultado=PrimerasDosIteraciones+BucleDeMaclaurin;
			cout<<"el Resultado es: "<<Resultado;
	}
	
}

