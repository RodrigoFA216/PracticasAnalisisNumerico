#include <stdlib.h>
#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

struct fx
{
	int numero, coeficiente, exponente, toe, exponencial, trigonometrica;
	fx *sig, *ant;
}*p=NULL, *f, *aux;

struct gx
{
	int numero, coeficiente, exponente, toe, trigonometrica, exponencial, dor, div;
	gx *sig, *ant; 
}*pg=NULL, *fg, *auxg;

//FUNCIONES
void funcionamiento(void);
void ecuacion (void);
void despejefx(void);
void despeje(void);
float sustitucion(float);

int main()
{
	float x0, xi, e, gx, e2;
	int i;
	funcionamiento();
	despejefx();
	system("cls");
	cout<<"\n                <<  P U N T O   F I J O  >>\n"<<endl;
	cout<<"  La ecuacion es:\n";
	ecuacion();
	cout<<"  El despeje es:\n";
	despeje();
	cout<<"\n\n  > De favor, coloque X0= ";
	cin>>x0;
	cout<<"  > Coloque el margen de error: ";
	cin>>e;
	cout<<"\n --------------------------------\n";
	cout<<"   It     Xi     g(x)      Error";
	cout<<"\n --------------------------------\n";
	xi=x0;
	e2=0;
	for(i=0;e>fabs(e2);i++)
	{
		gx=sustitucion(x0);
		e2=x0-xi;
		gx=sustitucion(x0);
		cout<<"  "<<i+1<<"   "<<x0<<"    "<<gx<<"    "<<fabs(e2)<<endl;
		if(i>=2 && fabs(e2)>2)
		{
			cout<<"   >> No puede ser completado, no hay convergencia<<";
			break;
		}
		xi=x0;
		x0=gx;
	}
	cout<<"\n\n\n   Zúñiga Sánchez Enrique.";
	
}

void despejefx()
{
	system("cls");
	int i;
	cout<<"\n                <<  P U N T O   F I J O  >>\n"<<endl;
	cout<<"   > Ecuacion g(x)."<<endl;
	cout<<"   Para el funcionamiento de este metodo, se le solicita que coloque"<<endl;
	cout<<"   la funcion despejada de f(x), de la siguiente manera:"<<endl;
	cout<<"    1. Se le pedira si hay division o raices"<<endl;
	cout<<"    2. Se le pedira el llenado de la misma manera que en f(x)."<<endl;
	printf("     2.1. Se pedira cuantas operaciones son, ejemplo, de ser ((x3 + 2x)/2x)%c3,\n",94);
	cout<<"          se colocaran 3 operaciones."<<endl;
	cout<<"     2.2. En todas las operaciones se colocara x predeterminadamente, en"<<endl;
	cout<<"          caso de no llevar x, en su exponente le coloca 0."<<endl;
	cout<<"     2.3. Al inicio, se le pedira saber si es una funcion exponencial y/o"<<endl;
	cout<<"          en caso de ser trigonometrica colocara 1 y en ser exponencial, 2."<<endl;
	cout<<"          Si no tiene, se coloca 0."<<endl;
	pg=new(gx);
	cout<<"Cuantas operaciones hay en el despeje: ";
	cin>>pg->numero;
	cout<<"\n   El despeje tiene a todos los elementos dentro de una (1)raiz\n   (2)una division, (3)ambas o (4)ninguna:  ";
	cin>>pg->dor;
	if(pg->dor==1 || pg->dor==3)
	{
		cout<<"  Cual es la elevacion de la raiz: ";
		cin>>pg->exponente;
	}
	pg->sig=NULL;
	pg->ant= NULL;
	fg=pg;
	for(int i=1;i<=pg->numero;i++)
	{
		cout<<"\n >>OPERACION "<<i<<endl;
		auxg=new(gx);
		if(pg->dor==2 || pg->dor==3)
		{
			cout<<"   -> Es parte del (1)dividendo o (2)divisor: ";
			cin>>auxg->div;	
		}
		auxg->numero=i;
		cout<<"   -> Coeficiente: ";
		cin>>auxg->coeficiente;
		cout<<"   -> Identidad trigonometrica(1) o Exponencial(2), (0) Ninguna: ";
		cin>>auxg->toe;
		switch(auxg->toe)
		{
			case 0:
				break;
			case 1:
				cout<<"   -> identidad trigonometrica: (1) cos, (2) sen, (3) tan: ";
				cin>>auxg->trigonometrica;
				break;
			case 2:
				cout<<"   -> Identidad exponencial: (1) log, (2) ln: ";
				cin>>auxg->exponencial;
				break;
			default:
				break;
		}
		cout<<"   -> Exponente de la variable: ";
		cin>>auxg->exponente;
		auxg->sig=NULL;
		auxg->ant=fg;
		fg->sig=auxg;
		fg=auxg; 
	}
}

void despeje()
{
	int o=0, band=0;
	cout<<"  g(x)= ";
	o=pg->numero;
	auxg=pg->sig;
	while(auxg!=NULL)
	{	
		switch(pg->dor)
		{
			case 1://raiz
				if(auxg->numero==1)
				{
					cout<<"( ";
				}
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						cout<<auxg->coeficiente;
					}
					else
					{
						printf("%ix%c%i",auxg->coeficiente,94,auxg->exponente);
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								printf("%icos%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("%isen%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 3:
								printf("%itan%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								printf("(%ilog(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("(%iln(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;	
						}
					}	
				}
				if(auxg->numero!=o)
				{
					if(auxg->coeficiente>0)
					{
						printf(" + ");	
					}
					else
					{
						cout<<" ";
					}
				}
				if(auxg->numero==o)
				{
					printf(" )%c 1/%i\n",94, pg->exponente);
				}
				break;
			case 2://division
				if(auxg->numero==1)
				{
					cout<<"( ";
				}
				if(auxg->numero!=o)
				{
					if(band==1)
					{
						band++;	
					}	
					else
					{
						if(auxg->coeficiente>0)
						{
							printf(" + ");	
						}
						else
						{
							cout<<" ";
						}
					}
				}
				if(band==0)
				{
					if(auxg->div==2)
					{
						cout<<") / ( ";
						band=1;	
					}
				}
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						cout<<auxg->coeficiente;
					}
					else
					{
						printf("%ix%c%i",auxg->coeficiente,94,auxg->exponente);
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								printf("%icos%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("%isen%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 3:
								printf("%itan%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								printf("(%ilog(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("(%iln(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;	
						}
					}	
				}
				if(auxg->numero==o)
				{
					cout<<" ) \n";
				}
				break;
			case 3:// raiz y division
				if(auxg->numero==1)
				{
					cout<<"( ( ";
				}
				if(auxg->numero!=o)
				{
					if(band==1)
					{
						band++;	
					}	
					else
					{
						if(auxg->coeficiente>0)
						{
							printf(" + ");	
						}
						else
						{
							cout<<" ";
						}
					}
				}
				if(band==0)
				{
					if(auxg->div==2)
					{
						cout<<") / ( ";
						band=1;	
					}
				}
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						cout<<auxg->coeficiente;
					}
					else
					{
						printf("%ix%c%i",auxg->coeficiente,94,auxg->exponente);
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								printf("%icos%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("%isen%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 3:
								printf("%itan%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								printf("(%ilog(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("(%iln(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;	
						}
					}	
				}
				if(auxg->numero==o)
				{
					printf(" ) )%c 1/%i\n",94, pg->exponente);
				}
				break;
			case 4:// ninguna
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						cout<<auxg->coeficiente;
					}
					else
					{
						printf("%ix%c%i",auxg->coeficiente,94,auxg->exponente);
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								printf("%icos%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("%isen%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;
							case 3:
								printf("%itan%c%i(x)",auxg->coeficiente,94,auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								printf("(%ilog(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;
							case 2:
								printf("(%iln(x))%c%i",auxg->coeficiente,94,auxg->exponente);
								break;	
						}
					}	
				}
				if(auxg->numero!=o)
				{
					if(auxg->coeficiente>0)
					{
						printf(" + ");	
					}
					else
					{
						cout<<" ";
					}
				}
				else
				{
					cout<<endl;
				}
				break;	
		}
		auxg=auxg->sig;
	}	
}

float sustitucion(float x)
{
	int o, band;
	float d, dd, r;
	o=pg->numero;
	auxg=pg->sig;
	while(auxg!=NULL)
	{	
		switch(pg->dor)
		{
			case 1://raiz
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						r=r+ auxg->coeficiente;
					}
					else
					{
						r=r + (auxg->coeficiente* pow(x,auxg->exponente));
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								r= r + pow(cos(x),auxg->exponente);
								break;
							case 2:
								r= r + pow(sin(x),auxg->exponente);
								break;
							case 3:
								r= r + pow(tan(x),auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								r=r + log(x);
								break;
							case 2:
								r=r + log10(x);
								break;	
						}
					}	
				}
				r=pow(r,(1/pg->exponente));
				break;
			case 2://divisionç
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						if(auxg->div==2)
						{
							d=d+auxg->coeficiente;
						}
						else
						{
							dd=dd+auxg->coeficiente;
						}
					}
					else
					{
						if(auxg->div==2)
						{
							d=d+(auxg->coeficiente* pow(x,auxg->exponente));
						}
						else
						{
							dd=dd+(auxg->coeficiente* pow(x,auxg->exponente));
						}
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								if(auxg->div==2)
								{
									d=d+ pow(cos(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(cos(x),auxg->exponente);
								}
								break;
							case 2:
								if(auxg->div==2)
								{
									d=d+ pow(sin(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(sin(x),auxg->exponente);
								}
								break;
							case 3:
								if(auxg->div==2)
								{
									d=d+ pow(tan(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(tan(x),auxg->exponente);
								}
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								if(auxg->div==2)
								{
									d=d+ log(x);
								}
								else
								{
									dd=dd+ log(x);
								}
								break;
							case 2:
								if(auxg->div==2)
								{
									d=d+ log10(x);
								}
								else
								{
									dd=dd+ log10(x);
								}
								break;	
						}
					}	
				}
				r= dd/d;
				break;
			case 3:// raiz y division
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						if(auxg->div==2)
						{
							d=d+auxg->coeficiente;
						}
						else
						{
							dd=dd+auxg->coeficiente;
						}
					}
					else
					{
						if(auxg->div==2)
						{
							d=d+(auxg->coeficiente* pow(x,auxg->exponente));
						}
						else
						{
							dd=dd+(auxg->coeficiente* pow(x,auxg->exponente));
						}
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								if(auxg->div==2)
								{
									d=d+ pow(cos(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(cos(x),auxg->exponente);
								}
								break;
							case 2:
								if(auxg->div==2)
								{
									d=d+ pow(sin(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(sin(x),auxg->exponente);
								}
								break;
							case 3:
								if(auxg->div==2)
								{
									d=d+ pow(tan(x),auxg->exponente);
								}
								else
								{
									dd=dd+ pow(tan(x),auxg->exponente);
								}
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								if(auxg->div==2)
								{
									d=d+ log(x);
								}
								else
								{
									dd=dd+ log(x);
								}
								break;
							case 2:
								if(auxg->div==2)
								{
									d=d+ log10(x);
								}
								else
								{
									dd=dd+ log10(x);
								}
								break;	
						}
					}	
				}
				r= dd/d;
				r=pow(r,(1/pg->exponente));
				break;
			case 4:// ninguna
				if(auxg->toe==0)
				{
					if(auxg->exponente==0)
					{
						r=r+ auxg->coeficiente;
					}
					else
					{
						r=r + (auxg->coeficiente* pow(x,auxg->exponente));
					}
				}
				else
				{
					if(auxg->toe==1)
					{
						switch(auxg->trigonometrica)	
						{
							case 1:
								r= r + pow(cos(x),auxg->exponente);
								break;
							case 2:
								r= r + pow(sin(x),auxg->exponente);
								break;
							case 3:
								r= r + pow(tan(x),auxg->exponente);
								break;	
						}	
					}
					else
					{
						switch(aux->exponencial)	
						{
							case 1:
								r=r + log(x);
								break;
							case 2:
								r=r + log10(x);
								break;	
						}
					}	
				}
				break;	
		}
		auxg=auxg->sig;
	}
	return r;
}

void funcionamiento()
{
	int o, i;
	cout<<"\n                <<  P U N T O   F I J O  >>\n"<<endl;
	cout<<"   > Ecuacion f(x)."<<endl;
	cout<<"   Para el funcionamiento de este metodo, se le solicita que coloque"<<endl;
	cout<<"   la funcion fincipal f(x), de la siguiente manera:"<<endl;
	cout<<"    1. Se pedira cuantas operaciones son, ejemplo, de ser x3 + 2x + 1,"<<endl;
	cout<<"       se colocaran 3 operaciones."<<endl;
	cout<<"    2. En todas las operaciones se colocara x predeterminadamente, en"<<endl;
	cout<<"       caso de no llevar x, en su exponente le coloca 0."<<endl;
	cout<<"    3. Al inicio, se le pedira saber si es una funcion exponencial y/o"<<endl;
	cout<<"       en caso de ser trigonometrica colocara 1 y en ser exponencial, 2."<<endl;
	cout<<"       Si no tiene, se coloca 0."<<endl;
	cout<<"   Cuntas operaciones contiene la ecuacion: ";
	cin>>o;
	for(int i=1;i<=o;i++)
	{
		cout<<"\n >>OPERACION "<<i<<endl;
		if(p==NULL)
		{
			p=new(fx);
			p->numero=i;
			cout<<"   -> Coeficiente: ";
			cin>>p->coeficiente;
			cout<<"   -> Identidad trigonometrica(1) o Exponencial(2), (0) Ninguna: ";
			cin>>p->toe;
			switch(p->toe)
			{
				case 0:
					break;
				case 1:
					cout<<"   -> identidad trigonometrica: (1) cos, (2) sen, (3) tan: ";
					cin>>p->trigonometrica;
					break;
				case 2:
					cout<<"   -> Identidad exponencial: (1) log, (2) ln: ";
					cin>>p->exponencial;
					break;
				default:
					break;
			}
			cout<<"   -> Exponente de la variable: ";
			cin>>p->exponente;
			p->sig=NULL;
			p->ant= NULL;
			f=p;
		}
		else
		{
			aux=new(fx);
			aux->numero=i;
			cout<<"   -> Coeficiente: ";
			cin>>aux->coeficiente;
			cout<<"   -> Identidad trigonometrica(1) o Exponencial(2), (0) Ninguna: ";
			cin>>aux->toe;
			switch(aux->toe)
			{
				case 0:
					break;
				case 1:
					cout<<"   -> identidad trigonometrica: (1) cos, (2) sen, (3) tan: ";
					cin>>aux->trigonometrica;
					break;
				case 2:
					cout<<"   -> Identidad exponencial: (1) log, (2) ln: ";
					cin>>aux->exponencial;
					break;
				default:
					break;
			}
			cout<<"   -> Exponente de la variable: ";
			cin>>aux->exponente;
			aux->sig=NULL;
			aux->ant=f;
			f->sig=aux;
			f=aux; 
		}
	}
}

void ecuacion ()
{
	int o=0;
	cout<<"  f(x)= ";
	aux=p;
	while(aux!=NULL)
	{
		o++;
		aux=aux->sig;
	}
	aux=p;
	while(aux!=NULL)
	{
		if(aux->toe==0)
		{
			if(aux->exponente==0)
			{
				cout<<aux->coeficiente;
			}
			else
			{
				printf("%ix%c%i",aux->coeficiente,94,aux->exponente);
			}
		}
		else
		{
			if(aux->toe==1)
			{
				switch(aux->trigonometrica)	
				{
					case 1:
						printf("%icos%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;
					case 2:
						printf("%isen%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;
					case 3:
						printf("%itan%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;	
				}	
			}
			else
			{
				switch(aux->exponencial)	
				{
					case 1:
						printf("(%ilog(x))%c%i",aux->coeficiente,94,aux->exponente);
						break;
					case 2:
						printf("(%iln(x))%c%i",aux->coeficiente,94,aux->exponente);
						break;	
				}
			}	
		}
		if(aux->numero!=o)
		{
			cout<<" + ";
		}
		else
		{
			cout<<endl;
		}
		
		aux=aux->sig;
	}
}








