#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
    int n, x, y, i, j, a;
    float z, w ,A[n][n],B[n][n],C[n],auxa[n],auxb[n];
  


    cout<<"Tamano de la matrix: ";
    cin >> n;

   

    for (x = 0; x < n; x++)
    { 
        auxa[x] = 0;
        auxb[x] = 0;
    }
    for (x = 0; x < n; x++)
    { 
        for (y = 0; y < n; y++)
        {
            B[x][y] = 0;
        }
        B[x][x] = 1;
    }

    for (x = 0; x < n; x++)
    { 
        cout << "Ingrese los datos:  ";
        for (y = 0; y < n; y++)
        {
            cin >> A[x][y];
        }
    }
    cout << "Ingrese los resultados: ";
    for (x = 0; x < n; x++)
    { 
        cin >> C[x];
    }
    cout << "Matriz inversa: ";
    for (x = 0; x < n; x++)
    { 
        for (y = 0; y < n; y++)
        {
            cout << A[x][y] << "\t";
        }
        cout << " | " << C[x];
        cout << endl;
    }
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
            A[x][y] = A[x][y] / z; 
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

    cout << "Matriz inversa: ";
    for (x = 0; x < n; x++)
    { 
        for (y = 0; y < n; y++)
        {
            cout << B[x][y] << "\t";
        }
        cout << endl
             << "\n";
    }
    cout <<"Final: ";
    for (x = 0; x < n; x++)
    {
        w = 0;
        for (y = 0; y < n; y++)
        {
            w = w + (C[y] * B[x][y]);
        }
        cout<<" X"<<x<<" = "<<w;
    }
}