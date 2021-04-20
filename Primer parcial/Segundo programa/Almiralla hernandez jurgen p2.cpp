#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include<math.h>


using namespace std;

int main(){
    system("color 3E");
	setlocale(LC_CTYPE, "spanish");

    float xi,xd,XM,it,i,x;

    cout<<"\n\nMetodo de BISECCION"
        <<"\nTrabajaremos con la funcion:"
        <<"x^3+2x^2+10x-20\n";

    cout<<"\nIngrese el rango: \n";
    cout<<"Xi: ";
    cin>>xi;
    cout<<"\nXD: ";
    cin>>xd;

    cout<<"\nCuantas iteraciones se haran?: ";
    cin>>it;

for(i=1;i<it+1;i++){

cout<<"\nITERACIONES NUMERO: "<<"'"<<i<<"'";
    cout<<"\nXI: "<<xi;
    cout<<"\nXD: "<<xd;

     XM=(xi+xd)/2;
      cout<<"\nXM: "<<XM;
    float error,XManterior;
    error=abs(XM-XManterior);
    cout<<"\nERROR: "<<error;

     x=pow(XM,3)+(2*pow(XM,2))+(10*XM)-20;
     

     if(x>0){
         xd=XM;
     }else{
         xi=XM;
     }
   
   XManterior=XM;
    }

    

}
    


