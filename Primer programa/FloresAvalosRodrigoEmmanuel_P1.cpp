#include<iostream>
#include<math.h>
#include<locale.h>
#include<wchar.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

main(){
    setlocale(LC_CTYPE, "Spanish");
    float numero, iter, x, serie, resultado, aux1, aux2, aux3, auxe, real, aprox, absoluto, porcentual;
    double e=2.718281828;
    int repetir;
    inicio:
    system("cls");
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"  ESTE PROGRAMA CALCULA LA APROXIMACION DE e^x POR EL METODO DE MCLAURIN"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"ingrese cuantas iteraciones quiere hacer: "<<endl;
    cin>>iter;
    afk:
    cout<<"ingrese el valor de X: "<<endl;
    cin>>x;
    e=pow(e,x);
    cout<<"el valor real para e^x es: "<<e<<endl;
    if (x<0)
    {
        cout<<"no se puede calcular par anumeros negativos"<<endl;
        system("pause");
        goto afk;
    }
    if (x==0)
    {
        resultado=1;
    }
    if (x==1)
    {
        resultado=1+x;
    }
    if (x>1)
    {
        resultado=1+x;
        cout<<"E=1+"<<x;
        for (float i = 2; i <= iter; i++)
        {
            aux1=pow(x,i);
            //cout<<"aux1: "<<aux1;
            aux2=1;
            for (int j = 1; j <= i; j++)
            {
                aux2*=j;
            }
            //cout<<"aux2: "<<aux2;
            aux3=aux1/aux2;
            //cout<<"aux3: "<<aux3;
            resultado+=aux3;
            cout<<" +"<<resultado;
        }
    }
    cout<<endl<<"La aproximacion calculada por el metodo de Maclaurin es: "<<resultado<<endl;
    real=e;
    aprox=resultado;
    absoluto=real-aprox;
    cout<<"el error absoluto es de "<<absoluto<<endl;
    porcentual=(absoluto/real)*100;
    cout<<"el porcentaje de error es de "<<porcentual<<"%"<<endl;
    cout<<"Quiere repetir el programa?"<<endl<<"(1)Si\t(2)No";
    cin>>repetir;
    if (repetir==1)
    {
        goto inicio;
    }
    if (repetir>1)
    {
        cout<<"a bueno adiós master"<<endl;
    }
    cout<<endl<<"Hecho por Rodrigo E. Flores Avalos"<<endl;
    system("pause");
}