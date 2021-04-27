#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

main()
{
	double Matriz[3][4]= {{4,-9,2,5},{2,-4,6,3},{1,-1,3,4}};
	double x1,x2,x3;
	double coeficiente1,coeficiente2,coeficiente3;
	cout<<"\t\tMETODO DE GAUSS"<<endl;
	cout<<"La matriz a utilizar es la siguiente: "<<endl;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Paso 1 obtener 0 en primera columna de fila 2 y 3:"<<endl;
	coeficiente1 = (Matriz[1][0]/Matriz[0][0]);
	coeficiente2 = (Matriz[2][0]/Matriz[0][0]);
	for(int j=0;j<=3;j++)
	{
		Matriz[1][j] = (Matriz[1][j] - ((coeficiente1)*(Matriz[0][j])));
		Matriz[2][j] = (Matriz[2][j] - ((coeficiente2)*(Matriz[0][j])));
	}
	
	for(int i=0;i<3;i++)//impresion del primer paso hecho
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Paso 2 obtener 0 en segunda columna de fila 3:"<<endl;
	coeficiente3 = (Matriz[2][1]/Matriz[1][1]);
	for(int j=0;j<=3;j++)
	{
		Matriz[2][j] = (Matriz[2][j] - ((coeficiente3)*(Matriz[1][j])));
	}
	
	for(int i=0;i<3;i++)//impresion del primer paso hecho
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	x3 = (Matriz[2][3]/Matriz[2][2]);
	cout<<"El valor de x3 es: "<<x3<<endl;
	x2 = ((Matriz[1][3]-(Matriz[1][2]*x3))/(Matriz[1][1]));
	cout<<"El valor de x2 es: "<<x2<<endl;
	x1 = (((Matriz[0][3])-(Matriz[0][2]*x3)-(Matriz[0][1]*x2))/4);
	cout<<"El valor de x1 es: "<<x1<<endl;
	
}
