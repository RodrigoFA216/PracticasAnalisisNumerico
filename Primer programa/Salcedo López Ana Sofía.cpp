/*Programa que determina el Error Relativo Porcentual de e^x con el número de iteraciones que ingrese el usuario.
Salcedo López Sofía 
Análisis numérico 4CM11*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	int term = 0, i, x, it=1;
	float res_ant,ep,ea=100,res_act;
	float res_act1, factor=1;
	double vv = 0, exponente = 0;
	const double e = 2.7182818;
	
	cout<<"Este programa determina e^x \n"
	<< "usando la serie de Maclaurin \n"<<endl;
	
	cout<<"Ingrese el valor de x: ";
	cin>> exponente;
	
	cout<<"Ingrese el numero de terminos: \t";
	cin>> term;
	
	vv=pow(e,exponente);
	res_ant = 1;
	res_act= 1 + exponente;
	
	ep=((res_ant-vv)/vv)*-100;
	
	cout<<"\n terminos \t p* \t ERP \n"
	<<"\t"<<it<<"\t"<<res_ant<<"\t"<<ep;
	
	it++;
	
	ep=((vv-res_act)/vv)*100;
	
	
	cout<<"\n\t"<<it<<"\t"<<res_act<<"\t"<<ep;
	
	
	for(i=2; i<=term-1;i++){
		
		factor = 1;
		res_ant = res_act;
		res_act1=pow(exponente,i);
		
		for(x=1; x<=i; x++){
			factor = x*factor;
		}
		fflush(stdin);
		res_act= res_ant+res_act1/factor;
		ep=((vv-res_act)/vv)*100;
		
		
		it++;
		cout<<"\n\t"<<it<<"\t"<<res_act<<"\t"<<ep;
		
	}
	
	cout<<"\n";
	system("PAUSE");
	return 0;
}
