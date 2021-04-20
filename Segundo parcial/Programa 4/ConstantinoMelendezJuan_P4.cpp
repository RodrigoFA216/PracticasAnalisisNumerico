#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
    float error, epsilon, Xo, Xi;
    cout << "Metodo de Newton-Raphson" << endl;
    cout << "funcion a evaluar: x^3+2x^2+10x-20\nFuncion derivada: 3x^2+4x+10" << endl;
    cout << "Ingresa el valir de Xo" << endl;
    cin >> Xo;
    cout << "Error aproximado" << endl;
    cin >> epsilon;

    for (int i = 1; i < 100; i++)
    {
        cout << "Iteracion#" << i << endl;
        Xi = Xo - ((pow(Xo, 3) + (2 * pow(Xo, 2) + (10 * Xo) - 20)) / ((3 * pow(Xo, 2) + (4 * Xo) + 10)));
        error = abs(Xi - Xo);
        Xo = Xi;
        cout << Xo << endl;
        if (error < epsilon)
        {
            break;
        }
    }
    getch();
    return 0;
}