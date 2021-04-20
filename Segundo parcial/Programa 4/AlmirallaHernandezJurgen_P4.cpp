#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
    float er, e, xo, xi;
    cout << "\t\tMetodo de Newton-Raphson";
    cout << "\n\nFuncion a evaluar: x^3+2x^2+10x-20"
         <<"\nFuncion derivada: 3x^2+4x+10";
    cout << "\n\nIngresa el valir de Xo: ";
    cin >> xo;
    cout << "\nError aproximado: ";
    cin >> e;

    for (int i = 1; i < 100; i++)
    {

        xi = xo - ((pow(xo, 3) + (2 * pow(xo, 2) + (10 * xo) - 20)) / ((3 * pow(xo, 2) + (4 * xo) + 10)));
        er = abs(xi - xo);
        xo = xi;

        cout <<"\nIteracion----------#" <<i<<"\n";
        cout << xo;
        
        
        
        if (er < e)
        {
            break;
        }
    }

   
}