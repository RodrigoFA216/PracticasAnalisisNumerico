#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
#define N 100

float funcion(float a, float b)
{
    float evaluacion;
    evaluacion = a - ((a - b) * (pow(a, 3) + (2 * pow(a, 2)) + (10 * a) - 20)) / ((pow(a, 3) + (2 * pow(a, 2)) + (10 * a) - 20) - (pow(b, 3) + (2 * pow(b, 2)) + (10 * b) - 20));
    return evaluacion;
}

int main()
{
    float VAl1, VAl2, error, evaluacion;
    cout << "Metodo de la secante" << endl;
    cout << "Ingresa Xi" << endl;
    cin >> VAl1;
    cout << "ingresa Xo" << endl;
    cin >> VAl2;

    for (int i = 1; i < N; i++)

    {
        cout << "\nIteracion[" << i << "]\n";
        evaluacion = funcion(VAl1, VAl2);
        error = abs(evaluacion - VAl1);
        cout << "\nResultado: " << evaluacion;
        cout << "\nError es: " << error;
        VAl2 = VAl1;
        VAl1 = evaluacion;

        if (error < 0.001)
        {
            break;
        }
    }
}