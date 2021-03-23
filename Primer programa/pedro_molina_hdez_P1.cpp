


/*ANALISIS NUMERICO */
/* MOLINA HERNANDEZ PEDRO*/


#include<iostream>
#include<math.h>

using namespace std;

int main ()
{
	int tem=0,i,x,iter=1;
	float res_ant,et,porc=100,v_e=1.648721,res_act;
	float res_act1,factor=1;
	cout<<"Molina Hernandez Pedro"<<endl;
	cout<<"\n\t****Error SERIE DE MACLAURIN*******"<<endl;
	cout<<"Ingrese el numero de iteraciones....";
	cin>>tem;
	res_ant=1;
	res_act=1.5;
	et=((v_e-res_ant)/v_e)*100;
	cout<<"\niteracion   \tp*           \t\t%\n"
	      <<"\t"<<iter<<"\t"<<res_ant<<"\t\t\t"<<porc;
	      i++;
	      et=((v_e-res_act)/v_e)*100;
	      porc=((res_act-res_ant)/res_act)*100;
	      cout<<"   \n\t"<<iter<<"\t"<<res_act<<"\t\t\t"<<porc;
	      for(i=2;i<=tem-1;i++)
	      {
	      	 /*calculamos P* */
			  factor=1;
	      	res_ant=res_act;
	      	res_act1=pow(0.5,i);
	      	for(x=1;x<=i;x++)
	      	{
	      		factor=x*factor;
			  }
			  /*Calculamos el % */
			res_act=res_ant+res_act1/factor;
			et=((v_e-res_act)/v_e)*100;
			porc=((res_act-res_ant)/res_act)*100;
			iter=iter+1;
			cout<<"   \n\t"<<iter<<"\t"<<res_act<<"\t\t\t"<<porc;
			
		  }
		  
		  cout<<"\n";
		  system("PAUSE");
		  return 0;
}
