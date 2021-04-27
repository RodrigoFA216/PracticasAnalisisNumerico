//gauss jordan

#include <stdio.h>
#include <iostream>

using namespace std;

double opera(double,double,double,double);

int main ()
{
	double gauss[3][4],aux[3][4],x1,x2,x3;
	
	cout << "ingresa los valores a la matriz 3X4 para realizar el metodo de gauss jordan\n\n";
	
	for(int i=0;i<3;i++)
	{
    	for(int j=0;j<4;j++)
    	{
    		cout <<"posicion [" << i+1 <<"][" << j+1 <<"] ";
    		cin >> gauss[i][j];
    		aux[i][j]=gauss[i][j];;
    		system ("cls");
		}
  	}

  	
  	for(int j=0;j<4;j++)
    {
    	gauss[1][j]=opera(aux[1][0],aux[0][0],gauss[1][j],gauss[0][j]);	
	}
	
	for(int j=0;j<4;j++)
    {
    	gauss[2][j]=opera(aux[2][0],aux[0][0],gauss[2][j],gauss[0][j]);	
	}
	x2=gauss[2][1];
	x1=gauss[1][1];
	for(int j=0;j<4;j++)
    {
    	gauss[2][j]=opera(x2,x1,gauss[2][j],gauss[1][j]);	
    	
	}
	x2=gauss[0][2];
	x1=gauss[2][2];
	for(int j=0;j<4;j++)
    {
    	gauss[0][j]=opera(x2,x1,gauss[0][j],gauss[2][j]);	
    	
	}
	x2=gauss[1][2];
	x1=gauss[2][2];
	for(int j=0;j<4;j++)
    {
    	gauss[1][j]=opera(x2,x1,gauss[1][j],gauss[2][j]);	
    	
	}
	x2=gauss[0][1];
	x1=gauss[1][1];
	for(int j=0;j<4;j++)
    {
    	gauss[0][j]=opera(x2,x1,gauss[0][j],gauss[1][j]);	
    	
	}
	x1=gauss[0][0];
	x2=gauss[1][1];
	x3=gauss[2][2];
	for(int j=0;j<4;j++)
    {
    	gauss[0][j]=gauss[0][j]/x1;
    	gauss[1][j]=gauss[1][j]/x2;
    	gauss[2][j]=gauss[2][j]/x3;
    	
	}
	x1=gauss[0][3];
	x2=gauss[1][3];
	x3=gauss[2][3];
	
	for(int i=0;i<3;i++)
	{
		cout <<"\n";
    	for(int j=0;j<4;j++)
    	{
    		if (gauss[i][j]==-0)
    		{
    			gauss[i][j]=0;
			}
    		cout << gauss[i][j] << "\t";
		}
  	}
  	
  	cout <<"\n\nel resultado es\n" <<"X: "<< x1 <<"\nY: "<< x2 <<"\nZ: "<< x3 << "\n\n";
	  	 	   	 	
	system ("pause");
}

double opera(double n,double n1,double x,double y)
{
	return x-((n/n1)*y);
}
