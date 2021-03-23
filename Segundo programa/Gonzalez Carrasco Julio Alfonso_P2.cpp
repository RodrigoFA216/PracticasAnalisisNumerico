#include <iostream>
#include <conio.h>
#include <cmath>
//Gonzalez Carrasco Julio Alfonso
//4CM11

using namespace std;

int main(){

double It=0,Xi=1,Xd=2,Xm=0,Xm1=0,L,Fxm,Fxi,Fxd,E=0,Ep;

cout<<"Función: F(x)=x^3+2x^2+10x-20\n";

cout<<"Xt\t\tXi\t\tXd\t\tXm\t\tF(Xm)\t\tE\n";
    Ep=0.001;

do{
    It++;
    Xm=(Xi+Xd)/2;

    Fxi=(pow(Xi,3))+(2*pow(Xi,2))+(10*(Xi))-20;
    Fxd=(pow(Xd,3))+(2*pow(Xd,2))+(10*(Xd))-20;
    Fxm=(pow(Xm,3))+(2*pow(Xm,2))+(10*(Xm))-20;
    E=abs(Xm1-Xm);

    cout<<It<<"\t\t"<<Xi<<"\t\t"<<Xd<<"\t\t"<<Xm<<"\t\t"<<Fxm<<"\t\t"<<E<<"\n";

    if(Fxm>0){
        Xd=Xm;
    }
    if(Fxm<0){
        Xi=Xm;
    }

    Xm1=Xm;
    //cout<<It<<"\t\t"<<Fxi<<"\t\t"<<Fxd<<"\t\t"<<Xm1<<"\n";

}while(Ep<E);

getch();
return 0;
}
