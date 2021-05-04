//CASTILLO MANCERA ALDO DANIEL
//matriz inversa 

#include <stdio.h>
#include <iostream>

using namespace std;

double OP(double,double,double,double);

int main ()
{
	double GA[3][7],aux[3][4],x1,x2,x3;
	
	cout << "ingresa los valores a la matriz 3X4 para realizar el metodo de gauss jordan\n\n";
	
	for(int i=0;i<3;i++)
	{
    	for(int j=0;j<4;j++)
    	{
    		cout <<"posicion [" << i+1 <<"][" << j+1 <<"] ";
    		cin >> gauss[i][j];
    		aux[i][j]=gauss[i][j];
    		system ("cls");
		}
  	}
  	
  	for(int i=0;i<3;i++)
	{
    	for(int j=4;j<7;j++)
    	{
    		if(GA[i][j]==GA[0][4] || GA[i][j]==gauss[1][5] || GA[i][j]==GA[2][6]) 
    		{
    			GA[i][j]=1;
			}
			else 
			{
				GA[i][j]=0;	
			}
		}
  	}
  	
  	for(int j=0;j<7;j++)
    {
    	GA[1][j]=OP(aux[1][0],aux[0][0],GA[1][j],GA[0][j]);	
	}
	
	for(int j=0;j<7;j++)
    {
    	GA[2][j]=OP(aux[2][0],aux[0][0],GA[2][j],GA[0][j]);	
	}
	x2=GA[2][1];
	x1=GA[1][1];
	for(int j=0;j<7;j++)
    {
    	GA[2][j]=OP(x2,x1,GA[2][j],GA[1][j]);	
    	
	}
	x2=GA[0][2];
	x1=GA[2][2];
	for(int j=0;j<7;j++)
    {
    	gauss[0][j]=OP(x2,x1,GA[0][j],GA[2][j]);	
    	
	}
	x2=GA[1][2];
	x1=GA[2][2];
	for(int j=0;j<7;j++)
    {
    	gauss[1][j]=OP(x2,x1,GA[1][j],GA[2][j]);	
    	
	}
	x2=GA[0][1];
	x1=GA[1][1];
	for(int j=0;j<7;j++)
    {
    	GA[0][j]=OP(x2,x1,GA[0][j],GA[1][j]);	
    	
	}
	x1=GA[0][0];
	x2=GA[1][1];
	x3=GA[2][2];
	for(int j=0;j<7;j++)
    {
    	GA[0][j]=GA[0][j]/x1;
    	GA[1][j]=GA[1][j]/x2;
    	GA[2][j]=GA[2][j]/x3;
    	
	}
	x1=GA[0][3];
	x2=GA[1][3];
	x3=GA[2][3];
	
	for(int i=0;i<3;i++)
	{
		cout <<"\n";
    	for(int j=0;j<7;j++)
    	{
    		if (GA[i][j]==-0)
    		{
    			GA[i][j]=0;
			}
    		cout << GA[i][j] << "\t";
		}
  	}
  	if (x1==-0)
    {
    	x1==0;	
	}
  	if (21==-0)
    {
    	x2==0;	
	}
	if (x3==-0)
    {
    	x3==0;	
	}
  	cout <<"\n\nel resultado es\n" <<"X: "<< x1 <<"\nY: "<< x2 <<"\nZ: "<< x3 << "\n\n";
	  	 	   	 	
	system ("pause");
}

double OP(double n,double n1,double x,double y)
{
	return x-((n/n1)*y);
}
