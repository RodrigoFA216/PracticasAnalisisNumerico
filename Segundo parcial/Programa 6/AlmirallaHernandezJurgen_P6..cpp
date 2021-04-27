#include <iostream>
using namespace std;

float funcion(float x)
{
    return pow(x, 3) + 2 * (pow(x, 2)) + 10 * x - 20;
}

int main()
{
    float xi, xf, fxi, fxf, xm, xa;
    
    cout << "------Metodo de posicion falsa-----";
    cout << "ingresa xi y xf";
    cin >> xi >> xf;
    cout << "\n\n";
    
    do
    {
        xm = xf - funcion(xf) * ((xf - xi) / (funcion(xf) - funcion(xi)));
        cout << "xi\t\t"
             << "xf\t\t"
             << "xm\t\t"
             << "f(xi)\t\t"
             << "f(xf)\t\t"
             << "f(xm)\t\t";
        cout << xi << "\t\t" << xf << "\t\t" << xm << "\t\t" << funcion(xi) << "\t\t" << funcion(xf) << "\t\t" << funcion(xm);
             

        if (fabs(xm - xa) / fabs(xm) <= 0.001)
        {
            cout << "\n\nPara una tolerancia de " << 0.001 << " la raiz de f es: " << xm;
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