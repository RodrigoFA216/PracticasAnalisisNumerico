#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int repeticiones;
    float funcion, val_incial, bacukp, error;
    cout << "funcion principal f(x)= 2x^2-x-5" << endl;
    cout << "Despeje a evaluar x=((x+5)/2)^(1/2)" << endl;
    cout << "Con que valor de X desea iniciar?: ";
    cin >> val_incial;
    cout << "Cuantas iteracion quieres" << endl;
    cin >> repeticiones;

    for (int i = 0; i < repeticiones; i++)
    {
        bacukp = val_incial;
        funcion = sqrt((val_incial + 5) / 2);
        val_incial = funcion;
        cout << "[" << i << "]"
             << " xi=" << bacukp;
        cout << "\tg(x)= " << funcion << "El error es " << error << endl;
        error = abs(val_incial - bacukp);
    }
}