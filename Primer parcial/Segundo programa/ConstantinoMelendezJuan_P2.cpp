#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
    float funcion, Xi, Xd, Xm, iteraciones, aux, error;
    cout << "Practica 2: Metodo de biseccion" << endl;
    cout << "Funcion a evualuar x^3+2x^2+10x-20" << endl;
    cout << "Ingresa el valor de Xi:" << endl;
    cin >> Xi;
    cout << "Ingresa el valor de Xd:" << endl;
    cin >> Xd;
    system("pause");
    iteraciones = abs(log(Xd - Xi) - log(0.001)) / log(2);

    for (int i = 1; i < iteraciones + 1; i++)
    {
        cout << "_______________________________________________" << endl;
        cout << "#iteracion [" << i << "]" << endl;
        cout << "El valor de Xi= " << Xi << endl;
        cout << "El valor de Xd= " << Xd << endl;
        Xm = (Xi + Xd) / 2; // formula del valor medio//
        cout << "El valor de Xm= " << Xm << endl;
        funcion = pow(Xm, 3) + (2 * pow(Xm, 2)) + (10 * Xm) - 20; //cambiar para evaluar otras funciones //
        cout << "El valor de f(Xm)= " << funcion << endl;
        error = abs(Xm - aux); //sacamos el error para ver saber si es menor a 0.001 y detener las iteraciones//
        cout << "El error es: " << error << endl;
        if (funcion > 0)
        {
            Xd = Xm;
            cout << "El nuevo valir de Xd es : " << Xd << endl;
        }
        if (funcion < 0)
        {
            Xi = Xm;
            cout << "El nuevo valir de Xi es : " << Xi << endl;
        }
        cout << "_______________________________________________" << endl;
        aux = Xm;          // guardamos el valor de Xm de la iteracion anterior
        if (error < 0.001) //si el error es menor a 0.001 se detiene el programa
        {
            break;
        }
    }
    getch();
    return 0;
}