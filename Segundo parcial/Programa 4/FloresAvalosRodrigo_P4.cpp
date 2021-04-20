#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

#define N 100
float f, fp, Vi, e, ep, Vo;

float NRP(float x)
{
    Vi=x-((pow(x,3)+(2*pow(x,2)+(10*x)-20))/((3*pow(x,2)+(4*x)+10)));
    e=abs(Vi-x);
    Vo=Vi;
    cout<<"Resultado: "<<Vo<<endl;
    return e;
}

int main()
{
    cout<<"PROGRAMA HECHO POR RODRIGO EMMANUEL FLORES AVALOS"<<endl;
    cout<<"La función a evaluar es: x^3+2x^2+10x-20"<<endl<<"Funcion derivada: 3x^2+4x+10"<<endl;
    cout<<"Ingresa el valor inicial"<<endl;
    cin>>Vo;
    cout<<"Ingresa el error"<<endl;
    cin>>ep;

    for (int i=0;i<N;i++)
    {
        f=NRP(Vo);
        cout<<f<<endl;
        if (f<ep)
        {
            i=100;
        }
    }
    system("pause");
}