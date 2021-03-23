#include <iostream>      //Martell Madrigal Emily
#include <math.h>

using namespace std; 
int main()
{
	int elem=0,i,x,it=1;
	float vbleX=0, res_ant, erp, vv=1.648721, res_act;
	float res_act1, factor=1;
	
	cout<<"\t\t° Serie de Maclaurin ° \n\n";
	cout<<"El valor verdadero es: 1.648721\n";
	cout<<"\nIngrese el valor de X: ";
	cin>>vbleX;
	cout<<"Ingrese el numero de elementos: ";
	cin>>elem;
	res_ant=1;
	res_act=1.5;
	erp=((vv-res_ant)/vv)*100;
	cout<<"\n\t # Elementos \t\tp* \t\t ERP"
	<<"\n\t\t"<<it<<"\t\t"<<res_ant<<"\t\t"<<erp<<"  %";
	it++;
	erp=((vv-res_act)/vv)*100;
	cout<<"\n\t\t"<<it<<"\t\t"<<res_act<<"\t\t"<<erp<<"  %";
	for(i=2; i<=elem-1; i++)
	{
		factor=1;
		res_ant=res_act;
		res_act1=pow(vbleX,i);
		for(x=1; x<=i; x++)
		{
			factor=x*factor;
		}
		res_act=res_ant+res_act1/factor;
		erp=((vv-res_act)/vv)*100;
		it++;
		cout<<"\n\t\t"<<it<<"\t\t"<<res_act<<"\t\t"<<erp<<"  %";
	}
	cout<<"\n\n";
	system("pause");
	return 0;
}
