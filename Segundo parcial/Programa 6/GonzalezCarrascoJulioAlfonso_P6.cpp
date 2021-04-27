#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main(){

 float Xi,Xo,Fx1=0,Fx2=0,Fx3=0,Fx4=0,i=1,E=1,Err;
 int GraP,GraD,j,k,coeP[10],coeD[10],IndP,IndD;

 //cout<<"Formula F(x)=x^3+2x^2+10x-20 Xi=1  Xo=0  Fx=((Xi-Xo)(Fxi))/(Fxi-Fxo) E=0.001"<<endl;

 cout<<"Aviso: Actualmente esta version del programa (ver 0.1.2) no soporta funciones trigonometricas.\n"<<endl;

cout<<"Ingresa el valor inicial de Xi ";
cin>>Xi;
cout<<"Ingresa el valor inicial de Xf ";
cin>>Xo;

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

cout<<"\nIngresa el error (E) ";
cin>>Err;

cout<<"\nIteracion\tXi\t\tXo\t\tF(xi)\t\tF(xo)\t\tFx\t\tFm\t\tE"<<endl;

while(E>Err){

    j=GraP;
    Fx1=0;
    for(int h=0;h<GraP;h++){
    Fx1=Fx1+(coeP[h]*(pow(Xi,j)));
    j--;
    }
    Fx1=Fx1+IndP;

    j=GraP;
    Fx2=0;
    for(int h=0;h<GraP;h++){
    Fx2=Fx2+(coeP[h]*(pow(Xo,j)));
    j--;
    }
    Fx2=Fx2+IndP;

    Fx3=0;
    Fx3=Xo-(((Xo-Xi)*(Fx2))/((Fx2)-(Fx1)));

    j=GraP;
    Fx4=0;
    for(int h=0;h<GraP;h++){
    Fx4=Fx4+(coeP[h]*(pow(Fx3,j)));
    j--;
    }
    Fx4=Fx4+IndP;

    E=fabs(Xi-Fx3);

    cout<<i<<"\t\t"<<Xi<<"\t\t"<<Xo<<"\t\t"<<Fx1<<"\t\t"<<Fx2<<"\t\t"<<Fx3<<"\t\t"<<Fx4<<"\t\t"<<E<<endl;
    Xi=Fx3;
    i++;
}

 getch();
 return 0;
}
