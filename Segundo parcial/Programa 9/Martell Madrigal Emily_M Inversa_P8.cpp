#include <windows.h>             //Martell Madrigal Emily
#include <iostream>

using namespace std; 

COORD coord={0,0};
void gotoxy (int x, int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	short int i,f,g,n;
	cout<<"\t\t\t\t\t °Inversa de una matriz °";
	cout<<"\n\n Introduzca el No. de ecuaciones: ";
	cin>>n;
	
	float C[n][n], D[n][n], aux, pivot;
	for(i=0; i<n; i++)
	
	  for(f=0; f<n; f++)
	   {
	   	 gotoxy(f*6, i+3);          
	   	 cin>>C[i][f];
	   	 D[i][f]=0;
	   	 
	   	 if (i==f)
	   	  D[i][f]=1;
	   }
	   
	//Reduccion por renglones
	 
	  for(i=0; i<n; i++)
	   {
		  pivot=C[i][i];
		   for (g=0; g<n; g++)    //Convertir el pivote a 1 y aplicar la operacion a toda la Fila
		     {
		     	C[i][g]=C[i][g]/pivot;
		     	D[i][g]=D[i][g]/pivot;
			 }
		    for (f=0; f<n; f++)
			  {
			  	 if (i!=f)      // No se esta en la diagonal 
			     {
			     	aux=C[f][i];
			     	for (g=0; g<n; g++)
			     	  {
			     	  	C[f][g]=C[f][g]-aux*C[i][g];   
			     	  	D[f][g]=D[f][g]-aux*D[i][g];
					  }
				 }
			  }	
	   }
	cout<<"\n\nMatriz Identidad                   Matriz Inversa";  
	
	   for (i=0; i<n; i++)
	     for (f=0; f<n; f++) 
	     {
			gotoxy(f*6, i+10);
	     	cout<<C[i] [f];
	     	                                  //gotoxy --->   manipular la posición en la pantalla
			gotoxy(33+f*8, i+10);
	     	cout<<D[i][f];
		 }
	return 0;
}
