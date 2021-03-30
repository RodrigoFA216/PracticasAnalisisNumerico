#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int it, j = 0;
    float gdx, xi, error, aux;
    cout << "Despeje a evaluar x=((x+5)/2)^(1/2)" << endl;
    cout << "Con que valor de X desea iniciar?: ";
    cin >> xi;
    cout << endl;

    for (int i = j; i <= it + 1; i++)
    {
        j++;
        aux = xi;
        gdx = sqrt((xi + 5) / 2);
        xi = gdx;
        cout << "#iteracion " << i << endl;
        cout << "xi=" << aux << "   ";
        cout << "g(x)= " << gdx << endl;
        cout << "El error es " << error << endl
             << endl;
        error = abs(xi - aux);
        if (error < 0.0001)
        {
            break;
        }
    }
    system("pause");
}
