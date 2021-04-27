//Garcia Patricio Roberto Manuel -Gauss jordan

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

double opera(double,double,double,double);

int main ()
{
	double jordan[3][4],aux[3][4],x_1,x_2,x_3;
	
	cout << "\n\t\tIngresar los datos a la matriz 3X4. Se resolvera por metodo de Gauss Jordan\n\n";
	
	for(int i=0;i<3;i++)
	{
    	for(int g=0;g<4;g++)
    	{
    		cout <<"Posicion [" << i+1 <<"][" << g+1 <<"] ";
    		cin >> jordan[i][g];
    		aux[i][g]=jordan[i][g];;
    		system ("cls");
		}
  	}

  	
  	for(int j=0;j<4;j++)
    {
    	jordan[1][j]=opera(aux[1][0],aux[0][0],jordan[1][j],jordan[0][j]);	
	}
	
	for(int j=0;j<4;j++)
    {
    	jordan[2][j]=opera(aux[2][0],aux[0][0],jordan[2][j],jordan[0][j]);	
	}
	x_2=jordan[2][1];
	x_1=jordan[1][1];
	for(int j=0;j<4;j++)
    {
    	jordan[2][j]=opera(x_2,x_1,jordan[2][j],jordan[1][j]);	
    	
	}
	x_2=jordan[0][2];
	x_1=jordan[2][2];
	for(int j=0;j<4;j++)
    {
    	jordan[0][j]=opera(x_2,x_1,jordan[0][j],jordan[2][j]);	
    	
	}
	x_2=jordan[1][2];
	x_1=jordan[2][2];
	for(int j=0;j<4;j++)
    {
    	jordan[1][j]=opera(x_2,x_1,jordan[1][j],jordan[2][j]);	
    	
	}
	x_2=jordan[0][1];
	x_1=jordan[1][1];
	for(int j=0;j<4;j++)
    {
    	jordan[0][j]=opera(x_2,x_1,jordan[0][j],jordan[1][j]);	
    	
	}
	x_1=jordan[0][0];
	x_2=jordan[1][1];
	x_3=jordan[2][2];
	for(int j=0;j<4;j++)
    {
    	jordan[0][j]=jordan[0][j]/x_1;
    	jordan[1][j]=jordan[1][j]/x_2;
    	jordan[2][j]=jordan[2][j]/x_3;
    	
	}
	x_1=jordan[0][3];
	x_2=jordan[1][3];
	x_3=jordan[2][3];
	
	for(int i=0;i<3;i++)
	{
		cout <<"\n";
    	for(int j=0;j<4;j++)
    	{
    		if (jordan[i][j]==-0)
    		{
    			jordan[i][j]=0;
			}
    		cout << jordan[i][j] << "\t";
		}
  	}
  	
  	cout <<"\n\nFinalmente, el resultado es:\n" <<"X: "<< x_1 <<"\nY: "<< x_2 <<"\nZ: "<< x_3 << "\n\n";
	  	 	   	 	
	system ("pause");
}

double opera(double n,double n1,double x,double y)
{
	return x-((n/n1)*y);
}
