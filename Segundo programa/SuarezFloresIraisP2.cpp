#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double e=0, E=0.001;
	double Xi=0, Xd=0, lga=0, n=0, lgt=0, r1, r2;
	double res1=0, res2=0, Xm=0, nitera=0, fxm;
	
	printf("\t\t\t\tSuarez Flores Irais\n");
	printf("\t\t\t\tMetodo de biseccion");

	
	printf("\nIngrese Xi: ");
	scanf("%lf",&Xi);
	printf("Ingrese Xd: ");
	scanf("%lf",&Xd);
	
	
	lga=Xd-Xi;
	n=(log(lga))-(log(E));
	lgt=log(2);
	nitera=n/lgt;
    nitera=ceil(nitera);
	
	printf("\nNumero de Iteraciones Necesarias:   %.2lf\n\n",nitera);
	printf("\n |# Iteracion|     \t |Xi|          \t |Xd|         \t |Xm|        \t |f(Xm)|        \t  |Error|");
	
	for(int i=1; i<=nitera; i++){
		r1=Xi;
		r2=Xd;
		Xm=(Xi+Xd)/2;
		fxm=pow(Xm,3)+2*pow(Xm,2)+(10*Xm)-20;
		if(i>1){
		e=r1-Xm;
		e=fabs(e);
	}
		printf("\n    %i            \t %lf      \t %lf      \t %lf    \t %lf         \t %lf",i,r1,r2,Xm,fxm,e);
		
		if(fxm>0){
			Xd=Xm;
		}
		else if(fxm<0){
			Xi=Xm;
		}
	}
	
}
