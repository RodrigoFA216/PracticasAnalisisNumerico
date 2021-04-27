#include<iostream>
#include<cmath>
using namespace std;

void gauss_jordan(double M[20][20],int n){
    double may;
    int ind;
    double aux;
    double pivote;
    
    for(int k=0;k<n;k++){
        may=abs(M[k][k]);
        ind=k;
        
        for(int l=k+1;l<n;l++){
            if(may<abs(M[l][k])){
                may=abs(M[l][k]);
                ind=l;
            }
            
        }

        
        if(k!=ind){
            for(int i=0;i<n+1;i++){
                aux=M[k][i];
                M[k][i]=M[ind][i];
                M[ind][i]=aux;
            }
            
        }
        if(M[k][k]==0){
            cout<<"no tiene solucion";
            break;
        }
        else{
            
            for(int i=0;i<n;i++){
                if(i!=k){
                    pivote=-M[i][k];
                    for(int j=k;j<n+1;j++){

                        M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k];
                    }
                }
                else{
                    pivote=M[k][k];
                    for(int j=k;j<n+1;j++){
                        M[i][j]=M[i][j]/pivote;
                    }
                }
            }
        }
        
    
}
} 
void ingresar_coeficientes(double M[20][20],int n){
    cout<<"Introduce los coeficientes:"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"fila "<<i+1<<endl;
        for(int j=0;j<n+1;j++){
            cin>>M[i][j];
        }
    }
}
int main (int argc, char *argv[]) {
    int n;
    double M[20][20];
    cout<<"\t Metodo de Gauss-Jordan"<<endl;
    cout<<endl;
    cout<<"Introduce el numero de incognitas: ";
    cin>>n;
    cout<<endl;
    ingresar_coeficientes(M,n);
    cout<<"La matriz es:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"reduccion:"<<endl;
    gauss_jordan(M,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"solucion:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"X"<<i+1<<"="<<M[i][n]<<"\t"<<endl;
    }cout<<endl;
    return 0;
}
