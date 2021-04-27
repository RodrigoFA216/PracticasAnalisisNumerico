#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

struct ecuaciones
{
	int numero;
	int div[4];
	float dividendo[4];
	float divisor[4];
	ecuaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;

void gauss(void);
void jordan(void);
void llenar(void);
void impresion(void);
void rg (void);
void rj (void);

int main()
{
	int m;
	cout<<"\n    <<  R E S O L U C I O N   DE  M A T R I C E S  >>"<<endl;
	cout<<"\n    Metodos disponibles:\n   (1) Metodo de Gauss.\n   (2) Metodo de Gauss Jordan. "<<endl;
	cout<<"       Seleccione el metodo deseado: ";
	cin>>m;
	switch(m)
	{
		case 1:
			gauss();
			break;
		case 2:
			jordan();
			break;
	}
	cout<<"\n\n    ZUNIGA SANCHEZ ENRIQUE - GRUPO 4CM11";
}
//-------------------FUNCIONES-----------------
void gauss()
{
	system("cls");
	cout<<"\n    << M E T O D O  D E  G A U S S >>"<<endl;
	llenar();
	system("cls");
	cout<<"\n    << M E T O D O  D E  G A U S S >>\n"<<endl;
	cout<<"  Matriz: \n"<<endl;
	impresion();
	cout<<"\n\n Resultado: \n"<<endl;
	rg();	
	impresion();
}
void jordan()
{
	system("cls");
	cout<<"\n    << M E T O D O  D E  G A U S S  J O R D A N >>"<<endl;
	system("cls");
	cout<<"\n    << M E T O D O  D E  G A U S S  J O R D A N >>\n"<<endl;
	cout<<"  Matriz: \n"<<endl;
	impresion();
	cout<<"\n\n Resultado: \n"<<endl;
	//rj();
	impresion();
}

void llenar()
{
	int i, j;
	cout<<"\n   A continuacion se mostrara el orden del llenado de";
	cout<<"\n   la matriz para su resolucion.";
	cout<<"\n  * Se le preguntara en cada valor, si es una fraccion.";
	cout<<"\n\n   Fila 1 =  | x1 x2 x3  |  R1  |";
	cout<<"\n   Fila 2 =  | x1 x2 x3  |  R2  |";
	cout<<"\n   Fila 3 =  | x1 x2 x3  |  R3  |";
	cout<<"\n\n   > Llenado de la matriz.";
	for(int i=1;i<=3;i++)
	{
		cout<<"\n Fila "<<i<<endl;
		if(p==NULL)
		{
			p=new(ecuaciones);
			p->numero=i;
			for(j=0; j<4; j++)
			{
				if(j==3)
				{
					cout<<"El coeficiente de R"<<i<<" es fraccion (1) Si, (2) No : ";
					cin>>p->div[j];
					switch(p->div[j])
					{
						case 1:
							cout<<"Ingrese el dividendo : ";
							cin>>p->dividendo[j];
							cout<<"Ingrese el divisor : ";
							cin>>p->divisor[j];
							break;
						case 2:
							cout<<"Ingrese el valor de R"<<i<<" : ";
							cin>>p->dividendo[j];
							p->divisor[j]=1;
							break;
					}
				}
				else
				{
					cout<<"El coeficiente de X"<<j+1<<" es fraccion (1) Si, (2) No : ";
					cin>>p->div[j];
					switch(p->div[j])
					{
						case 1:
							cout<<"Ingrese el dividendo X"<<j+1<<" : ";
							cin>>p->dividendo[j];
							cout<<"Ingrese el divisor X"<<j+1<<" : ";
							cin>>p->divisor[j];
							break;
						case 2:
							cout<<"Ingrese el valor de X"<<j+1<<" : ";
							cin>>p->dividendo[j];
							p->divisor[j]=1;
							break;
					}
				}
				
			}
			p->sig=NULL;
			p->ant= NULL;
			f=p;
		}
		else
		{
			aux=new(ecuaciones);
			aux->numero=i;
			for(j=0; j<4; j++)
			{
				if(j==3)
				{
					cout<<"El coeficiente de R"<<i<<" es fraccion (1) Si, (2) No : ";
					cin>>aux->div[j];
					switch(aux->div[j])
					{
						case 1:
							cout<<"Ingrese el dividendo : ";
							cin>>aux->dividendo[j];
							cout<<"Ingrese el divisor : ";
							cin>>p->divisor[j];
							break;
						case 2:
							cout<<"Ingrese el valor de R"<<i<<" : ";
							cin>>aux->dividendo[j];
							aux->divisor[j]=1;
							break;
					}
				}
				else
				{
					cout<<"El coeficiente de X"<<j+1<<" es fraccion (1) Si, (2) No : ";
					cin>>aux->div[j];
					switch(p->div[j])
					{
						case 1:
							cout<<"Ingrese el dividendo X"<<j+1<<" : ";
							cin>>aux->dividendo[j];
							cout<<"Ingrese el divisor X"<<j+1<<" : ";
							cin>>aux->divisor[j];
							break;
						case 2:
							cout<<"Ingrese el valor de X"<<j+1<<" : ";
							cin>>aux->dividendo[j];
							aux->divisor[j]=1;
							break;
					}
				}
				
			}
			aux->sig=NULL;
			aux->ant=f;
			f->sig=aux;
			f=aux; 
		}
	}
}

void impresion()
{
	int j, i;
	aux=p;
	while(aux!=NULL)
	{
		cout<<"  | ";
		for(j=0; j<4; j++)
		{
			if(aux->div[j]==1)
			{
				if(j==3)
				{
					cout<<"| ("<<aux->dividendo[j]<<"/"<<aux->divisor[j]<<") |";
				}
				else
				{
					cout<<"("<<aux->dividendo[j]<<"/"<<aux->divisor[j]<<") ";	
				}
			}
			else
			{
				if(j==3)
				{
					cout<<"|  ("<<aux->dividendo[j]<<")   |";
				}
				else
				{
					cout<<" ("<<aux->dividendo[j]<<")  ";	
				}
			}
		}
		cout<<"\n";
		aux=aux->sig;
	}
}

void rg()
{
	float d, dd;
	int i, j;
	aux=p;
	aux2=aux->sig;
	aux3=aux2->sig;
	d=(aux2->dividendo[0]) * (aux->divisor[0]);
	dd=(aux2->divisor[0]) * (aux->dividendo[0]);
	
	for(i=0; i<4; i++)
	{
		aux2->divisor[i]= (aux2->divisor[i])*(aux->divisor[i])*dd;
		aux2->dividendo[i]=((aux2->dividendo[i])*(aux->divisor[i])*dd)-(d*(aux2->divisor[i])*(aux->dividendo[i]));
	}
	
	d=(aux3->dividendo[0]) * (aux->divisor[0]);
	dd=(aux3->divisor[0]) * (aux->dividendo[0]);
	
	for(i=0; i<4; i++)
	{
		aux3->divisor[i]= (aux3->divisor[i])*(aux->divisor[i])*dd;
		aux3->dividendo[i]=((aux3->dividendo[i])*(aux->divisor[i])*dd)-(d*(aux3->divisor[i])*(aux->dividendo[i]));
	}
	
	d=(aux3->dividendo[0]) * (aux2->divisor[0]);
	dd=(aux3->divisor[0]) * (aux2->dividendo[0]);
	
	for(i=0; i<4; i++)
	{
		aux3->divisor[i]= (aux3->divisor[i])*(aux2->divisor[i])*dd;
		aux3->dividendo[i]=((aux3->dividendo[i])*(aux2->divisor[i])*dd)-(d*(aux3->divisor[i])*(aux2->dividendo[i]));
	}
	
	aux=p;
	for(i=0; i<4; i++)
	{
		if(aux->divisor[i]>1)
		{
			aux->div[i]=1;
		}
		aux=aux->sig;
	}
	
}

void rj();







