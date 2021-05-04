#include <iostream>
#include <conio.h>
#include <math.h>
#define n 3
using namespace std;
float A[n][n];
float B[n][n];
float C[n];
float auxa[n];
float auxb[n];

void matrizI()
{
    int x, y;
    for (x = 0; x < n; x++)
    { // CREA 0 en aux
        auxa[x] = 0;
        auxb[x] = 0;
    }
    for (x = 0; x < n; x++)
    { // lllena matriz identidad
        for (y = 0; y < n; y++)
        {
            B[x][y] = 0;
        }
        B[x][x] = 1;
    }
}

void Llenado()
{
    int x, y;
    for (x = 0; x < n; x++)
    { //llena matriz A
        cout << "Ingrese los elementos del renglon " << x + 1 << " De la matriz de coeficientes " << endl;
        for (y = 0; y < n; y++)
        {
            cin >> A[x][y];
        }
    }
    cout << "Ingrese los elementos de la matriz de resultados " << endl;
    for (x = 0; x < n; x++)
    { //llena matriz A
        cin >> C[x];
    }
    cout << "MATRIZ INGRESADA" << endl;
    for (x = 0; x < n; x++)
    { //MUESTRA LA MATRIZ INGRESADA
        for (y = 0; y < n; y++)
        {
            cout << A[x][y] << "\t";
        }
        cout << " | " << C[x];
        cout << endl;
    }
}

void inversa()
{
    int x, y;
    int i, z;
    int a, w, j;
    for (x = 0; x < n; x++)
    {
        if (A[x][x] == 0)
        {
            for (y = x; y < n; y++)
            {
                if (A[y][x] == 0)
                {
                }
                else
                {
                    for (a = 0; a < n; a++)
                    {
                        auxa[a] = A[y][a];
                        auxb[a] = B[y][a];
                        A[y][a] = A[x][a];
                        B[y][a] = B[x][a];
                        A[x][a] = auxa[a];
                        B[x][a] = auxb[a];
                    }
                }
            }
        }
    }
    for (x = 0; x < n; x++)
    {
        z = A[x][x];
        for (y = 0; y < n; y++)
        {
            A[x][y] = A[x][y] / z; // CONSIGUE EL 1 EN LA DIAGONAL
            B[x][y] = B[x][y] / z;
        }
        for (i = 0; i < n; i++)
        {
            if (i == x)
            {
            }
            else if (i != x)
            {
                w = A[i][x];
                for (j = 0; j < n; j++)
                {
                    A[i][j] = (A[i][j]) - (w * A[x][j]);
                    B[i][j] = (B[i][j]) - (w * B[x][j]);
                }
            }
        }
    }

    cout << "MATRIZ INVERSA" << endl;
    for (x = 0; x < n; x++)
    { //MUESTRA LA MATRIZ INVERSA
        for (y = 0; y < n; y++)
        {
            cout << B[x][y] << "\t";
        }
        cout << endl
             << "\n";
    }
    cout << "RESULTADOS" << endl;
    for (x = 0; x < n; x++)
    {
        w = 0;
        for (y = 0; y < n; y++)
        {
            w = w + (C[y] * B[x][y]);
        }
        cout << " X" << x << " = " << w << endl;
    }
}

int main()
{

    matrizI();
    Llenado();
    inversa();
    return 0;
}