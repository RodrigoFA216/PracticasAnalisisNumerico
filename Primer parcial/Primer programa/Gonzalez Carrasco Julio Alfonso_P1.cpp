#include <iostream>
#include <conio.h>
#include <cmath>
//Gonzalez Carrasco Julio Alfonso
//4CM11

using namespace std;

class Num{
public:
    float sucesion(float,float);
    float x,y;
};

//serie Maclaurin, pedir x y numero de armonicos

float Num::sucesion(float x,float y){

float z;
int w=1;

if(y==0){
    z=1;
}else{
    for(int i=1;i<=y;i++){
        w=w*i;
    }
    z=(pow(x,y))/w;
}

return z;
}

int main(){

    float x,elem=0,eP=0;
    double P=0,eX;
    int s;
    Num o;

    cout<<"Ingresa el numero x ";
    cin>>x;
    cout<<"Numero de elementos a tomar ";
    cin>>elem;

    eX=exp(x);

    cout<<"\nTabla de Serie Maclaurin...\n";
    cout<<"e^x= "<<eX;
    cout<<"\nX\t# de elementos\tP\t\tEP\n";

    for(int i=0;i<elem;i++){
        P=P+o.sucesion(x,i);

        eP=(((eX-P))/eX)*100;

        cout<<x<<"\t"<<i+1<<"\t\t"<<P<<"\t\t"<<eP<<"\n";
    }

    getch();

return 0;
}
