#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

main()
{
	double Matriz[3][4] = {{4, -9, 2, 5}, {2, -4, 6, 3}, {1, -1, 3, 4}};
	double Matriz_inversa[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	double Auxiliar;
	double Auxiliar_inv;
	double coeficiente1, coeficiente2, coeficiente3, coeficiente4;
	cout<<"\t\tMETODO PARA HAYAR LA MATRIZ INVERSA CON GAUSS-JORDAN"<<endl;
	cout<<"Las matrices a utilizar son las siguiente: "<<endl;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for (int j=0; j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Paso 1 intercambiar la primera y la tercera fila:"<<endl;
	for(int j=0;j<4;j++)
	{
		Auxiliar=Matriz[0][j];
		Matriz[0][j]=Matriz[2][j];
		Matriz[2][j]=Auxiliar;
	}

	for(int j=0;j<3;j++)
	{
		Auxiliar_inv=Matriz_inversa[0][j];
		Matriz_inversa[0][j]=Matriz_inversa[2][j];
		Matriz_inversa[2][j]=Auxiliar_inv;
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Paso 2 obtener 0 en la primera columna de fila 2 y 3:"<<endl;
	coeficiente1 = (Matriz[1][0]/Matriz[0][0]);
	coeficiente2 = (Matriz[2][0]/Matriz[0][0]);
	for(int j=0;j<=3;j++)
	{
		Matriz[1][j] = (Matriz[1][j] - ((coeficiente1)*(Matriz[0][j])));
		Matriz[2][j] = (Matriz[2][j] - ((coeficiente2)*(Matriz[0][j])));
	}

	for(int j=0;j<=2;j++)
	{
		Matriz_inversa[1][j] = (Matriz_inversa[1][j] - ((coeficiente1)*(Matriz_inversa[0][j])));
		Matriz_inversa[2][j] = (Matriz_inversa[2][j] - ((coeficiente2)*(Matriz_inversa[0][j])));
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Paso 3 obtener 1 en la fila 2:"<<endl;
	coeficiente3 = Matriz[1][1];
	for(int j=0;j<=3;j++)
	{
		Matriz[1][j]=(Matriz[1][j]/coeficiente3);
	}

	for(int j=0;j<=2;j++)
	{
		Matriz_inversa[1][j]=(Matriz_inversa[1][j]/coeficiente3);
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"Comenzar a crear la diagonal de 1:"<<endl;
	coeficiente4 = (Matriz[2][1]*(-1));
	for(int j=0;j<=3;j++)
	{
		Matriz[0][j] = (Matriz[0][j] + Matriz[1][j]);
		Matriz[2][j] = (Matriz[2][j] + ((coeficiente4)*(Matriz[1][j])));
	}

	for(int j=0;j<=2;j++)
	{
		Matriz_inversa[0][j] = (Matriz_inversa[0][j] + Matriz_inversa[1][j]);
		Matriz_inversa[2][j] = (Matriz_inversa[2][j] + ((coeficiente4)*(Matriz_inversa[1][j])));
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"Dividir fila 3 entre -10: "<<endl;
	for(int j=0;j<=3;j++)
	{
		Matriz[2][j] = (Matriz[2][j]/-10);
		
	}

	for(int j=0;j<=3;j++)
	{
		Matriz_inversa[2][j] = (Matriz_inversa[2][j]/-10);
		
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<endl;

	for(int j=0;j<=3;j++)
	{
		Matriz[0][j] = (Matriz[0][j]-(3*Matriz[2][j]));
	}

	for(int j=0;j<=2;j++)
	{
		Matriz_inversa[0][j] = (Matriz_inversa[0][j]-(3*Matriz_inversa[2][j]));
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}

		for(int j=0;j<3;j++)
		{
			cout<<Matriz_inversa[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Los valores resultantes son:"<<endl;
	cout<<"x1: "<<Matriz[0][3]<<endl;
	cout<<"x2: "<<Matriz[1][3]<<endl;
	cout<<"x3: "<<Matriz[2][3]<<endl;
}