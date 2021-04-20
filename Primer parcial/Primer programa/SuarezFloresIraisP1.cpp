#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<iostream>

using namespace std;

main(){
	
	int iteraciones, fact=0;
	double x=0, itera=0, e=2.71828182846, ex, ee;
	double res=0, suscn=0, pot=0, ea, er, erp;
	

	printf("\t\t\t\tSuarez Flores Irais\n");
	printf("\t\t\t\tSerie de Maclaurin");
	printf(" \n Ingrese la variable a calcular: ");
	scanf("%lf",&x);
	printf(" Ingrese el numero de iteraciones: ");
	scanf("%i",&iteraciones);
	ex=	pow(e,x);
	printf("\n\n  |# Iteraciones|          | p* |          |ERP (%)| \n\n");
	if(iteraciones>2){
    itera=1;
    ee=itera-ex;
    ea=fabs(ee);
    er=ea/ex;
	erp=er*100;	
	
	printf("    1                       1                %lf  \n",erp);
	itera=1+x;
	ee=itera-ex;
    ea=fabs(ee);
	er=ea/ex;
	erp=er*100;
	printf("    2                       %lf         %lf  \n",itera,erp);
	}
	
	switch(iteraciones){
		case 0:
			{
				printf("\n  0                 0            -");            
		        getch();
			}
    	break;
		case 1:
			{
			
			    itera=1;
			    ee=itera-ex;
			    ea=fabs(ee);
			    er=ea/ex;
			    erp=er*100;	
			printf("    1                       1                  %lf \n",erp);
	        	getch();
			}
		break;
		case 2:
			{
			    itera=1+x;
			    ee=itera-ex;
			    ea=fabs(ee);
			    er=ea/ex;
			    erp=er*100;
			printf("    %d                       %lf         %lf  \n",iteraciones,itera,erp);
		        getch();
			}
		break;
		default:
			itera=1+x;
			for(int i=2; i<iteraciones; i++){
				pot=pow(x,i);
				fact=tgamma(i+1);
				suscn+= pot/fact;
				res=itera+suscn;
				ee=res-ex;
			    ea=fabs(ee);
			    er=ea/ex;
			    erp=er*100;
			
				printf("    %d                       %lf         %lf \n",i+1,res,erp);
			}
	}
	
}


