#include<iostream>
#include<windows.h>
using namespace std;
int main(){
int u=0,N,i,j;
float aux,aux1,V[30][30]={0},C[30];
cout<<"DIMENSION:   ";
cin>>N;

system("cls");

for(i=0;i<N;i++){
    cout<<"INGRESE VALORES MATRIZ:"<<endl;
    for(j=0;j<N;j++){
        cout<<i+1<<j+1<<":  ";
        cin>>V[i][j];
    }
    cout<<"INGRESE CONSTANTE: ";
    cin>>C[i];
    system("cls");
}
system("cls");

for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        cout<<V[i][j]<<"\t";            
    }
    cout<<"|\t"<<C[i];
    cout<<endl;
}

system("pause");
do{
    system("cls");
//      for(i=0;i<N;i++){
//          for(j=0;j<N;j++){
//              if(i==j&&V[i][j]==0){
//                  cout<<"LA MATRIZ NO TIENE SOLUCION";
//                  return 0;
//              }
//          }
//      }   

    aux1=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==u){
                aux=V[u][u];
                V[i][j]=(V[i][j]/aux);
                C[i]=(C[i]/aux);
            }
        }
    }


    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout<<V[i][j]<<"\t";
        }
        cout<<"|\t"<<C[i];
        cout<<endl;
    }
    system("pause");
    system("cls");
//----------------------------------------------------------------------------
//  Aplicando el Metodo Gauss para Resolucion de Ecuaciones Lineales hemos observado
//  que los valores que corresponden a las coordenadas, al momento de imprimir
//  no coinciden. Ej: en V[2][2] el valor registrado que debe guardar es -2
//  pero al momento de imprimir mu
    cout<<"ENTRANDO"<<endl;
    for(i=u+1;i<N;i++){
        float aux3;
        aux3=V[i][u];
        for(j=u;j<N;j++){
                cout<<i<<endl;
                cout<<j<<endl;
                cout<<"b: "<<V[i][j]<<endl;
                V[i][j]=((-aux3*V[u][j])+V[i][j]);
                cout<<"a: "<<V[i][j]<<endl;
                cout<<"aux: "<<aux3<<endl;
                system("pause");
        }
            C[i]=((-aux3*C[u])+C[i]);
            cout<<C[i]<<endl;
            system("pause");
    }
//----------------------------------------------------------------------------
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout<<V[i][j]<<"\t";
        }
        cout<<"|\t"<<C[i];
        cout<<endl;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j){
                aux1=aux1+V[i][j];
            }
        }
    }
    u++;
}while(aux1!=N);
return 0;
}
