#include <iostream>
#include <cmath>

using namespace std;

float fun(float x);

int main()
{

    float IntI, IntF, valorI, valorF, Xm, xant;

    cout << "ingresa el valor de Xi" << endl;
    cin >> IntI;
    cout << "Ingresa el valor de Xf" << endl;
    cin >> IntF;
    cout << "ingresa el valor de f(xi)" << endl;
    cin >> valorI;
    cout << "ingresa el valor de f(xf)" << endl;
    cin >> valorF;

    for (int i = 0; i < 100; i++)
    {

        Xm = IntF - valorF * ((IntF - IntI) / (valorF - valorI));
        cout << IntI << "\t\t" << IntF << "\t\t" << Xm << "\t\t" << fun(IntI) << "\t\t" << fun(IntF) << "\t\t" << fun(Xm) << endl
             << endl;
        if (abs(Xm - xant) <= 0.001)
        {
            break;
        }
        else
        {
            xant = Xm;
            if (fun(Xm) < 0)
            {
                IntI = Xm;
            }
            else
            {
                IntF = Xm;
            }
        }
    }
}

float fun(float x)
{
    return pow(x, 3) + 2 * (pow(x, 2)) + 10 * x - 20;
}