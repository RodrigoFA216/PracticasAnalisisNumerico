#include <iostream>
#include <iomanip>
 
using namespace std;
 
void LeerMatriz( float **M, int fil, int col ){
 
    cout << "\nDatos de la matriz:\n";
    for( int i = 0; i < fil; i++ ){
        cout << "Fila: " << i + 1 << "\n";
        for( int j = 0; j < col; j++ ){
            cout << "Columna " << j + 1 << ": ";
            cin >> M[i][j];
        }
    }
}
 
const void ImprimirFase( float **M, int fil, int col ){
 
    cout << "\n\n";
    for( int i = 0; i < fil; i++ ){
        for( int j = 0; j < col; j++ ){
            cout << setprecision(2) << fixed << setw(6)
                 << M[i][j] << " ";
        }
        cout << "\n";
    }
}
 
void Gauss( float **M, int fil, int col ){
 
    int k = 0;
    float temp;
 
    while( k < col - 1 ){
        for( int i = k; i < fil; i++ ){
            for( int j = col - 1; j >= k; j-- ){
                if( i == k ){
                    temp = 1 / M[k][k];
                    M[i][j] = temp * M[i][j];
                }
                if( i > k ){
                    temp = (-M[i][k]);
                    M[i][j] = ( temp * (M[k][j])) + M[i][j];
                }
            }
        }
        k++;
    }
    cout << "\nFase 1:";
    ImprimirFase( M, fil, col);
 
    for( int i = 0; i < fil - 1; i++ ){
        for( int j = col - 1; j >= col - 2; j-- ){
            temp = (-M[i][col - 2]);
            M[i][j] = (temp * M[fil - 1][j])+ M[i][j];
        }
    }
    cout << "\nFase 2:";
    ImprimirFase( M, fil, col);
 
    k = 0;
    int c = 1;
    while( k < col - 1 ){
        for( int i = k; i < fil - 2; i++ ){
            for( int j = col - 1; j >= k + c; j-- ){
                temp = (-M[i][k + c]);
                M[i][j] = temp * M[i + 1][j] + M[i][j];
            }
        }
        k++;
        c++;
    }
    cout << "\nFase 3:";
    ImprimirFase( M, fil, col );
 
}
 
const void ImprimirResultado( float **M, int fil, int col ){
 
    cout << "\nImprimir resultado:\n\n";
    for( int i = 0; i < fil; i++ ){
        cout << setprecision(0) << fixed << setw(3)
             << char(120 + i) << " = "
             << setw(3) << setiosflags( ios::right )
             << M[i][col - 1] << endl;
    }
}
 
int main(){
 
    int col, fil;
 
    cout << "# filas de la matriz: ";
    cin >> fil;
    cout << "# columnas de la matriz: ";
    cin >> col;
 
    float** M = new float*[fil];
    for( int i = 0; i < fil; i++ )
        M[i] = new float[col];
 
    LeerMatriz( M, fil, col );
 
    cout << "\nMatriz inicial:";
    ImprimirFase( M, fil, col );
 
    Gauss( M, fil, col );
    ImprimirResultado( M, fil, col );
 
    return 0;
}
