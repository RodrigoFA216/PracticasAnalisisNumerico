#include<stdio.h>
#include<stdlib.h>

main()
{
int n,a,b,i,j,k;
float A[10][10],B[10],cte,aux;
//Se piden las incógnitas y términos indp.
printf("\n\t\tMETODO DE ELIMINACION DE GAUSS\n");
printf("\nIngrese el numero de ecuaciones del sistema: ");
scanf("%i",&n);
printf("Ingrese los coeficientes\n");
for(a=0;a<n;a++) 
{
   for(b=0;b<n;b++)
   {
                   printf("Valores matriz (%i,%i): ",a+1,b+1);
                   scanf("%f",&A[a][b]);
   }
   printf("Vector %i: ",a+1);
   scanf("%f",&B[a]);
}
//Triangulacion del sistema
for(i=0;i<n;i++)
{
    //Se Comprueba que el pivote sea dif. de 0
    if (A[i][i]==0)
    {
       for(int s=i+1;s<=n+1;s++)
       {
         if (A[s][i]!=0)
         {//Intercambio de renglon
                      aux=A[i][s-1];
                      A[i][s-1]=A[i+1][s-1];
                      A[i+1][s-1]=aux;
                      
                      aux=B[i];
                      B[i]=B[i+1];
                      B[i+1]=aux;
         }      
       }
                      
    }
    for(j=i+1;j<n;j++)
    {
    cte=A[j][i]/A[i][i];
    for(k=i;k<n;k++)
       {
        A[j][k]=A[j][k]-cte*A[i][k];
       }
       B[j]=B[j]-cte*B[i];
    }
}
//Sustitucion regresiva
float suma=0,x[10];
//Se imprime en pantalla el resultado
printf("\n SOLUCION DEL SISTEMA\n");
x[n-1]=B[n-1]/A[n-1][n-1];
printf("x[%d] = %1.4f",i,x[n-1]);
for(int z=n-2;z>=0;z--)
{
    suma=0;
	for(int y=z+1;y<n;y++)
	{
		suma=suma+A[z][y]*x[y];
	}
	x[z]=(B[z]-suma)/A[z][z];
	printf("\nx[%d] = %1.4f",z+1,x[z]);
}
printf("\n");
system("pause");
}
