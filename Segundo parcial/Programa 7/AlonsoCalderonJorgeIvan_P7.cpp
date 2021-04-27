#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

float A1, B1, C1, A2, B2, C2, A3, B3, C3, D1, D2, D3;
float b2, b3, c2, c3, d2, d3;
float x, y, z;
	
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
/*P*/cout<<"0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
/*M3*/cout<<"Su ultima matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"	|"<<D1;
	cout<<"\n"<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	cout<<"	|"<<-A3*D1+A1*D3;
	cout<<"\n0";	cout<<"	"<<-b3*b2+b2*b3;	cout<<"	"<<-b3*c2+b2*c3;	cout<<"	|"<<-b3*d2+b2*d3;
	cout<<"\n";
	
	system("pause");

	cout<<"Y asi los valores de X, Y, Z son:\n";
	z=(-b3*d2+b2*d3)/(-b3*c2+b2*c3);
	y=((-A3*D1+A1*D3)-(-A3*C1+A1*C3)*z)/(-A3*B1+A1*B3);
	x=(D1-B1*y-C1*z)/(A1);
	
	cout<<"X= "<<x;
	cout<<"\nY= "<<y;
	cout<<"\nZ= "<<z;
	}
int main(){
	Gaus();
	
}





