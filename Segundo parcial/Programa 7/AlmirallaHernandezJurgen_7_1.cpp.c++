#include<iostream>
#include<windows.h>

using namespace std;

int main(){

int u=0,r,i,j;
float a,a1,a2,a3,jr[30];


cout<<"-------GAUSS--------";
cout<<"\n\n\n\nDe cuanto sera la mtriz:   ";
cin>>r;

for(i=0;i<r;i++){

   float V[30][30]={0};

    cout<<"Ingresa los valores:";

    for(j=0;j<r;j++){

        cout<<i+1<<j+1<<":  ";
        cin>>V[i][j];
    }
    cout<<"Cual es la constante? : ";
    cin>>jr[i];
    
}


for(i=0;i<r;i++){

    for(j=0;j<r;j++){

        cout<<V[i][j]<<"\t";            
    }

    cout<<"|\t"<<jr[i];
    
}


do{
    
    a1=0;

    for(i=0;i<r;i++){

        for(j=0;j<r;j++){

            if(i==u){

                a=V[u][u];
                V[i][j]=(V[i][j]/a);
                jr[i]=(jr[i]/a);
            }
        }
    }


    for(i=0;i<r;i++){

        for(j=0;j<r;j++){

            cout<<V[i][j]<<"\t";
        }
        cout<<"|\t"<<jr[i];
       
    }

    for(i=u+1;i<r;i++){

        a3=V[i][u];

        for(j=u;j<r;j++){

                cout<<i;
                cout<<j;
                cout<<"b: "<<V[i][j];

                V[i][j]=((-a3*V[u][j])+V[i][j]);
                cout<<"a: "<<V[i][j];
                cout<<"aux: "<<a3;

                
        }
            jr[i]=((-a3*jr[u])+jr[i]);
            cout<<jr[i];
            
    }

    for(i=0;i<r;i++){

        for(j=0;j<r;j++){

            cout<<V[i][j]<<"\t";
        }
        cout<<"|\t"<<jr[i];
        
    }
    for(i=0;i<r;i++){

        for(j=0;j<r;j++){

            if(i==j){

                a1=a1+V[i][j];
            }
        }
    }
    u++;

}while(a1!=r);

}