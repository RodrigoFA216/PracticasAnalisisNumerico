//Roberto Manuel Garcia Patricio
//matriz inversa 

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

double opera(double,double,double,double);

int main ()
{
	double matriz[3][7],aux[3][4],x_1,x_2,x_3;
	
	cout << "\n\t\tDigita los valores a la matriz 3X4 \n\n";
	
	for(int i=0;i<3;i++)
	{
    	for(int l=0;l<4;l++)
    	{
    		cout <<"Posicion [" << i+1 <<"][" << l+1 <<"] ";
    		cin >> matriz[i][l];
    		aux[i][l]=matriz[i][l];
    		system ("cls");
		}
  	}
  	
  	for(int i=0;i<3;i++)
	{
    	for(int l=4;l<7;l++)
    	{
    		if(matriz[i][l]==matriz[0][4] || matriz[i][l]==matriz[1][5] || matriz[i][l]==matriz[2][6]) 
    		{
    			matriz[i][l]=1;
			}
			else 
			{
				matriz[i][l]=0;	
			}
		}
  	}
  	
  	for(int l=0;l<7;l++)
    {
    	matriz[1][l]=opera(aux[1][0],aux[0][0],matriz[1][l],matriz[0][l]);	
	}
	
	for(int l=0;l<7;l++)
    {
    	matriz[2][l]=opera(aux[2][0],aux[0][0],matriz[2][l],matriz[0][l]);	
	}
	x_2=matriz[2][1];
	x_1=matriz[1][1];
	for(int l=0;l<7;l++)
    {
    	matriz[2][l]=opera(x_2,x_1,matriz[2][l],matriz[1][l]);	
    	
	}
	x_2=matriz[0][2];
	x_1=matriz[2][2];
	for(int l=0;l<7;l++)
    {
    	matriz[0][l]=opera(x_2,x_1,matriz[0][l],matriz[2][l]);	
    	
	}
	x_2=matriz[1][2];
	x_1=matriz[2][2];
	for(int l=0;l<7;l++)
    {
    	matriz[1][l]=opera(x_2,x_1,matriz[1][l],matriz[2][l]);	
    	
	}
	x_2=matriz[0][1];
	x_1=matriz[1][1];
	for(int l=0;l<7;l++)
    {
    	matriz[0][l]=opera(x_2,x_1,matriz[0][l],matriz[1][l]);	
    	
	}
	x_1=matriz[0][0];
	x_2=matriz[1][1];
	x_3=matriz[2][2];
	for(int l=0;l<7;l++)
    {
    	matriz[0][l]=matriz[0][l]/x_1;
    	matriz[1][l]=matriz[1][l]/x_2;
    	matriz[2][l]=matriz[2][l]/x_3;
    	
	}
	x_1=matriz[0][3];
	x_2=matriz[1][3];
	x_3=matriz[2][3];
	
	for(int i=0;i<3;i++)
	{
		cout <<"\n";
    	for(int l=0;l<7;l++)
    	{
    		if (matriz[i][l]==-0)
    		{
    			matriz[i][l]=0;
			}
    		cout << matriz[i][l] << "\t";
		}
  	}
  	if (x_1==-0)
    {
    	x_1==0;	
	}
  	if (21==-0)
    {
    	x_2==0;	
	}
	if (x_3==-0)
    {
    	x_3==0;	
	}
  	cout <<"\n\n\tFinalmente, el resultado es\n" <<"X: "<< x_1 <<"\nY: "<< x_2 <<"\nZ: "<< x_3 << "\n\n";
	  	 	   	 	
	system ("pause");
}

double opera(double n,double n1,double x,double y)
{
	return x-((n/n1)*y);
}
