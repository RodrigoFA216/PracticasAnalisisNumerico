#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) // Ancho = 80, Alto = 25
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void portada()
{
	printf("\t\t\t\t\tInstituto Politecnico Nacional\n");
	printf("\t\t\t\tEscuela Supérior de Ingeneria Electrica y Mecanica\n");
	printf("\t\t\t\t\t\tUnidad Culhuacan\n");
	printf("\n\n\n\n\n\n");
	printf("Analisis Numerico\n");
	printf("Programa: Serie de Maclaurin\n");
	printf("Profesor:Olivares Mercado Jesus\n");  
	printf("Grupo:4CM11\n");
	printf("Alumno: Mosco Garcia Juan Eduardo\n\n");
	printf("Precione culaquier tecla para continuar...\n");
	getch();
}

int factorial (int);

int main ()
{
	portada();
	int elementos, i = 2,a;
	float x, error, error1, count, y;
	
	
	printf("\nEl programa te pedira el numero de elementos, valor de x,");
	printf("\nInsete el numero de elemntos:");
	scanf("%d",&elementos);
	printf("Inserte el valor de X:");
	scanf("%f", &x);
	/*Obtencion de e^x = p*/
	y = exp(x);	
	gotoxy(90,20);printf("El valor de P = %f\n", y);
	a = elementos;
	
	count = 1 + x;
	while(i < elementos)
	{
		count += (pow(x,i)/factorial(i));
		i++;
	}
	
	printf("El valor aproximado es: %f\n", count);
	
	error = count - y;
	error1 = (error / y)*-100;
	printf("Porcentaje de error es: %f", error1);
	

}
		

int factorial (int x)
{
	int factorial = 1;
	
	for (int i = 1; i <= x; i++)
	{
		factorial = factorial * i;
	}
	return factorial;
}
