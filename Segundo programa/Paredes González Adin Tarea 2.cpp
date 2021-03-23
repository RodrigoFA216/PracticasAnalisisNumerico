#include <iostream>
#include <cmath>
using namespace std;

double Xi=0;
	double Xd=0;
	double Error=0;
	double ErrorA=0.001;
	double Cambio=0;
	double Diferencia=0;
	double Num=0;
	double Den=0;
	double V1=0;
	double V2=0;
	double Promedio=0;
	double Repeticiones=0;
int main()
{
	
	cout<<"		**TAREA 2**		"<<endl;
	cout<<"PROGRAMA DE METODO DE BISECCION"<<endl;
;
	cout<<"INGRESA EL VALOR SUPERIOR (Xi):";
	cin>>Xi;
	cout<<"INGRESA EL VALOR INFERIOR (Xd):";
	cin>>Xd;
	
	//Operacion para determinar el numero de repeticiones
	Diferencia=Xd-Xi;
	Num=(log(Diferencia))-(log(ErrorA));
	Den=log(2);
	Repeticiones=Num/Den;
	Repeticiones=ceil(Repeticiones);
	
	V1=Xi;
	V2=Xd;
	
	for(int i=0; i<Repeticiones; i++){
		Num=V1+V2;
		Den=2;
		Promedio=Num/Den;
		
		Error=V1-Promedio;
		Error=fabs(Error);
		
		cout<<V1<<" |    ";
		cout<<V2<<" | ";
		cout<<Promedio<<" | ";
		cout<<Error<<endl;
		
		Cambio=V2;
		V2=V1;
		V1=Promedio;
	}
	

}
