#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

float A1, B1, C1, A2, B2, C2, A3, B3, C3, K1, K2, K3;
float D1=1, E1=0, F1=0, D2=0, E2=1, F2=0, D3=0, E3=0, F3=1;
float A11, B11, C11, D11, E11, F11, A22, B22, C22, D22, E22, F22, A33, B33, C33, D33, E33, F33;
float A111, B111, C111, D111, E111, F111, A222, B222, C222, D222, E222, F222, A333, B333, C333, D333, E333, F333;
float A1111, B1111, C1111, D1111, E1111, F1111, A2222, B2222, C2222, D2222, E2222, F2222, A3333, B3333, C3333, D3333, E3333, F3333;
float a1, a2, a3, b1, b2, b3, c1, c2, c3;

int Matriz_inversa() {
	cout<<"Inserte los valores de su primera ecuacion\nf(x)=(A1)X+(B1)Y+(C1)Z=D1";
	cout<<"\nA1: ";cin>>A1;
	cout<<"B1: ";cin>>B1;
	cout<<"C1: ";cin>>C1;
	cout<<"D1: ";cin>>K1;
	
	cout<<"\nInserte los valores de su segunda ecuacion\nf(x)=(A2)X+(B2)Y+(C2)Z=D2";
	cout<<"\nA2: ";cin>>A2;
	cout<<"B2: ";cin>>B2;
	cout<<"C2: ";cin>>C2;
	cout<<"D2: ";cin>>K2;
	
	cout<<"\nInserte los valores de su tercera ecuacion\nf(x)=(A3)X+(B3)Y+(C3)Z=D3";
	cout<<"\nA3: ";cin>>A3;
	cout<<"B3: ";cin>>B3;
	cout<<"C3: ";cin>>C3;
	cout<<"D3: ";cin>>K3;
	
	system("cls");
	
/*M1*/	cout<<"Su matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"   |1";	cout<<"	     0";	cout<<"	     0";
	cout<<"\n"<<A2;	cout<<"	"<<B2;	cout<<"	"<<C2;	cout<<"   |0";	cout<<"	     1";	cout<<"	     0";
	cout<<"\n"<<A3;	cout<<"	"<<B3;	cout<<"	"<<C3;	cout<<"   |0";	cout<<"	     0";	cout<<"	     1";
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu primera nueva ecuacion queda de la siguiente manera:\n";
	cout<<""<<-A2*A1+A1*A2;	cout<<"	"<<-A2*B1+A1*B2;	cout<<"	"<<-A2*C1+A1*C2;	
	cout<<"   |"<<-A2*D1+A1*D2;	cout<<"	   "<<-A2*E1+A1*E2;	cout<<"	   "<<-A2*F1+A1*F2;
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu segunda nueva ecuacion queda de la siguiente manera:\n";
	cout<<""<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	
	cout<<"   |"<<-A3*D1+A1*D3;	cout<<"	   "<<-A3*E1+A1*E3;	cout<<"	   "<<-A3*F1+A1*F3;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"Su segunda matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"|1";	cout<<"     0";	cout<<"      0";
	cout<<"\n"<<-A2*A1+A1*A2;	cout<<"	"<<-A2*B1+A1*B2;	cout<<"	"<<-A2*C1+A1*C2;	cout<<"|"<<-A2*D1+A1*D2;	cout<<"	"<<-A2*E1+A1*E2;	cout<<"	"<<-A2*F1+A1*F2;
	cout<<"\n"<<-A3*A1+A1*A3;	cout<<"	"<<-A3*B1+A1*B3;	cout<<"	"<<-A3*C1+A1*C3;	cout<<"|"<<-A3*D1+A1*D3;	cout<<"	"<<-A3*E1+A1*E3;	cout<<"	"<<-A3*F1+A1*F3;
	cout<<"\n";
	
	A11=A1; 			B11=B1;				C11=C1;				D11=D1;				E11=E1;				F11=F1;
	A22=-A2*A1+A1*A2;	B22=-A2*B1+A1*B2;	C22=-A2*C1+A1*C2;	D22=-A2*D1+A1*D2;	E22=-A2*E1+A1*E2;	F22=-A2*F1+A1*F2;
	A33=-A3*A1+A1*A3;	B33=-A3*B1+A1*B3;	C33=-A3*C1+A1*C3;	D33=-A3*D1+A1*D3;	E33=-A3*E1+A1*E3;	F33=-A3*F1+A1*F3;
	
	system("pause");
	
	cout<<"\nSu primera nueva ecuacion de la segunda matriz queda de la siguiente manera:\n";
	cout<<""<<B33*A22+-B22*A33;	cout<<"	"<<B33*B22+-B22*B33;	cout<<"	"<<B33*C22+-B22*C33;	cout<<"   |"<<B33*D22+-B22*D33;	cout<<"	   "<<B33*E22+-B22*E33;	cout<<"	   "<<B33*F22+-B22*F33;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"Su tercera matriz queda de la siguiente manera:\n";
	cout<<""<<A1;	cout<<"	"<<B1;	cout<<"	"<<C1;	cout<<"|1";	cout<<"     0";	cout<<"      0";
	cout<<"\n"<<-A2*A1+A1*A2;	cout<<"	"<<-A2*B1+A1*B2;	cout<<"	"<<-A2*C1+A1*C2;	cout<<"|"<<-A2*D1+A1*D2;	cout<<"	"<<-A2*E1+A1*E2;	cout<<"	"<<-A2*F1+A1*F2;
	cout<<"\n"<<B33*A22+-B22*A33;	cout<<"	"<<B33*B22+-B22*B33;	cout<<"	"<<B33*C22+-B22*C33;	cout<<"|"<<B33*D22+-B22*D33;	cout<<"	"<<B33*E22+-B22*E33;	cout<<"	"<<B33*F22+-B22*F33;
	cout<<"\n";
	
	A111=A1;				B111=B1;				C111=C1;				D111=D1;				E111=E1;				F111=F1;
	A222=-A2*A1+A1*A2;		B222=-A2*B1+A1*B2;		C222=-A2*C1+A1*C2;		D222=-A2*D1+A1*D2;		E222=-A2*E1+A1*E2;		F222=-A2*F1+A1*F2;
	A333=B33*A22+-B22*A33;	B333=B33*B22+-B22*B33;	C333=B33*C22+-B22*C33;	D333=B33*D22+-B22*D33;	E333=B33*E22+-B22*E33;	F333=B33*F22+-B22*F33;
	
	system("pause");
	
	cout<<"\nSu primera nueva ecuacion de la tercera matriz queda de la siguiente manera:\n";
	cout<<""<<C111*A333+-C333*A111;	cout<<"	"<<C111*B333+-C333*B111;	cout<<"	"<<C111*C333+-C333*C111;	cout<<"   |"<<C111*D333+-C333*D111;	cout<<"	   "<<C111*E333+-C333*E111;	cout<<"	   "<<C111*F333+-C333*F111;
	cout<<"\n";
	
	system("pause");
	
	cout<<"\nSu segunda nueva ecuacion de la tercera matriz queda de la siguiente manera:\n";
	cout<<""<<-C222*A333+C333*A222;	cout<<"	"<<-C222*B333+C333*B222;	cout<<"	"<<-C222*C333+C333*C222;	cout<<"   |"<<-C222*D333+C333*D222;	cout<<"	   "<<-C222*E333+C333*E222;	cout<<"	   "<<-C222*F333+C333*F222;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"Su cuarta matriz queda de la siguiente manera:\n";
	cout<<""<<C111*A333+-C333*A111;	cout<<"	"<<C111*B333+-C333*B111;	cout<<"	"<<C111*C333+-C333*C111;	cout<<"|"<<C111*D333+-C333*D111;	cout<<"	"<<C111*E333+-C333*E111;	cout<<"	"<<C111*F333+-C333*F111;
	cout<<"\n"<<-C222*A333+C333*A222;	cout<<"	"<<-C222*B333+C333*B222;	cout<<"	"<<-C222*C333+C333*C222;	cout<<"|"<<-C222*D333+C333*D222;	cout<<"	"<<-C222*E333+C333*E222;	cout<<"	"<<-C222*F333+C333*F222;
	cout<<"\n"<<B33*A22+-B22*A33;	cout<<"	"<<B33*B22+-B22*B33;	cout<<"	"<<B33*C22+-B22*C33;	cout<<"|"<<B33*D22+-B22*D33;	cout<<"	"<<B33*E22+-B22*E33;	cout<<"	"<<B33*F22+-B22*F33;
	cout<<"\n";
	
	system("pause");
	
	A1111=C111*A333+-C333*A111;		B1111=C111*B333+-C333*B111;		C1111=C111*C333+-C333*C111;		D1111=C111*D333+-C333*D111;		E1111=C111*E333+-C333*E111;		F1111=C111*F333+-C333*F111;
	A2222=-C222*A333+C333*A222;		B2222=-C222*B333+C333*B222;		C2222=-C222*C333+C333*C222;		D2222=-C222*D333+C333*D222;		E2222=-C222*E333+C333*E222;		F2222=-C222*F333+C333*F222;
	A3333=B33*A22+-B22*A33;			B3333=B33*B22+-B22*B33;			C3333=B33*C22+-B22*C33;			D3333=B33*D22+-B22*D33;			E3333=B33*E22+-B22*E33;			F3333=B33*F22+-B22*F33;
	
	cout<<"\nSu primera nueva ecuacion de la cuarta matriz queda de la siguiente manera:\n";
	cout<<""<<-B1111*A2222+B2222*A1111;	cout<<"	"<<-B1111*B2222+B2222*B1111;	cout<<"	"<<-B1111*C2222+B2222*C1111;	cout<<"   |"<<-B1111*D2222+B2222*D1111;	cout<<"	   "<<-B1111*E2222+B2222*E1111;	cout<<"	   "<<-B1111*F2222+B2222*F1111;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"Su quinta matriz queda de la siguiente manera:\n";
	cout<<""<<-B1111*A2222+B2222*A1111;	cout<<"	"<<-B1111*B2222+B2222*B1111;	cout<<"	"<<-B1111*C2222+B2222*C1111;	cout<<"|"<<-B1111*D2222+B2222*D1111;	cout<<"	"<<-B1111*E2222+B2222*E1111;	cout<<"	"<<-B1111*F2222+B2222*F1111;
	cout<<"\n"<<-C222*A333+C333*A222;	cout<<"	"<<-C222*B333+C333*B222;	cout<<"	"<<-C222*C333+C333*C222;	cout<<"|"<<-C222*D333+C333*D222;	cout<<"	"<<-C222*E333+C333*E222;	cout<<"	"<<-C222*F333+C333*F222;
	cout<<"\n"<<B33*A22+-B22*A33;	cout<<"	"<<B33*B22+-B22*B33;	cout<<"	"<<B33*C22+-B22*C33;	cout<<"|"<<B33*D22+-B22*D33;	cout<<"	"<<B33*E22+-B22*E33;	cout<<"	"<<B33*F22+-B22*F33;
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"Su sexta y ultima matriz queda de la siguiente manera:\n";
	cout<<""<<(-B1111*A2222+B2222*A1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*B2222+B2222*B1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*C2222+B2222*C1111)/(-B1111*A2222+B2222*A1111);	cout<<"|"<<(-B1111*D2222+B2222*D1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*E2222+B2222*E1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*F2222+B2222*F1111)/(-B1111*A2222+B2222*A1111);
	cout<<"\n"<<(-C222*A333+C333*A222)/(-C222*B333+C333*B222);	cout<<"	"<<(-C222*B333+C333*B222)/(-C222*B333+C333*B222);	cout<<"	"<<(-C222*C333+C333*C222)/(-C222*B333+C333*B222);	cout<<"|"<<(-C222*D333+C333*D222)/(-C222*B333+C333*B222);	cout<<"	"<<(-C222*E333+C333*E222)/(-C222*B333+C333*B222);	cout<<"	"<<(-C222*F333+C333*F222)/(-C222*B333+C333*B222);
	cout<<"\n"<<(B33*A22+-B22*A33)/(B33*C22+-B22*C33);	cout<<"	"<<(B33*B22+-B22*B33)/(B33*C22+-B22*C33);	cout<<"	"<<(B33*C22+-B22*C33)/(B33*C22+-B22*C33);	cout<<"|"<<(B33*D22+-B22*D33)/(B33*C22+-B22*C33);	cout<<"	"<<(B33*E22+-B22*E33)/(B33*C22+-B22*C33);	cout<<"	"<<(B33*F22+-B22*F33)/(B33*C22+-B22*C33);
	cout<<"\n";
	
	system("pause");
	system("cls");
	
	cout<<"La matriz inversa es:\n";
	cout<<" "<<(-B1111*D2222+B2222*D1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*E2222+B2222*E1111)/(-B1111*A2222+B2222*A1111);	cout<<"	"<<(-B1111*F2222+B2222*F1111)/(-B1111*A2222+B2222*A1111);
	cout<<"\n"<<(-C222*D333+C333*D222)/(-C222*B333+C333*B222);			cout<<"	"<<(-C222*E333+C333*E222)/(-C222*B333+C333*B222);			cout<<"	"<<(-C222*F333+C333*F222)/(-C222*B333+C333*B222);
	cout<<"\n"<<(B33*D22+-B22*D33)/(B33*C22+-B22*C33);					cout<<"	"<<(B33*E22+-B22*E33)/(B33*C22+-B22*C33);					cout<<"	"<<(B33*F22+-B22*F33)/(B33*C22+-B22*C33);
	cout<<"\n";
	
	a1=(-B1111*D2222+B2222*D1111)/(-B1111*A2222+B2222*A1111);	b1=(-B1111*E2222+B2222*E1111)/(-B1111*A2222+B2222*A1111);	c1=(-B1111*F2222+B2222*F1111)/(-B1111*A2222+B2222*A1111);
	a2=(-C222*D333+C333*D222)/(-C222*B333+C333*B222);			b2=(-C222*E333+C333*E222)/(-C222*B333+C333*B222);			c2=(-C222*F333+C333*F222)/(-C222*B333+C333*B222);
	a3=(B33*D22+-B22*D33)/(B33*C22+-B22*C33);					b3=(B33*E22+-B22*E33)/(B33*C22+-B22*C33);					c3=(B33*F22+-B22*F33)/(B33*C22+-B22*C33);
	
	cout<<"Los valores de X, Y, Z son:\n";
	cout<<"X= "<<a1*K1+b1*K2+c1*K3;
	cout<<"\nY= "<<a2*K1+b2*K2+c2*K3;
	cout<<"\nZ= "<<a3*K1+b3*K2+c3*K3;
	cout<<"\n";
	
	}
int main(){
	Matriz_inversa();
	
}





