#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int i, j, k, NumeroDeEcuaciones;
    float a[10][10]={0}, d;
    cout << "Numero de ecuaciones ";
    cin >> NumeroDeEcuaciones;
    cout << "Read all coefficients of matrix with b matrix too " << endl;
    for (i = 1; i <= NumeroDeEcuaciones; i++)
        for (j=1; j<=NumeroDeEcuaciones; j++)
            cin >> a[i][j];
    for (i=1;i<=NumeroDeEcuaciones;i++)
        for (j=1; j<=2*NumeroDeEcuaciones; j++)
            if (j==(i+NumeroDeEcuaciones))
                a[i][j] = 1;
///////////////////////////////////////////////////////////////////
    for (i=NumeroDeEcuaciones; i>1; i--){
            if (a[i-1][1]<a[i][1])
                for(j=1; j<=NumeroDeEcuaciones*2; j++){
                        d=a[i][j];
                        a[i][j]=a[i-1][j];
                        a[i-1][j]=d;
                    }
        }
    cout << "pivoted output: " << endl;
    for(i=1; i<=NumeroDeEcuaciones; i++){
            for (j=1; j<=NumeroDeEcuaciones*2; j++)
                cout << a[i][j] << "    ";
            cout << endl;
        }
///////////////////////////////////////////////////////////////////
    for (i=1; i<=NumeroDeEcuaciones; i++){
            for (j=1; j<=NumeroDeEcuaciones*2; j++)
                if (j!=i){
                        d=a[j][i]/a[i][i];
                        for (k=1; k<=NumeroDeEcuaciones*2; k++)
                            a[j][k]-=a[i][k]*d;
                    }
        }
///////////////////////////////////////////////////////////////////
    for (i=1; i<=NumeroDeEcuaciones;i++)
        {
            d = a[i][i];
            for (j=1; j<=NumeroDeEcuaciones*2; j++)
                a[i][j] = a[i][j]/d;
        }
    cout << "your solutions: " << endl;
    for (i=1; i<=NumeroDeEcuaciones; i++){
            for (j=NumeroDeEcuaciones+1; j<=NumeroDeEcuaciones*2; j++)
                cout<<a[i][j]<<"    ";
            cout<<endl;
        }
    getch();
    return 0;
}
