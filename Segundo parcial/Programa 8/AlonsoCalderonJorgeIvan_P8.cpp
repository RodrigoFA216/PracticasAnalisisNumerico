#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

float A1, B1, C1, A2, B2, C2, A3, B3, C3, D1, D2, D3;
float b2, b3, c2, c3, d2, d3;
float a11, b11, c11, d11, a22, b22, c22, d22, a33, b33, c33, d33;
float a111, b111, c111, d111, a222, b222, c222, d222, a333, b333, c333, d333;
float x1, x11, w1, w11, z1, z11;

int Gaus() {
	cout<<"Inserte los valores de su primera ecuacion\nf(x)=(A1)X+(B1)Y+(C1)Z=D1";
	cout<<"\nA1: ";cin>>A1;
	cout<<"B1: ";cin>>B1;
	cout<<"C1: ";cin>>C1;
	cout<<"D1: ";cin>>D1;
	
	cout<<"\nInserte los valores de su segunda ecuacion\nf(x)=(A2)X+(B2)Y+(C2)Z=D2";
	cout<<"\nA2: ";cin>>A2;
	cout<<"B2: ";cin>>B2;
	cout<<"C2: ";cin>>C2;
	cout<<"D2: ";cin>>D2;
	
	cout<<"\nInserte los valores de su tercera ecuacion\nf(x)=(A3)X+(B3)Y+(C3)Z=D3";
	cout<<"\nA3: ";cin>>A3;
	cout<<"B3: ";cin>>B3;
	cout<<"C3: ";cin>>C3;
	cout<<"D3: ";cin>>D3;
	
	system("cls");
	
/*M1*/	cout<<"Su matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"	|"<<D1;
	cout<<"\n"<<A2;	cout<<"	"<<B2;	cout<<"	"<<C2;	cout<<"	|"<<D2;
	cout<<"\n"<<A3;	cout<<"	"<<B3;	cout<<"	"<<C3;	cout<<"	|"<<D3;
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu primera nueva ecuacion queda de la siguiente manera:\n";
	cout<<""<<-A2*A1+A1*A2;	cout<<"	"<<-A2*B1+A1*B2;	cout<<"	"<<-A2*C1+A1*C2;	cout<<"	|"<<-A2*D1+A1*D2;
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu segunda nueva ecuacion queda de la siguiente manera:\n";
	cout<<""<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	cout<<"	|"<<-A3*D1+A1*D3;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
/*M2*/cout<<"Su segunda matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"	|"<<D1;
	cout<<"\n"<<-A2*A1+A1*A2;	cout<<"	"<<-A2*B1+A1*B2;	cout<<"	"<<-A2*C1+A1*C2;	cout<<"	|"<<-A2*D1+A1*D2;
	cout<<"\n"<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	cout<<"	|"<<-A3*D1+A1*D3;
	cout<<"\n";
	
	system("pause");
	
	b2=-A2*B1+A1*B2;
	b3=-A3*B1+A1*B3;
	c2=-A2*C1+A1*C2;
	c3=-A3*C1+A1*C3;
	d2=-A2*D1+A1*D2;
	d3=-A3*D1+A1*D3;
	cout<<"\nSu nueva ecuacion sacada de la segunda matriz queda de la siguiente manera:\n";
	cout<<"0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
/*M3*/cout<<"Su tercera matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"	|"<<D1;
	cout<<"\n"<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	cout<<"	|"<<-A3*D1+A1*D3;
	cout<<"\n0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");
	
	a11=A1;				b11=B1;				c11=C1;				d11=D1;
	a22=-A3*A1+A1*A3;	b22=-A3*B1+A1*B3;	c22=-A3*C1+A1*C3;	d22=-A3*D1+A1*D3;
	a33=0;				b33=-b3*b2+b2*b3;	c33=-b3*c2+b2*c3;	d33=-b3*d2+b2*d3;
	cout<<"\nSu nueva ecuacion sacada de la tercera matriz queda de la siguiente manera:\n";
	cout<<""<<c11*a33+(-c33*a11);	cout<<"	"<<c11*b33+(-c33*b11);	cout<<"	"<<c11*c33+(-c33*c11);	cout<<"	|"<<c11*d33+(-c33*d11);
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu segunda nueva ecuacion de la tercera matriz queda de la siguiente manera:\n";
	cout<<""<<c22*a33+(-c33*a22);	cout<<"	"<<c22*b33+(-c33*b22);	cout<<"	"<<c22*c33+(-c33*c22);	cout<<"	|"<<c22*d33+(-c33*d22);
	cout<<"\n";
	
	system("pause");
	system("cls");
	
/*M4*/cout<<"\nSu cuarta matriz queda de la siguiente manera:\n";
	cout<<""<<c11*a33+(-c33*a11);	cout<<"	"<<c11*b33+(-c33*b11);	cout<<"	"<<c11*c33+(-c33*c11);	cout<<"	|"<<c11*d33+(-c33*d11);
	cout<<"\n"<<c22*a33+(-c33*a22);	cout<<"	"<<c22*b33+(-c33*b22);	cout<<"	"<<c22*c33+(-c33*c22);	cout<<"	|"<<c22*d33+(-c33*d22);
	cout<<"\n0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");
	
	a111=c11*a33+(-c33*a11);		b111=c11*b33+(-c33*b11);		c111=c11*c33+(-c33*c11);		d111=c11*d33+(-c33*d11);
	a222=c22*a33+(-c33*a22);		b222=c22*b33+(-c33*b22);		c222=c22*c33+(-c33*c22);		d222=c22*d33+(-c33*d22);
	a333=0;							b333=-b3*b2+b2*b3;				c333=-b3*c2+b2*c3;				d333=-b3*d2+b2*d3;
	cout<<"\nSu nueva ecuacion sacada de la cuarta matriz queda de la siguiente manera:\n";
	cout<<""<<b111*a222+(-b222*a111);	cout<<"	"<<b111*b222+(-b222*b111);	cout<<"	"<<b111*c222+(-b222*c111);	cout<<"	|"<<b111*d222+(-b222*d111);
	cout<<"\n";
	
	system("pause");
	system("cls");
	
/*M5*/cout<<"\nSu quinta matriz queda de la siguiente manera:\n";
	cout<<""<<b111*a222+(-b222*a111);	cout<<"	"<<b111*b222+(-b222*b111);	cout<<"	"<<b111*c222+(-b222*c111);	cout<<"	|"<<b111*d222+(-b222*d111);
	cout<<"\n"<<c22*a33+(-c33*a22);	cout<<"	"<<c22*b33+(-c33*b22);	cout<<"	"<<c22*c33+(-c33*c22);	cout<<"	|"<<c22*d33+(-c33*d22);
	cout<<"\n0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	x1=b111*a222+(-b222*a111);		x11=b111*d222+(-b222*d111);
	w1=c22*b33+(-c33*b22);			w11=c22*d33+(-c33*d22);
	z1=-b3*c2+b2*c3;				z11=-b3*d2+b2*d3;
/*M6*/cout<<"\nSu sexta y ulima matriz que es identidad queda de la siguiente manera:\n";
	cout<<"1";	cout<<"	0";	cout<<"	0";	cout<<"	|"<<x11/x1;
	cout<<"\n0";	cout<<"	1";	cout<<"	0";	cout<<"	|"<<w11/w1;
	cout<<"\n0";	cout<<"	0";	cout<<"	1";	cout<<"	|"<<z11/z1;
	cout<<"\n";
	
	cout<<"Y asi los valores de X, Y, Z son:\n";
	cout<<"X= "<<x11/x1;
	cout<<"\nY= "<<w11/w1;
	cout<<"\nZ= "<<z11/z1;
	}
int main(){
	Gaus();
	
}





