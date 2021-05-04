#include <stdio.h>
#include <conio.h>
#include <math.h>
 
double matriz[50][50];
double identidad[50][50];
int N; 
void hallar_inversa(void);
void escalonar_matriz(void);
void permutar_filas(int fila1, int fila2);
void multip_fila(int fila,double factor);
void sumar_fila_multip(int fila1,int fila2, double factor);
void ceros_abajo(int fila_pivote, int columna_pivote);
void ceros_arriba(int fila_pivote, int columna_pivote);
void generar_matriz_identidad(void);
 
int main(){
	int fi, co;
	do{
		printf("Ingrese el tama�o de la matriz cuadrada: ");
		scanf("%i",&N);
		if(N>50 || N<2) { 
			printf("El numero debe estar entre 2 y 50n");
		}
	}while(N>50 || N<2);
	for(fi=0;fi<N;fi++){
		for(co=0;co<N;co++){
			printf("Ingrese el valor de matriz[%i][%i]: ",fi+1,co+1);
			scanf("%lf",&matriz[fi][co]);
		}
	}
	hallar_inversa();
	return 0;
}
 
void hallar_inversa(void){
	int cont,cont2, flag=0;
 	escalonar_matriz();
	generar_matriz_identidad(); 
	for(cont=0;cont<N;cont++) {
		for(cont2=0;cont2<N;cont2++){
			if(matriz[cont][cont2]!=0){
				if(matriz[cont][cont2]!=1){
					multip_fila(cont,pow(matriz[cont][cont2],-1));
				}
				ceros_arriba(cont,cont2); 
				ceros_abajo(cont,cont2); 
				break;
			}
		}
	}
	for(cont=0;cont<N;cont++){
		for(cont2=0;cont2<N;cont2++){
			if(cont==cont2){
				if(matriz[cont][cont2]!=1) flag=1;
			}
			else{
				if(matriz[cont][cont2]!=0) flag=1;
			}
		}
	}
	if(flag==1){
		printf("nnLa matriz no tiene inversann");
	}
	else{
		printf("\nLa Matriz Inversa es :\n"); 
		for(cont=0;cont<N;cont++){
			for(cont2=0;cont2<N;cont2++){
				printf("%+#0.3f ",identidad[cont][cont2]);
 			}
			printf("\n");
		}
	}
	printf("\nPresione una tecla para continuar...");
	getch();
}

void escalonar_matriz(void){
	int cont, col, ceros, vec[10];
	int flag, aux; 
	for(cont=0;cont<N;cont++){
		col=0,ceros=0; 
		if(matriz[cont][col]==0){
			do{
				ceros++;
				col++;
			}while(matriz[cont][col]==0);
		}
		vec[cont]=ceros;
	}
	do{
		flag=0;
		for(cont=0;cont<N-1;cont++){
			if(vec[cont]>vec[cont+1]){
				aux=vec[cont];
				vec[cont]=vec[cont+1];
				vec[cont+1]=aux; 
				permutar_filas(cont,cont+1);
				flag=1;
			}
		}
	}while(flag==1); 
}
 
void permutar_filas(int fila1,int fila2){
	float auxval;
	int cont; 
	for(cont=0;cont<N;cont++){
		auxval=matriz[fila1][cont];
		matriz[fila1][cont]=matriz[fila2][cont];
		matriz[fila2][cont]=auxval;
		auxval=identidad[fila1][cont];
		identidad[fila1][cont]=identidad[fila2][cont];
		identidad[fila2][cont]=auxval;
	}
}
  
void multip_fila(int fila,double factor){
	int cont; 
	for(cont=0;cont<N;cont++){
		matriz[fila][cont]=(matriz[fila][cont])*factor;
		identidad[fila][cont]=(identidad[fila][cont])*factor;
	}
}
 
void sumar_fila_multip(int fila1,int fila2, double factor){
	int cont;
	for(cont=0;cont<N;cont++){
		matriz[fila1][cont]=(matriz[fila1][cont])+((matriz[fila2][cont])*factor);
		identidad[fila1][cont]=(identidad[fila1][cont])+((identidad[fila2][cont])*factor);
	}
}
  
void ceros_arriba(int fila_pivote, int columna_pivote){
	int cont; 
	for(cont=0;cont<fila_pivote;cont++){
		sumar_fila_multip(cont,fila_pivote,((matriz[cont][columna_pivote])*(-1))); 
	}
}

void ceros_abajo(int fila_pivote, int columna_pivote){
	int cont; 
	for(cont=columna_pivote+1;cont<N;cont++){
		sumar_fila_multip(cont,fila_pivote,((matriz[cont][columna_pivote])*(-1)));
	}
}

void generar_matriz_identidad(void){
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(i==j) identidad[i][j]=1;
			else identidad[i][j]=0;
		}
	}
}
