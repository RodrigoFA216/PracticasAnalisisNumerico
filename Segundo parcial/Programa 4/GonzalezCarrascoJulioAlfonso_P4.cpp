#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main(){

float Xi,Xo=1,Fx1=0,Fx2=0,Fx3,Fx4,i=1,E=1,Err;
int GraP,GraD,j,k,coeP[10],coeD[10],IndP,IndD;

//Formula F(x)=x^3+2x^2+10x-20      F'(x)=3x^2+4x+10
//Xi=1  X=X(i+1)=Xi-F(Xi)/F'(Xi)  E=0.001

cout<<"Método de Newton-Raphson"<<endl;
//cout<<"Formula F(x)=x^3+2x^2+10x-20  F'(x)=3x^2+4x+10   Xi=1  Xo=X(i+1)=Xi-F(Xi)/F'(Xi)  E=0.001"<<endl;
cout<<"Aviso: Actualmente esta version del programa (ver 0.1.4) no soporta funciones trigonometricas.\n"<<endl;

cout<<"Ingresa el valor inicial de Xi ";
cin>>Xi;

cout<<"¿De que grado es su polinomio? ";
cin>>GraP;
j=GraP;

cout<<"Ingresa los coeficientes de los terminos del polinomio "<<endl;
for(int h=0;h<GraP;h++){

    cout<<"Ingresa el coeficiente del termino con exponente "<<j<<" : ";
    cin>>coeP[h];
    j--;
}
cout<<"Ingrese el valor del termino independiente del polinomio ";
cin>>IndP;


cout<<"\n¿De que grado es la derivada del polinomio? ";
cin>>GraD;
k=GraD;
cout<<"Ingresa los coeficientes de los terminos del polinomio "<<endl;

for(int h=0;h<GraD;h++){

    cout<<"Ingresa el coeficiente del termino con exponente "<<k<<" : ";
    cin>>coeD[h];
    k--;
}

cout<<"Ingrese el valor del termino independiente de la derivada del polinomio ";
cin>>IndD;

cout<<"\nIngresa el error (E) ";
cin>>Err;

cout<<"\nIteracion\tXi\t\tXo\t\tFx1\t\t\tFx2\t\tE"<<endl;
while(E>Err){
    Xi=Xo;

    //Fx3=(pow(Xi,3))+(2*(pow(Xi,2)))+(10*Xi)-20;
    j=GraP;
    Fx1=0;
    for(int h=0;h<GraP;h++){
    //cout<<"Fx1="<<Fx1<<"+"<<coeP[h]<<"*("<<Xi<<"^"<<j<<")--\n";
    Fx1=Fx1+(coeP[h]*(pow(Xi,j)));

    j--;
    }
    Fx1=Fx1+IndP;

    //Fx4=(3*(pow(Xi,2)))+(4*Xi)+10;
    k=GraD;
    Fx2=0;
    for(int h=0;h<GraD;h++){
    Fx2=Fx2+(coeD[h]*(pow(Xi,k)));
    k--;
    }
    Fx2=Fx2+IndD;

    Xo=Xi-(Fx1/Fx2);
    E=fabs(Xo-Xi);
    cout<<i<<"\t\t"<<Xi<<"\t\t"<<Xo<<"\t\t"<<Fx1<<"\t\t\t"<<Fx2<<"\t\t"<<E<<endl;

    i++;
}

getch();
return 0;
}
