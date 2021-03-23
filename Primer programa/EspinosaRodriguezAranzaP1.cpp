#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void ErrorP(float valorBefore, float valorNow)
{
    float resultado;

    resultado = ((valorNow - valorBefore) / valorNow) * 100;
    cout << "El error% es :" << resultado << "%" << endl;
}

float operacion(float x, float it)
{
    float po, fac, ope;

    po = pow(x, it);
    fac = 1;
    for (int j = it; j >= 1; j--)
    {
        fac = fac * j;
    }
    ope = po / fac;

    return ope;
}
int main()
{
    float x, iteracion, valor, valoraprox, dato, ErrorPorcentual;

    cout << "Cuantas iteraciones vas a querer" << endl;
    cin >> iteracion;
    cout << "Cual es el valor que tendra x: " << endl;
    cin >> x;

    valor = pow(2.7182, x);
    cout << "    El valor de e^x es: " << valor << endl;
    cout << "_________________________________________________|" << endl;

    for (int i = 1; i < iteracion + 1; i++)
    {
        switch (i)
        {
        case 1:
            valoraprox = 1;
            cout << "    El valor aproximado es: " << valoraprox
                 << endl;
            cout << "_________________________________________________|" << endl;
            break;

        case 2:
            valoraprox = 1 + x;
            cout << "    El valor aproximado es: " << valoraprox << endl;
            cout << "    ";
            ErrorP(ErrorPorcentual, valoraprox);
            cout << "_________________________________________________|" << endl;
            break;

        default:
            valoraprox = operacion(x, i - 1);
            valoraprox = dato + valoraprox;
            cout << "    El valor aproximado es: " << valoraprox << endl;
            cout << "    ";
            ErrorP(ErrorPorcentual, valoraprox);
            cout << "_________________________________________________|" << endl;
            break;
        }
        dato = valoraprox;
        ErrorPorcentual = valoraprox;
    }
}
