#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int op, it, i;

    float x, gx, aux,r;

    cout << "PUNTO FIJO\n\n";
    cout << "Funcion a evaluar\n"
         << "2x^2-x-5\n"
         << "\n";

    cout << "Con que despeje desea trabajar\n\n"
         << "1)x=2x^2-5\n"
         << "2)5/(2x-1)\n"
         << "3)RAIZ CUADRADA DE((x+5)/2)\n";
    cin >> op;

    switch (op)
    {

    case 1:

        cout << "1)x=2x^2-5\n\n";
        cout << "Cuantas iteraciones quiere hacer?: ";
        cin >> it;
        cout << "Con que valor de X desea iniciar?: ";
        cin >> x;

        for (i = 0; i <= it; i++)
        {
            aux = x;
            gx = pow(2 * x, 2) - 5;

            cout << "-------------------------";
            cout << "ITERACION #" << i
                 << "\n"
                 << "XI=" << aux
                 << "\n"
                 << "g(x)=" << gx
                 << "\n";
                 cout<<"El error es de: "<<r;
                  cout<<"\n";
            r=abs(x-aux);
            x = gx;
        }
        break;

    case 2:

        cout << "2)5/(2x-1)\n\n";

        cout << "Cuantas iteraciones quiere hacer?: ";
        cin >> it;
        cout << "Con que valor de X desea iniciar?: ";
        cin >> x;

        for (i = 0; i <= it; i++)
        {
            aux = x;
            gx = 5 / ((2 * x) - 5);

            cout << "-------------------------";
            cout << "ITERACION #" << i
                 << "\n"
                 << "XI=" << aux
                 << "\n"
                 << "g(x)=" << gx
                 << "\n";
                 cout<<"El error es de: "<<r;
                  cout<<"\n";
            r=abs(x-aux);
            x = gx;
        }
        break;

    case 3:

        cout << "3)x=RAIZ CUADRADA DE((x+5)/2)\n\n";

        cout << "Cuantas iteraciones quiere hacer?: ";
        cin >> it;
        cout << "Con que valor de X desea iniciar?: ";
        cin >> x;

        for (i = 0; i <= it; i++)
        {

            aux = x;
            gx = sqrt((x + 5) / 2);
            cout << "-------------------------";
            cout << "ITERACION #" << i
                 << "\n"
                 << "XI=" << aux
                 << "\n"
                 << "g(x)=" << gx
                 << "\n";
            cout<<"El error es de: "<<r;
            cout<<"\n";

            x = gx;
            r=abs(x-aux);
        }
        break;
    }
}