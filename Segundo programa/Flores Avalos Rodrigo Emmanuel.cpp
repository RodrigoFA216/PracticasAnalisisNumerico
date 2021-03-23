#include <iostream>
#include <iomanip> // setprecision
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string>
#include<windows.h> 

using namespace std;

#define presicion 6
#define intervalos 15

double f(double x);

void gotoxy(int x,int y)
{  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

void cabecera(){
    cout<<"------------------------------------------------------------------------------"<<endl;
    cout<<"calculo de raices de una función usando el método de bisección"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl<<endl;
}

main(){
    double min, max, ancho, tolerancia, raiz, a, b;
    int puntos=16;
    cabecera();
    cout<<"Ingrese el intervalo minimo para tabulación"<<endl;
    cin>>min;
    cout<<"Ingrese el intervalo máximo para tabulación"<<endl;
    cin>>max;
    ancho=(max-min)/intervalos;
    cout<<endl;
    inter:
    system("cls");
    cabecera();
    gotoxy(0,9);
    cout << "\t         x\t\tf(x)=x^3+2x^2+10x-20"<<endl;
    for (int i = 0; i < puntos; i++)
    {
        gotoxy(9,11+i);
        cout<<"\t"<<min;
        gotoxy(30,11+i);
        cout<<f(min)<<endl;
        min+=ancho;
    }
    gotoxy(43,14);
    cout<<"escoja el intervalo a analizar"<<endl;
    gotoxy(43,15);
    cout<<"Ingrese el primer valor de x"<<endl;
    gotoxy(43,16);
    cin>>a;
    gotoxy(43,17);
    cout<<"Ingrese el segundo valor de x"<<endl;
    gotoxy(43,18);
    cin>>max;
    if (f(a) * f(b) > 0)
    {
        gotoxy(43,20);
        cout<<"No se puede aplicar el metodo de bisección";
        gotoxy(43,21);
        cout<<"f("<<a<<") y f("<<b<<") tienen el mismo signo";
        system("pause");
    }else
    {
        gotoxy(43,20);
        cout<<"¿cuanta es la tolerancia de error que desea para los cálculos?"<<endl;
        gotoxy(43,21);
        cin>>tolerancia;
        gotoxy(43,23);
        cout<<"a\tb\tx\tf(a)\t\tf(b)\t\tf(x)"<<endl;
        int contador=0;
        do
        {
            raiz=(a+b)/2;
            gotoxy(43,25+contador);
            cout<<a;
            gotoxy(47,25+contador);
            cout<<b;
            gotoxy(49,25+contador);
            cout<<raiz;
            gotoxy(51,25+contador);
            cout<<f(a);
            gotoxy(55,25+contador);
            cout<<f(b);
            gotoxy(62,25+contador);
            cout<<f(raiz);
            if (abs(f(raiz))<=tolerancia)
            {
                gotoxy(43,25+contador);
                cout<<"Para una tolerancia "<<tolerancia<<" la raiz de f es "<<raiz<<endl;
                break;
            }else{
                if (f(raiz)*f(a)>0)
                {
                    a=raiz;
                }else if (f(raiz)*f(a)>0)
                {
                    b=raiz;
                }
            }
            contador++;
        } while (1);
    }
    system("pause");
}
double f(double x) 
{
   return pow(x,3)+(2*pow(x,2))+10*x-20;
}
