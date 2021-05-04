/* METODO DE LA MATRIZ INVERSA 
RODRIGUEZ ORTIZ NELLY ITZEL
* ANALISIS NUMERICO
* 4CM11
* 30 DE ABRIL DE 2021
*/

#include <iostream>
#include <math.h>
#include <windows.h>

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

using namespace std;

int main() {

	double matriz[50][50];
	double identidad[50][50];
	int N,num_inc, i, j, k, x, y, opc;
    double incog[100], aux0, pivote;

    int op = 0;
    do {
        cout << "\n\t  **  SISTEMAS DE ECUACIONES. METODO DE LA MATRIZ INVERSA**\n\n";
        cout << "\t\t\t  **  NELLY ITZEL RODRIGUEZ ORTIZ  **\n";
        cout << "\n\nINGRESE EL NUMERO DE INCOGNITAS DEL SISTEMA DE ECUACIONES A RESOLVER:  ";
        cin >> num_inc;
        cout << "\n  INGRESE EL VALOR DE LOS COEFICIENTES DE CADA INCOGNITA EN FORMA DE MATRIZ [FILA,COLUMNA]\n\n";

        //LLENADO MATRIZ DEL SISTEMA DE ECUACIONES
        for (i = 0; i < num_inc; i++)
        {
            for (j = 0; j < num_inc + 1; j++)
            {
                cout << " INGRESE EL VALOR DE [ " << i + 1 << " , " << j + 1 << " ]: ";
                cin >> k;
                matriz[i][j] = k;
            }
            cout << "\n";
        }
        //LLENADO DE MATRIZ IDENTIDAD
        for (i = 0; i < num_inc; i++)
        {
            for (j = 0; j < num_inc; j++)
            {
                identidad[i][j] = 0;
                if (i == j) {
                    identidad[i][j] = 1;
                }
            }
            cout << "\n";
        }
        system("cls");
        //MOSTRAR MATRIZ
        cout << "\n\n  EL SISTEMA DE ECUACIONES REPRESENTADO EN MATRIZ ES:  \n\n";
        for (i = 0; i < num_inc; i++)
        {
            for (j = 0; j < num_inc + 1; j++)
            {
                if (j == num_inc) {
                    gotoxy(j * 5, i + 3);
                    cout << " | ";
                    cout << matriz[i][j] << " ";
                    cout << " | ";
                }
                else {
                    gotoxy(j * 5, i + 3);
                    cout << " " << matriz[i][j] << " ";
                }

            }
            gotoxy(j * 5, i + 3);
            cout << "\n";
        }
        //MOSTRAR MATRIZ IDENTIDAD
        for (i = 0; i < num_inc; i++)
        {
            gotoxy(50 + j * 5, i + 3);
            for (j = 0; j < num_inc; j++)
            {
                if (j == num_inc) {
                    gotoxy(50 + j * 5, i + 3);
                    cout << identidad[i][j] << " ";

                }
                else {
                    gotoxy(50 + j * 5, i + 3);
                    cout << " " << identidad[i][j] << " ";
                }

            }
            cout << "\n";
        }

        system("pause");

        //REDUCCION POR RENGLONES
        for (i = 0; i < num_inc; i++) {
            pivote = matriz[i][i];
            //convertir el pivote a 1 y aplicar a toda la linea
            for (k = 0; k < num_inc + 1; k++) {
                matriz[i][k] = matriz[i][k] / pivote;
                identidad[i][k] = identidad[i][k] / pivote;
            }
            for (j = 0; j < num_inc; j++) {
                if (i != j) {
                    aux0 = matriz[j][i];
                    for (k = 0; k < num_inc + 1; k++) {
                        matriz[j][k] = matriz[j][k] - aux0 * matriz[i][k];
                        identidad[j][k] = identidad[j][k] - aux0 * identidad[i][k];
                    }
                }
            }
        }
        system("cls");
        cout << "\n\nLA RESOLUCION DE LA MATRIZ ES:" << endl;
        x = 0;
        for (i = 0; i < num_inc; i++)
        {
            for (j = 0; j < num_inc + 1; j++)
            {
                if (j == num_inc) {
                    cout << " | " << matriz[i][j] << " ";
                    incog[x] = matriz[i][j];
                    x++;
                }
                else {
                    cout << " " << matriz[i][j] << " ";
                }

            }
            cout << "\n";
        }
        //MOSTRAR LA MATRIZ INVERSA
        for (i = 0; i < num_inc; i++)
        {
            for (j = 0; j < num_inc; j++)
            {
                if (j == num_inc) {
                    gotoxy(50 + j * 10, i + 3);
                    cout << identidad[i][j] << " ";

                }
                else {
                    gotoxy(50 + j * 10, i + 3);
                    cout << " " << identidad[i][j] << " ";
                }
            }
            cout << "\n";
        }

        cout << "\n LA SOLUCION DE LAS INCOGNITAS SON:  ";
        for (i = num_inc; i > 0; i--)
        {
            cout << "\n  INCOGNITA x" << i << " : " << incog[num_inc - i];
        }
        cout << "\n\n";
        system("pause");
    cout << "\nDESEA PERMANECER EN EL PROGRAMA (1.SI / 2.NO): ";
    cin >> op;
    }while (op != 2);
}

