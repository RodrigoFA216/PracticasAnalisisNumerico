#include <iostream>
#include <stdlib.h>
using namespace std;
main()
{
    int tamaño, a, b, i, j, k;
    float MAtriz1[10][10], Terminos[10], cte, aux;
    cout << "\ningrese de que dimensio es su matriz: \n";
    cin >> tamaño;
    cout << "ingresa los datos" << endl;
    for (a = 0; a < tamaño; a++)
    {
        for (b = 0; b < tamaño; b++)
        {
            cout << a + 1 << b + 1 << endl;
            cin >> MAtriz1[a][b];
        }
        cout << "TIngresa el primer termino " << a + 1 << endl;
        cin >> Terminos[a];
    }
    for (i = 0; i < tamaño; i++)
    {
        if (MAtriz1[i][i] == 0)
        {
            for (int s = i + 1; s <= tamaño + 1; s++)
            {
                if (MAtriz1[s][i] != 0)
                {
                    aux = MAtriz1[i][s - 1];
                    MAtriz1[i][s - 1] = MAtriz1[i + 1][s - 1];
                    MAtriz1[i + 1][s - 1] = aux;
                    aux = Terminos[i];
                    Terminos[i] = Terminos[i + 1];
                    Terminos[i + 1] = aux;
                }
            }
        }
        for (j = i + 1; j < tamaño; j++)
        {
            cte = MAtriz1[j][i] / MAtriz1[i][i];
            for (k = i; k < tamaño; k++)
            {
                MAtriz1[j][k] = MAtriz1[j][k] - cte * MAtriz1[i][k];
            }
            Terminos[j] = Terminos[j] - cte * Terminos[i];
        }
    }

    float suma = 0, x[10];

    cout << "\nlos resultados son\n";
    x[tamaño - 1] = Terminos[tamaño - 1] / MAtriz1[tamaño - 1][tamaño - 1];
    cout << "x [" << i << "]"
         << "= " << x[tamaño - 1];
    for (int z = tamaño - 2; z >= 0; z--)
    {
        suma = 0;
        for (int y = z + 1; y < tamaño; y++)
        {
            suma = suma + MAtriz1[z][y] * x[y];
        }
        x[z] = (Terminos[z] - suma) / MAtriz1[z][z];
        cout << "\nx[" << z + 1 << "] = " << x[z];
    }

    system("pause");
}