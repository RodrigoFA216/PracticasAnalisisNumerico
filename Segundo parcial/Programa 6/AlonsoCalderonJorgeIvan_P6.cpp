#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;
float A, B, C, D, i, fx, xi, xf, fi, ff;
float xm, xm2, xm3, xm4, xm5;
float fxm, fxm2, fxm3, fxm4, fxm5;
float x, x2,x3,x4,x5;

int pfalsa() {
	cout<<"Inserte f(x)=Ax^3+Bx^2+Cx+D\nA: ";cin>>A;
	cout<<"B: ";cin>>B;
	cout<<"C: ";cin>>C;
	cout<<"D: ";cin>>D;
	
	system("cls");
	
	cout<<"Sus valores de f(-5) a f(5) es:";
	for(i=-5; i<=5; i++){
		fx=A*i*i*i+B*i*i+C*i+D;
		cout<<"\nf("<<i; cout<<")= "<<fx;
	}
	cout<<"\n\nDe su tabla anterir seleccione:\n";
	
	cout<<"f(xi) (ultimo resultado negativo de la funcion con xi) y xi de esa funcion:\n";
	cout<<"f(xi)= ";cin>>fi;
	cout<<"xi: ";cin>>xi;
	
	cout<<"f(xf) (primer resultado positivo despues de f(xi)) y xf de esa funcion:\n";
	cout<<"f(xf)= ";cin>>ff;
	cout<<"xf: ";cin>>xf;
	
	system("cls");
	
	//xm1:
	xm=xf-(((xf-xi)*ff)/(ff-fi));
	fxm=A*xm*xm*xm+B*xm*xm+C*xm+D;
	
	//xm2:
	xm2=xf-(((xf-xm)*ff)/(ff-fxm));
	fxm2=A*xm2*xm2*xm2+B*xm2*xm2+C*xm2+D;
	
	//xm3:
	xm3=xf-(((xf-xm2)*ff)/(ff-fxm2));
	fxm3=A*xm3*xm3*xm3+B*xm3*xm3+C*xm3+D;
	
	//xm4:
	xm4=xf-(((xf-xm3)*ff)/(ff-fxm3));
	fxm4=A*xm4*xm4*xm4+B*xm4*xm4+C*xm4+D;
	
	//xm5:
	xm5=xf-(((xf-xm4)*ff)/(ff-fxm4));
	fxm5=A*xm5*xm5*xm5+B*xm5*xm5+C*xm5+D;
	
	//1
		cout<<"It 1:\n";	cout<<"xm= "<<xm;		cout<<"\nf(xm)= "<<fxm;		cout<<"\n";		cout<<"Error: "<<abs(xm-xi);
	//2
		cout<<"\n\nIt 2:\n";	cout<<"xm= "<<xm2;		cout<<"\nf(xm)= "<<fxm2;	cout<<"\n";		cout<<"Error: "<<abs(xm2-xm);
	//3
		cout<<"\n\nIt 3:\n";	cout<<"xm= "<<xm3;		cout<<"\nf(xm)= "<<fxm3;	cout<<"\n";		cout<<"Error: "<<abs(xm3-xm2);
	//4 
		cout<<"\n\nIt 4:\n";	cout<<"xm= "<<xm4;		cout<<"\nf(xm)= "<<fxm4;	cout<<"\n";		cout<<"Error: "<<abs(xm4-xm3);
	//5
		cout<<"\n\nIt 5:\n";	cout<<"xm= "<<xm5;		cout<<"\nf(xm)= "<<fxm5;	cout<<"\n";		cout<<"Error: "<<abs(xm5-xm4);
		
}

int main(){
	pfalsa();
	
}





