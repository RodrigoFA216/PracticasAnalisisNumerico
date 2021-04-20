#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//huerta mellado francisco javier
using namespace std;

float val1, val2, val3, val4;
float valA, valX;
float evaluacion1, evaluacion2, evaluacion3, evaluacion4;
float d1, d2, d3;
float dd1, dd2;
float ddd1;
float sumatoria;
float i2=(2*1);
float i3=(3*2*1);
float solucionA;

int main()

{

    cout<<"                              **Serie de Taylor**"<<endl;
    cout<< "Ingresa el valor de A"<<endl;
    cin>> valA;
    cout<< "Ingresa el valor de X"<<endl;
    cin>> valX;
    cout<< "Ingresa el valor elevado a la tercera potencia"<<endl;
    cin>> val1;
    cout<< "ingresa el valor elavado a la segunda potencia"<<endl;
    cin>>val2;
    cout<< "Ingresa el valor elevado a la primera potencia"<<endl;
    cin>>val3;
    cout<< "ingresa la constante"<<endl;
    cin>>val4;

    float valA3=(valA*valA*valA);

    float valA2=(valA*valA);

    evaluacion1=(val1*valA3)+(val2*valA2)+(val3*valA)+(val4);

    d1=val1*3;
    d2=val2*2;
    d3=val3;

    evaluacion2=(d1*valA2)+(d2*valA)+(d3);

    dd1=d1*2;
    dd2=d2;
    evaluacion3=(dd1*valA)+(dd2);


    ddd1=dd1;

 
    evaluacion4=ddd1;

 
float valAX=(valX-valA);

float valAX3=(valAX*valAX*valAX);

float valAX2=(valAX*valAX);

float fa2=(evaluacion3/i2);

float fa3=(evaluacion4/i3);


    sumatoria=(evaluacion1)+(evaluacion2*valAX)+(fa2*valAX2)+(fa3*valAX3);


float valX3=(valX*valX*valX);

float valX2=(valX*valX);

 
float error1, error2, error3;


    solucionA=(val1*valX3)+(val2*valX2)+(val3*valX)+(val4);

    int X=solucionA;

    int X2=sumatoria;

    int X3;


    error1=X-X2;

    error2=(error1)/(X);

    error3=error2;

 
    cout<<"Evalucion en F="<<evaluacion1<<endl;

    cout<<"Evalucion en F'="<<evaluacion2<<endl;

    cout<<"Evalucion en F''="<<evaluacion3<<endl;

    cout<<"Evalucion en F'''="<<evaluacion4<<endl;

    cout<<"Sumatoria="<<sumatoria<<endl;

    cout<<"Solucion analitica="<<solucionA<<endl;

    cout<<"Error absoluto="<<error1<<endl;

    cout<<"Error relativo="<<error2<<endl;

    cout<<"Error potencial="<<error3;

    cout<<"%"<<endl;
}
