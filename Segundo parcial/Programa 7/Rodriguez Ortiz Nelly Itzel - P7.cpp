/*METODO DE GAUSS
RODRIGUEZ ORTIZ NELLY ITZEL
ANALISIS NUMERICO
4CM11
26 DE ABRIL DE 2021*/
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <conio.h>

using namespace std;



double matriz[50][50];
double identidad[50][50];
int N,
num_inc, i, j, k, x, y, opc;
double  recu[1][101], incog[100], aux0, aux1, aux2, ayuda, pivote;

int main(){
    int op=0;
    do {
    cout << "\n\t  **  SISTEMAS DE ECUACIONES. METODO DE GAUSS  / METODO DE GAUSS-JORDAN**\n\n";
    cout << "\t\t\t  **  NELLY ITZEL RODRIGUEZ ORTIZ  **\n";
    cout << "\n\nINGRESE EL NUMERO DE INCOGNITAS DEL SISTEMA DE ECUACIONES A RESOLVER:  ";
    cin >> num_inc;
 
    cout << "\n  INGRESE EL VALOR DE LOS COEFICIENTES DE CADA INCOGNITA EN FORMA DE MATRIZ [FILA,COLUMNA]\n\n";
    for(i=0;i<num_inc;i++)
    {
        for(j=0;j<num_inc+1;j++)
        {
            cout << " INGRESE EL VALOR DE [ "<<i+1<<" , "<<j+1<<" ]: ";
            cin >> k;
            matriz[i][j] = k;
        }
        cout << "\n";
    }
    cout << "\n\n  EL SISTEMA DE ECUACIONES REPRESENTADO EN MATRIZ ES:  \n\n";
    for(i=0;i<num_inc;i++)
    {
        cout << " | ";
        for (j = 0; j < num_inc + 1; j++)
        {
            if (j == num_inc) {
                cout << " | " << matriz[i][j] << " ";
            }
            else {
                cout << " " << matriz[i][j] << " ";
            }

        }
        cout << " | ";
        cout << "\n";
    }
    cout << "\nPOR QUE METODO DESEA RESOLVERLO (1. METODO DE GAUSS / 2. METODO DE GAUSS-JORDAN): ";
    cin >> opc;
    switch(opc){
    case 1://METODO DE GAUSS
        for (i = 0; i < num_inc - 1; i++)
        {
            aux1 = matriz[i][i];
            for (j = i + 1; j < num_inc; j++)
            {
                aux2 = matriz[j][i];
                for (k = i; k < num_inc + 1; k++)
                {
                    aux0 = matriz[i][k];
                    recu[0][k] = aux0;
                    aux0 = aux0 * aux2 * (-1);
                    matriz[i][k] = aux0;
                    aux0 = matriz[j][k];
                    aux0 = aux0 * aux1 * 1;
                    matriz[j][k] = aux0;
                }
                for (y = 0; y < num_inc + 1; y++)
                {
                    aux0 = matriz[i][y] + matriz[j][y];
                    matriz[j][y] = aux0;
                }
                for (x = i; x < num_inc + 1; x++)
                {
                    aux0 = recu[0][x];
                    matriz[i][x] = aux0;
                }
            }
        }
        cout << "\n\n  EL SISTEMA CON TRIANGULO INFERIOR QUEDARIA ASI:  \n\n";
        for (i = 0; i < num_inc; i++)
        {
            cout << " | ";
            for (j = 0; j < num_inc + 1; j++)
            {
                if ( j == num_inc) {
                    cout << " | " << matriz[i][j] << " ";
                }
                else {
                    cout << " "<<matriz[i][j]<<" ";
                }
                
            }
            cout << " | ";
            cout << "\n";
        }
        k = 1;
        x = 0;
        for (i = num_inc - 1; i >= 0; i--)
        {
            aux0 = matriz[i][i];
            aux1 = matriz[i][i + k];
            if (k == 1)
            {
                aux2 = aux1 / aux0;
                incog[x] = aux2;
                for (j = num_inc - 1; j >= 0; j--)
                {
                    ayuda = matriz[j][num_inc - k];
                    ayuda = ayuda * aux2;
                    matriz[j][num_inc - k] = ayuda;
                }
                k++;
                x++;
            }
            else
            {
                for (y = i + 1; y < num_inc; y++)
                {
                    ayuda = matriz[i][y];
                    aux1 = aux1 - ayuda;
                }
                aux2 = aux1 / aux0;
                incog[x] = aux2;
                for (j = i; j >= 0; j--)
                {
                    ayuda = matriz[j][num_inc - k];
                    ayuda = ayuda * aux2;
                    matriz[j][num_inc - k] = ayuda;
                }
                k++;
                x++;
            }
        }
        cout << "\n LA SOLUCION DE LAS INCOGNITAS SON:  ";
        for (i = 0; i < num_inc; i++)
        {
            cout << "\n  INCOGNITA x" << i + 1 << " : " << incog[num_inc - i - 1];
        }
        system("pause");
        break;
    case 2:
        //REDUCCION POR RENGLONES
        for (i = 0; i < num_inc; i++) {
            pivote = matriz[i][i];
            //convertir el pivote a 1 y aplicar a toda la linea
            for(k=0;k<num_inc+1;k++){
                matriz[i][k] = matriz[i][k] / pivote;
            }
            for (j = 0; j < num_inc; j++) {
                if (i != j) {
                    aux0 = matriz[j][i];
                    for (k = 0; k < num_inc+1; k++) {
                        matriz[j][k] = matriz[j][k] - aux0 * matriz[i][k];
                    }
                }
            }
        }
        x = 0;
        for (i = 0; i < num_inc; i++)
        {
            cout << " | ";
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
            cout << " | ";
            cout << "\n";
        }
        cout << "\n LA SOLUCION DE LAS INCOGNITAS SON:  ";
        for (i = num_inc; i > 0; i--)
        {
            cout << "\n  INCOGNITA x" << i<< " : " << incog[num_inc - i];
        }
        system("pause");
        break;
    }
    cout << "\nDESEA PERMANECER EN EL PROGRAMA (1.SI / 2.NO): ";
    cin >> op;
    }while (op != 2);
    
}

