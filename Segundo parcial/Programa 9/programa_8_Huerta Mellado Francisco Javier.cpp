#include<iostream>

using namespace std;

int main(){

    int n=0,m=0;

    cout<<"ingrese el tamaño de la matriz "<<endl;

    cin >>n>> m;

    int mat[n][m],cof[n][m],adj[n][m],cofaux[n][m],inv[n][m],aux_inv[n][m];

    if(n==m && n>0 && m>0){

        cout<<"es una matriz cuadrada "<<endl;

    }

    else{

        cout<<"no se puede calcular la matriz. tiene que ser cuadrada "<<endl;

    }

    int i=0,j=0,det=0,det2=0,det3=0,det4=0,aux_cof=1,d=0,k=0,e=0;

    float det5;

    cout<<"ingrese los valores de la matriz "<<endl;

    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            cin >> mat[i][j];

        }

    }


    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            for(d=0;d<n;d++){

            for(e=0;e<m;e++){

            for(k=0;k<m;k++){

                    if((i+k)%2==0){

                        aux_cof = 1;

                       }

                       else if((i+k)%2!=0){

                        aux_cof= -1;

                       }

                    if((d==k || d!=k) && (e==k || e==d)){

                        cofaux[i][j]= aux_cof*((mat[i][k]*mat[d][j])-(mat[i][k]*mat[e][j]));

                    }

            }

        }

    }

    }

    }

    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            cof[i][j]= cofaux[i][j];

        }

    }

    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

                adj[i][j] = cof[j][i];

 

        }

    }


    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            for(k=0;k<n;k++){

                for(e=0;e<n;e++){

                    det=0;

                    det2=0;

                    for(d=0;d<m;d++){

                        if((d!=k || d==k) && (e==k || e==d)&& i!=j){

                            if(i%2==0 & j%2==0 ){

                                det= det + ((mat[i][d]*mat[k][j])-(mat[i][e]*mat[d][j]));

                            }

                            else if(i%2!=0 && j%2!=0 ){

                                det2= det-((mat[i][d]*mat[k][j])-(mat[i][d]*mat[e][j]));

                            }

                        }

                        if(i==j){

                                det3= det3 +(mat[i][j]*det);

                                det4= det4 +(mat[i][j]*det2);

                        }

                    }

                }

            }

        }

    }

    det5 = det3 + det4;

    if(det5==0){

        cout<<"la matriz no tiene inversa"<<endl;

    }

    else{

        for(i=0;i<n;i++){

            for(j=0;j<m;j++){

                aux_inv[i][j]= (1/det5)*adj[i][j];

                inv[i][j] = aux_inv[i][j];

            }

        }

    }

    cout<<"elementos de la matriz inversa "<<endl;

    for(i=0;i<n;i++){

        for(j=0;j<m;j++){

            cout<< inv[i][j]<<" ";

        }

        cout << endl;

    }

    return 0;

}
