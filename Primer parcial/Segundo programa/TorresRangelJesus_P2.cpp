#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double E, Ea;
	double Xi, Xd,Vc, Dp, Num, Deno;
	double res1, res2, resP, IteracionesN;
	
	cout<<"  Torres Rangel Jesus"<<endl;
	cout<<"  Analisis Numerico"<<endl;
	
	cout<<"\nPrograma del Metodo de biseccion"<<endl;
	
	E=0;
	Ea=0.001;
	Xi=0;
	Xd=0;
	Vc=0;
	Dp=0; 
	Num=0; 
	Deno=0;
	res1=0; 
	res2=0; 
	resP=0; 
	IteracionesN=0;
	
	cout<<"\nIngrese Xi: ";
	cin>>Xi;
	cout<<"Ingrese Xd: ";
	cin>>Xd;
	
	
	Dp=Xd-Xi;
	Num=(log(Dp))-(log(Ea));
	Deno=log(2);
	IteracionesN=Num/Deno;
    IteracionesN=ceil(IteracionesN);
	
	res1=Xi;
	res2=Xd;
	
	cout<<"\nXi\t Xd \t Xm \t Error";
	
	for(int i=0; i<IteracionesN; i++){
		Num=res1+res2;
		Deno=2;
		resP=Num/Deno;
		
		E=res1-resP;
		E=fabs(E);
		
		cout<<"\n"<<res1<<"\t"<<res2<<"\t"<<resP<<"\t"<<E;
		
		Vc=res2;
		res2=res1;
		res1=resP;
	}
	

}

