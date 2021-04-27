#include <iostream>
using namespace std;
const int N = 3;
int main(){
    double array[N][N], det = 1;
    cout << "mete la matriz de "<<N<<"*"<<N<<endl;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j){
            cin >> array[i][j];
        }
    }

    for (int i=0; i<N; ++i){
        bool flag = false;
        if (array[i][i] == 0){
            flag=true;
            for (int j=i; j<N; ++j){
                if (array[j][i]!= 0){
                    det*=-1;
                    for (int k=0; k<N; ++k){ 
                        double t=array[i][k];
                        array[i][k]=array[j][k];
                        array[j][k]=t;
                        flag=false;
                    }
                }
            }
        }
        if(flag==true){
            det=0;
            break;
        }
        else{
            for(int j=i+1; j<N; ++j){
                double store=array[j][i];
                for(int k=i; k<N; ++k){
                    array[j][k] -= (array[i][k]*store)/array[i][i];
                } 
            }
            det *= array[i][i];
        }
    }
    cout<<"Determinante: "<<det;
    return 0;
}
