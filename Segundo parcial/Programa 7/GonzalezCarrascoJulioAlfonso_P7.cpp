#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


using namespace std;

int main()
{
    int op,C,tam=3;
    int i,j,k,n,m;
    float mt[20][20],aux;

cout<<"Aviso: Actualmente esta version del programa (ver 0.2.7) solo soporta mrices de 3x3 en el metodo Gauss-Jordan\n";

cout<<"Desea hacerlo con el metodo de 1.-Gauss o 2.-Gauss/Jordan ";
cin>>op;

switch(op){
case 1:
    cout<<"\n m cuadrada de orden N= ";
    cin>>n;
    cout<<"\n Digite los elementos de la m en la posicion ";
    for(i=1;i<=n;i++){

        for(j=1;j<=n;j++){
            cout<<"\n M=["<<i<<","<<j<<"]= ";
            cin>>mt[i][j];
        }
        cout<<"\n Termino independiente de X"<<i<<" ";
        cin>>mt[i][n+1];

    }

    for(i=1;i<=n;i++){
        if(mt[i][i]!=0){
            aux=1/mt[i][i];
            for(j=1;j<=n+1;j++)
            {
                mt[i][j]=aux*mt[i][j];
            }

            for(j=1;j<=n;j++){
                if(j!=i)
                {
                    aux=-mt[j][i];
                    for(k=1;k<=n+1;k++)
                    {
                    mt[j][k]=mt[j][k]+aux*mt[i][k];
                    }
                }
            }
        }
    }

    cout<<"\n";
    cout<<"la matriz identidad es";
    cout<<"\n\n";
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
    cout<<mt[i][j]<<"\t";
    }
    cout<<"\n\n";
    }

    cout<<"El valor de las incognitas es : ";
    for(i=1;i<=n;i++)
    {
    cout<<"\nX"<<i<<" = "<<mt[i][n+1]<<"\n";
    }
break;
case 2:
    cout<<"\n Digite los elementos de la m en la posicion ";

    int res;
    float col_pivote,x;

    for(j=1;j<=tam;j++){

        for(k=1;k<=tam;k++){
            cout<<"\n M=["<<j<<","<<k<<"]= ";
            cin>>mt[j][k];
        }
        cout<<"\n Termino independiente de X"<<j<<" ";
        cin>>mt[j][tam+1];
    }

    for(i=1;i<=tam;i++)
        {
        res=0;m=i;
        while(res==0)
        {
           if((mt[m][i]>0.0000001)||((mt[m][i]<-0.0000001)))
           {
                res=1;
    }
            else
                m++;
            }
        col_pivote=mt[m][i];

        for(j=1;j<=(tam+1);j++)
            {
            x=mt[m][j];
            mt[m][j]=mt[i][j];
            mt[i][j]=x/col_pivote;
        }

        for(k=i+1;k<=tam;k++)
            {
            x=mt[k][i];
            for(j=i;j<=(tam+1);j++)
            {
                mt[k][j]=mt[k][j]-x*mt[i][j];
        }
    }
    }

    for(i=tam;i>=1;i--){
        for(j=(i-1);j>=1;j--)
        {
            mt[j][tam+1]=mt[j][tam+1]-mt[j][i]*mt[i][tam+1];
            mt[j][i]=0;
        }
    }

    cout<<"\n";
    cout<<"la matriz identidad es";
    cout<<"\n\n";
    for(j=1;j<=tam;j++)
    {
    for(k=1;k<=tam;k++)
    {
    cout<<mt[j][k]<<"\t";
    }
    cout<<"\n\n";
    }

    cout<<"El valor de las incognitas es : ";
    for(i=1;i<=tam;i++)
    {
    cout<<"\nX"<<i<<" = "<<mt[i][tam+1]<<"\n";
    }
break;
default:
    cout<<"ok";
break;
}



getchar();
return 0;
}
