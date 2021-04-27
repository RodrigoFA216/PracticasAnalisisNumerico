#include <stdio.h>           //Martell Madrigal Emily
#include <iostream>

using namespace std;

void datos(int *tam, float mat1[][102]);
void esc_data(int tam1, float mat2[][102]);
void solucion(int Dim, float Sist[][102]);


int main(void)
{
    int i,tam;
    float mat[101][102];
    datos(&tam,mat);
    printf("\n\n\nEcuacion \n\n");
    esc_data(tam,mat);
    solucion(tam,mat);
    printf("\n\n\nSolucion \n");
    for(i=1;i<=tam;i++)
        printf("\n X%d = %f\n",i,mat[i][tam+1]);

    scanf("");
    return(0);
}


void datos(int *tam,float mat1[][102])
{
    int j,k;
    cout<<"\n\t\t\t ° Metodo de Gauss Jordan °";
    printf("\n\n\n\t No. de ecuaciones: ");
    scanf("%d",&*tam);
    
    for(j=1;j<=*tam;j++)
        for(k=1;k<=*tam;k++)
        {
        printf("\n Valores de la celda (%d,%d): ",j,k);            // valores ---> # de las celdas de la matriz (#fila,#columna) 
    scanf("%f",&mat1[j][k]);
    }
    printf("\n\n\n Resultado \n");
    for(j=1;j<=*tam;j++){
        printf("\n Termino Indep. (%d): ",j);         // Ter. independiente (vector) 
        scanf("%f",&mat1[j][*tam+1]);
    }
    }

void esc_data(int tamano, float mat2[][102])
{
    int a,b;
    for(a=1;a<=tamano;a++)
        {
        for(b=1;b<=(tamano+1);b++)
        {
            printf("%7.2f",mat2[a][b]);
            if(b==tamano)
             printf("   |");
    }
        printf("\n");
    }
    }

void solucion(int tam, float mat[][102])
{
    int res,i,h,p,s;
    float col_pivote,x;

    for(i=1;i<=tam;i++)
        {
        res=0;s=i;
        while(res==0)
        {
           if((mat[s][i]>0.0000001)||((mat[s][i]<-0.0000001)))
           {
                res=1;
    }
            else
                s++;
            }
        col_pivote=mat[s][i];
        for(h=1;h<=(tam+1);h++)
            {
            x=mat[s][h];
            mat[s][h]=mat[i][h];
            mat[i][h]=x/col_pivote;
        }
        for(p=i+1;p<=tam;p++)
            {
            x=mat[p][i];
            for(h=i;h<=(tam+1);h++)
            {
                mat[p][h]=mat[p][h]-x*mat[i][h];
        }
    }
    }

    for(i=tam;i>=1;i--)
        for(h=(i-1);h>=1;h--)
        {
        mat[h][tam+1]=mat[h][tam+1]-mat[h][i]*mat[i][tam+1];
        mat[h][i]=0;
    }
}
