/*******************************************************************************************************
*****		Creado por: Mosco Garcia Eduardo							********
*****		Calculadora de Matrices 															********
*****   	Grupo: 4CM11							                                   				********
*******************************************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <windows.h>

void gotoxy(int x, int y) // Ancho = 80, Alto = 25
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void suma();
void resta();
void multiplicacion();
void traspuesta();
void inversa();
//En funciones de usuario siempre se especifica las columnas 
void mostrar_matriz(int matriz[][20], int orden);
//calcula el determinante 
int determinante(int matriz[][20], int orden);
//calculo del cofactor				fila y columnas para calcular su cofactor
int cofactor(int matriz[][20], int orden, int fila, int columna);


void portada()
{
	printf("\t\t\t\t\tInstituto Politecnico Nacional\n");
	printf("\t\t\t\tEscuela Supérior de Ingeneria Electrica y Mecanica\n");
	printf("\t\t\t\t\t\tUnidad Culhuacan\n");
	printf("\n\n\n\n\n\n");
	printf("ANALISIS NUMERICO\n");
	printf("Profesor: OLIVARES MERCADO JESUS\n");
	printf("Grupo:4CM11\n");
	printf("Trabajo:Proyecto Final\n");
	printf("Alumnos: Mosco Garcia Eduardo\n");
	printf("Precione culaquier tecla para continuar...\n\n");
	getch();
}

int main()
{
	char seguir;
	
	do{	
	int opciones;
	portada();
	printf("Seleccione la opcion deseada para comenzar con operaciones con matrices\n");
	printf("1-. Suma \n");
	printf("2-. Resta  \n");
	printf("3-. Multiplicacion\n");
	printf("4-. Inversa\n");
	printf("5-. Matriz Traspuesta\n");
	printf("6-. Determinante de una matriz\n");
	printf("7-. Matriz elevada a una potencia\n");
	printf("8-. Salir\n");
	printf("Opcion a realizar: ");
	scanf("%d",&opciones);
	if (opciones > 0 && opciones < 9)
	{
	system("cls");
	printf("\t\t\t\t\tInstituto Politecnico Nacional\n");
	printf("\t\t\t\tEscuela Supérior de Ingeneria Electrica y Mecanica\n");
	printf("\t\t\t\t\t\tUnidad Culhuacan\n");
	printf("\n\n\n\n\n\n");
	switch(opciones)
	{
		case 1: suma();
			break;
		case 2: resta();
			break;
		case 3: multiplicacion();
			break;
		case 4: inversa();
			break;
		case 5: traspuesta();
			break;
		case 6: 
				int matriz[20][20];
				int orden;
				
				printf("Que es el determinante de una matriz?\n");
				printf("Un determinante es una asignacion de un numero escalar a una matriz cuadrada\n");
				printf("Como se expresaria:\n");
				printf("\t\t\t det(A) = |A|\n"); 	 
				printf("\nLa dimension de la matriz sera un numero entero: \n");
				printf("Si se toma el 2 sera tomado como una matriz 2x2\n");
				printf("\t\t Se veria asi:\n");
				printf("\t\t\t\t|x1	,y1|\n ");
				printf("\t\t\t\t|x2	,y2|\n ");
				
				printf("\nIngrese la dimencion de la matriz [Valor maximo 20]:  ");
				scanf("%d",&orden);
	
				//validando la variable orden 
				while(orden < 0 || orden > 20 )
				{ 
				printf("\nEl orden de la matriz no puede ser mayor a 20 o menor a 0\n");
				printf("Ingrese nuevemente el orden de la matriz ");	
				scanf("%d", &orden);
				}
	
				//introduccion de datos a la matriz
				printf("\nIngrese los valores de la matriz \n");
				//filas
				for(int i = 0; i < orden; i++)
				{
					printf("Ingrese los valores de la fila %d : \n",i+1);
					//columnas
					for(int j = 0; j < orden; j++)
					{
						printf("Ingrese los datos [%d , %d] : ",i+1,j+1);
						scanf("%d", &matriz[i][j]);	
					}
					printf("\n");
				}
				printf("Mostrando la matriz ingresada: \n");
				mostrar_matriz(matriz, orden);
				printf("El determinante es: %d \n", determinante(matriz, orden));
				
			break;
		case 7: 
			int filas,columnas, n;
			do{
				printf("La elevacion de una matriz es igual a su multiplicacion por si misma.\n");
				printf("\t\t Se veria graficamente asi:\n");
				printf("\t\t\t\t|x1	,y1|		\n ");
				printf("\t\t\t\t|x2	,y2|  ^   n		\n ");
				printf("\nIngrese las dimensiones que tendran las matrices \nRecuerde que las matrices deben ser cuadraticas \n");
				printf("Ingrese el numero de filas: ");
				scanf("%d",&filas);
				printf("Ingrese el numero de columnas: ");
				scanf("%d",&columnas);
				printf("Ingrese el numero del exponente:  ");
				scanf("%d",&n);
				printf("\n");
				
				if (filas == columnas)
				{
					int matriz_a[filas][columnas], matriz_r[filas][columnas];
			
					printf("Matriz A\n");
					for (int i = 1; i <= filas; i++)
					{
						printf("Ingrese los valores de la fila %d : \n",i);
						for (int j = 1; j <= columnas; j++)
						{
							printf("Ingrese los datos [%d , %d] : ",i,j);	
							scanf("%d",&matriz_a[i][j]);
						}
					}
					
					for (int i = 1; i <= filas; i++)
					{
						for (int j = 1; j <= columnas; j++)
						{matriz_r[i][j]= 0;
							for(int k = 1; k <= columnas; k++)
							{
								if(n%2 == 0)
								matriz_r[i][j] = matriz_r[i][j] + matriz_a[i][k] * matriz_a[k][j];
								else
								
								matriz_r[i][j] = matriz_r[i][j] + (matriz_a[i][k] * matriz_a[k][j]) * matriz_a[k][j];
							}
						}
					}
					
					for (int i = 1; i <= filas; i++)
					{
						for (int j = 1; j <= columnas; j++)
						{
							printf("	%d	  ", matriz_r[i][j]); 
						}
						printf("\n");
					}
				}
				else
				{
					printf("Introduzca los valores de nuevo .... \n\n");
				}
			}while(filas != columnas);
					
			break;
		case 8: exit(1);
			break;
		default:
		break;
		}
	}
	else
	{
		printf("\nSolo insertar numeros del 1 al 8\n\n");
		//exit(1);
	}
	printf("Desea realizar otra operacion (s/n): "); 
	scanf("%s",&seguir);
	system("cls");
	}while(seguir != 'n');
	
	return 0;
}

void suma ()
{
	int filas,columnas;
	do{
	printf("Ingrese las dimensiones que tendran las matrices \nRecuerde que las matrices deben ser cuadraticas \n");
	printf("Como muestra la siguiente figura\n");
	printf("	|x1	,y1|		|a1 ,b1|	     |x1+a1 , y1+b1|\n");
	printf("	|x2	,y2|	+	|a2 ,b2|	=    |x2+a2 , y1+b1|\n");
	printf("Ingrese el numero de filas: ");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas: ");
	scanf("%d",&columnas);
	printf("\n");
	
	
		if (filas == columnas)
		{
			int matriz_a[filas][columnas], matriz_b[filas][columnas], matriz_r[filas][columnas];
			
			printf("Matriz A\n");
			for (int i = 1; i <= filas; i++)
			{
				printf("Ingrese los valores de la fila %d : \n",i);
				for (int j = 1; j <= columnas; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_a[i][j]);
				}
			}	
			
			printf("\n");
			printf("Matriz B\n");
			for (int i = 1; i <= filas; i++)
			{
				printf("Ingrese los valores de la fila %d :\n",i);
				for (int j = 1; j <= columnas; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_b[i][j]);
				}
			}
			
			
			printf("\n   Matriz A   +    Matriz B   \n");
			for(int i=1; i <= filas; i++)
			{
				for(int j=1; j<= columnas; j++)
				{
					printf("   |%d    ",matriz_a[i][j]);
					
					printf("   %d| ",matriz_b[i][j]);
				}
				printf("\n");
			}
			printf("\nLa suma de la Matriz A con la Matriz B es :  \n");
			for(int i=1; i <= filas; i++)
			{
				for(int j=1; j<= columnas; j++)
				{
					matriz_r[i][j] = ((matriz_a[i][j]) + (matriz_b[i][j]));
					printf("   	%d ",matriz_r[i][j]);
				}
				printf("\n");
			}
			
		} 
		else{
			printf("Introduzca los valores de nuevo .... \n\n");
		}
	}while(filas != columnas);
}

void resta()
{
	int filas,columnas;
	do{
	printf("\nIngrese las dimensiones que tendran las matrices \nRecuerde que las matrices deben ser cuadraticas \n");
	printf("Como muestra la siguiente figura\n");
	printf("	|x1	,y1|		|a1 ,b1|	     |x1-a1 , y1-b1|\n");
	printf("	|x2	,y2|	-	|a2 ,b2|	=    |x2-a2 , y1-b1|\n");
	printf("Ingrese el numero de filas: ");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas: ");
	scanf("%d",&columnas);
	printf("\n");
		if (filas == columnas)
		{
			int matriz_a[filas][columnas], matriz_b[filas][columnas], matriz_r[filas][columnas];
			
			printf("Matriz A\n");
			for (int i = 1; i <= filas; i++)
			{
				printf("Ingrese los valores de la fila %d : \n",i);
				for (int j = 1; j <= columnas; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_a[i][j]);
				}
			}	
			
			printf("\n");
			printf("Matriz B\n");
			for (int i = 1; i <= filas; i++)
			{
				printf("Ingrese los valores de la fila %d :\n",i);
				for (int j = 1; j <= columnas; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_b[i][j]);
				}
			}
			printf("\nLa resta de la Matriz A con la Matriz B es :  \n");
			for(int i=1; i <= filas; i++)
			{
				for(int j=1; j<= columnas; j++)
				{
					matriz_r[i][j] = ((matriz_a[i][j]) - (matriz_b[i][j]));
					printf("  %d  ",matriz_r[i][j]);
				}
				printf("\n");
			}
			
		} 
		else{
			printf("Introduzca los valores de nuevo .... \n\n");
		}
	}while(filas != columnas);
}

void multiplicacion()
{
	int filas,columnas, filas_b ,columnas_b;
	
	int matriz_a[filas][columnas], matriz_b[filas_b][columnas_b], matriz_r[100][100];
	
	printf("Al realizar una multiplicacion de matrices\nTenemos que recordar que 'M''N' = 'N''M'\n");
	printf("\nPara poder realizar una multiplicacion de matrices.\nEl numero columnas de la matriz A, tiene que ser igual al numero de filas de la matriz B, 'M''N' = 'N''M'\n\t\tEjemplo");
	printf("\t\t\t\t\n 			        Matriz A			Matriz B ");
	printf("\t\t\t\t\n 				Filas	  Columnas      \tFilas	  Columnas	");
	printf("\t\t\t\t\n 				  3\t      2\t\tx\t 2\t    3	\n");
	printf("\nIngrese las dimensiones que tendran las matrices: \n \n");
	printf("Matriz A\n");
	printf("Ingrese el numero de filas: ");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas: ");
	scanf("%d",&columnas);
	printf("Matriz B\n");
	printf("Ingrese el numero de filas: ");
	scanf("%d",&filas_b);
	printf("Ingrese el numero de columnas: ");
	scanf("%d",&columnas_b);
	printf("\n");
		if (columnas == filas_b)
		{		 
			printf("Matriz A\n");
			for (int i = 1; i <= filas; i++)
			{
				printf("Ingrese los valores de la fila %d : \n",i);
				for (int j = 1; j <= columnas; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_a[i][j]);
				}
			}	
			
			printf("\n");
			printf("Matriz B\n");
			for (int i = 1; i <= filas_b; i++)
			{
				printf("Ingrese los valores de la fila %d :\n",i);
				for (int j = 1; j <= columnas_b; j++)
				{
					printf("Ingrese los datos [%d , %d] : ",i,j);	
					scanf("%d",&matriz_b[i][j]);
				}
			}
			printf("\nLa multiplicacion de la Matriz A con la Matriz B es : \n");
			for(int i=1; i <= filas; i++)
			{
				for(int j=1; j<= columnas_b; j++)
				{ matriz_r[i][j]= 0;
					for(int k =1; k<= columnas; k++)
					{
						matriz_r[i][j]  = matriz_r[i][j] + matriz_a[i][k] * matriz_b[k][j];	
					}		
				}
			}
			
			for (int i = 1; i <= filas; i++)
			{
				for (int j = 1; j <= columnas_b; j++)
				{
					printf("  %d  ",matriz_r[i][j]);
				}
			printf("\n");
			}
		} 
		else{
			printf("\nEstas matrices no se pueden multiplicar debido a que el numero de columnas de la \n");
			printf("matriz A es diferente al numero de filas de la matriz B, !Intentelo de nuevo! \n");
			printf("\n");
		}
   }
   
void traspuesta()
{
	int filas,columnas;
	printf("Una matriz traspuesta se obtiene cambiando sus filas por sus columnas.\n");
	printf("\n");
	printf("\tPor ejemplo:\n");
	printf("\n			x1 y1 z1		x1	x2\n");
	printf("			x2 y2 z2		y1	y2\n");
	printf("						z1	z2\n");
	printf("\nIngrese las dimensiones que tendran las matrices\n");
	printf("Ingrese el numero de filas: ");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas: ");
	scanf("%d",&columnas);
	printf("\n");
	
	int matriz_a[filas][columnas];
			
	printf("Matriz A\n");
	for (int i = 1; i <= filas; i++)
	{
		printf("Ingrese los valores de la fila %d : \n",i);
		for (int j = 1; j <= columnas; j++)
			{
				printf("Ingrese los datos [%d , %d] : ",i,j);	
				scanf("%d",&matriz_a[i][j]);
			}
	}
	
	printf("Matriz 'A' original\n");
	for (int i = 1; i <= filas; i++)
	{
		for (int j = 1; j <= columnas; j++)
		{
			printf("   %d   ", matriz_a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz 'A' Traspuesta\n");
	printf("\n");
	for (int j = 1; j <= columnas; j++)
	{
		for (int i = 1; i <= filas; i++)
		{
			printf("   %d   ", matriz_a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


void mostrar_matriz(int matriz[][20], int orden)
{
	//printf("El orden es: \n", orden);
	for(int i = 0; i < orden; i++)
	{
		for(int j = 0; j < orden; j++)
		{
			printf("	%d	 ", matriz[i][j]);
		}
		//Este salto de linea es para que los siguietes elementos 
		//se impriman en una nueva fila
		printf("\n");
	}
}

int determinante(int matriz[][20], int orden)
{
	int det = 0.0;
	//calcular el determinante de la matriz
	if (orden == 1)
	{	
		//Fila 0 y columna 0 seria nuestro determinante
		//para el caso de la matriz sea = 1
		det = matriz[0][0];
	}//orden es general arriba de 2
	else
	{
		//la suma del producto de todos los elementos de 
		//cualquier fila por su respectivo cofactor
		for (int j = 0; j < orden; j++)
		{
			//acumulamos los productos de los elementos de cada columna 
			//en la fila cero con su debido cofactor
			det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
			//A la matriz le pasamos el orden de la fila 0 columna j que seria la fila y columna que se tachen
			//en la matriz que tiene como argumento
		}
	}
	
	return det;
}
//Aqui se define el cuerpo 
//fila y columna que se tacharan 
int cofactor(int matriz[][20], int orden, int fila, int columna)
{
	int submatriz[20][20];
	//el orden de la matriz mas grande -1
	int n = orden - 1;
	//necesitamos dos variables para manejar las filas y columnas
	int x = 0;//fila 
	int y = 0;//columna  
	//recorrer la matriz grande y guardar los elementos que no pertenezcan a las fila y columnas
	//creando una nueva matriz tachando una fila y una columna  
	for(int i = 0; i < orden; i++)
	{
		for(int j = 0; j < orden; j++)
		{
			//descartamos los elementos que se encuentran en la variable fila y la columna
			if(i != fila && j != columna)
			{
				//aqui guardamos la submatriz 
				submatriz[x][y] = matriz[i][j];
				y++;
				//Y es mayor o igual al orden de la submatriz que seria n
				if(y >= n)
				{
					//para pasar a la siguiente fila 
					x++;
					y = 0;
				}
			}
		}
	}
	//elevamos a la -1 lasa filas y columnas 
	return pow(-1.0, fila + columna) * determinante(submatriz, n); 
}

int i,j,k,s;
float m1[1000][1000], coef, aux[1000], elemento;

void inversa()
{	
	printf("\nMatriz Inversa\n");
	printf("\nLa dimension de la matriz sera un numero entero: \n");
	printf("Si se toma el 2 sera tomado como una matriz 2x2\n");
	printf("\t\t Se veria asi:\n");
	printf("\t\t\t\t|x1	,y1|\n ");
	printf("\t\t\t\t|x2	,y2|\n ");
	printf("\nNo todas las las matrices cuadradas tienen inversa.\nSi una matriz A tiene inversa, decimos que A es regular o invertible (o inversible).\nEn caso contrario, decimos que es singular.");
	printf("\n\n\t\t\tFormula\n");
	printf("\t\t\t\t (A^-1) = A\n");
	printf("\nPor favor introduzca el tamaño de la matriz:  ");
    /* Vamos a introducir la matriz por teclado*/ 
	scanf("%d",&k);
	
	for (i=0;i<k;i++)
	{
		for (j=0;j<k;j++)
		{
			printf("Ingrese el valor de [%d , %d]:  ", i+1,j+1);
			scanf("%f",&m1[i][j]);
		}
	}
	printf("\nLa amatriz original es: \n");
	for (i=0;i<k;i++)
	{
		for (j=0;j<k;j++)
		{
			printf(" \t %1.2f   ",m1[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	
	for (i=0;i<k;i++)
	//
		for(j=k;j<2*k;j++)
		{
			//
			if(i==(j-k))
				m1[i][j]=1;
			else
				m1[i][j]=0;
		}
		//Iteraciones
		for (s=0;s<k;s++)
		{
			elemento=m1[s][s];
			for (j=0;j<2*k;j++)
				m1[s][j]=m1[s][j]/elemento;

			for(i=0;i<k;i++)
			{
				if (i==s)
					;
				else 
				{
					coef= m1[i][s];
					for (j=0;j<2*k;j++)
						aux[j]=m1[s][j]*(coef*-1);
					for (j=0;j<2*k;j++)
						m1[i][j]=m1[i][j]+aux[j];
				}
			}
		}
		
		printf("La inversa es: \n");
		//Imprimir la matriz inversa
		
		for (i=0;i<k;i++)
		{
			for(j=k;j<2*k;j++)
			{
				printf("[%d , %d] = %f ",i+1,j-1 ,m1[i][j]);
				if (j==k)
		 		printf("\n");
			}
			printf("\n");
		 }
		printf("\n");
        system("pause");
}

