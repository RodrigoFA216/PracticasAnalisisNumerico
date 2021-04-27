#include <iostream>
#include <cmath>

using namespace std;

float xi, xf, fxi, fxf, xm, xa;

float funcion(float x)
{
    return pow(x, 3) + 2 * (pow(x, 2)) + 10 * x - 20;
}

int main()
{
    cout << "metodo de posicion falsa" << endl;
    cout << "ingresa xi y xf" << endl;
    cin >> xi >> xf;
    cout << "\n\n";
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    do
    {
        xm = xf - funcion(xf) * ((xf - xi) / (funcion(xf) - funcion(xi)));
        cout << "xi\t\t"
             << "xf\t\t"
             << "xm\t\t"
             << "f(xi)\t\t"
             << "f(xf)\t\t"
             << "f(xm)\t\t" << endl;
        cout << xi << "\t\t" << xf << "\t\t" << xm << "\t\t" << funcion(xi) << "\t\t" << funcion(xf) << "\t\t" << funcion(xm) << endl
             << endl;

        if (fabs(xm - xa) / fabs(xm) <= 0.001)
        {
            cout << "\n\nPara una tolerancia de " << 0.001 << " la raiz de f es: " << xm << endl;
            break;
        }
        else
        {
            xa = xm;
            if (funcion(xm) * funcion(xi) > 0)
            {
                xi = xm;
            }
            else if (funcion(xm) * funcion(xf) > 0)
            {
                xf = xm;
            }
        }

    } while (1);
}