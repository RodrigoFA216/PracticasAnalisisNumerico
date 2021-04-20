#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double VariableInferiorXi=0, VariableSuperiorXd=0, Error=0, ErrorAsignado=0.001, VariableDeCambio=0, DiferenciaDeLosPuntos=0, Numerador=0, Denominador=0;
	double ValorP1=0, ValorP2=0, ResultadoDelPromedio=0, NumeroDeIteracionesN=0;
	int j=0;
	
	cout<<"Programa de Metodo de biseccion"<<endl;
	cout<<"tomando en cuenta que ya tienes la Variable superior (Xi) y la variable inferior (Xd): "<<endl;
	cout<<"Ingresa el valor de Xi: ";
	cin>>VariableInferiorXi;
	cout<<"Ingresa el valor de Xd: ";
	cin>>VariableSuperiorXd;
	
	//Operacion para determinar el numero de repeticiones
	DiferenciaDeLosPuntos=VariableSuperiorXd-VariableInferiorXi;
	Numerador=(log(DiferenciaDeLosPuntos))-(log(ErrorAsignado));
	Denominador=log(2);
	NumeroDeIteracionesN=Numerador/Denominador;
	NumeroDeIteracionesN=ceil(NumeroDeIteracionesN);
	
	ValorP1=VariableInferiorXi;
	ValorP2=VariableSuperiorXd;
	
	cout<<"It\t";
	cout<<"Xi\t";
	cout<<"Xd\t";
	cout<<"Xm\t";
	cout<<"E\t";
	cout<<endl;
	
	for(int i=0; i<NumeroDeIteracionesN; i++){
		
		j++;
		Numerador=ValorP1+ValorP2;
		Denominador=2;
		ResultadoDelPromedio=Numerador/Denominador;
		
		Error=ValorP1-ResultadoDelPromedio;
		Error=fabs(Error);
		
		cout<<j<<"\t";		
		cout<<ValorP1<<"\t";
		cout<<ValorP2<<"\t";
		cout<<ResultadoDelPromedio<<"\t";
		cout<<Error<<"\t"<<endl;
		
		VariableDeCambio=ValorP2;
		ValorP2=ValorP1;
		ValorP1=ResultadoDelPromedio;
	}
	

}
