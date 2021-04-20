#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()

{

    float xi, xo, error, epsilon, op;

    cout << "Metodo de la secante" << endl;
    cout << "Ingresa xi" << endl;
    cin >> xi;
    cout << "ingresa xo" << endl;
    cin >> xo;
    cout << "ingresa e" << endl;
    cin >> epsilon;

    for (int i = 1; i < 100; i++)
    {
        cout << "\nIteracion[" << i << "]\n";
        op = xi - ((xi - xo) * (pow(xi, 3) + (2 * pow(xi, 2)) + (10 * xi) - 20)) / ((pow(xi, 3) + (2 * pow(xi, 2)) + (10 * xi) - 20) - (pow(xo, 3) + (2 * pow(xo, 2)) + (10 * xo) - 20));
        error = abs(op - xi);
        cout << "Resultado: " << op;
        cout << "\nError es: " << error;
        cout << "\n---------------------------------\n";
        xo = xi;
        xi = op;

        if (error < epsilon)
        {
            break;
        }
    }
}