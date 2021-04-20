#include <stdlib.h>
#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

struct fx
{
	int numero, exponente, toe, exponencial, trigonometrica;
	float coeficiente;
	fx *sig, *ant;
}*p=NULL, *f, *aux;

struct gx
{
	int numero, exponente, toe, trigonometrica, exponencial, dor, div;
	float coeficiente;
	gx *sig, *ant; 
}*pg=NULL, *fg, *auxg;

//FUNCIONES
void funcionamiento(void);
void ecuacion (void);
void despejefx(void);
void despeje(void);
float sustitucion(float);
float sustitucionfx(float);

int main()
{
	float x0, xi, e, gx, gx2, gx3, e2;
	int i;
	funcionamiento();
	despejefx();
	system("cls");
	cout<<"\n                <<  N E W T O N  -  R A P H O N  >>\n"<<endl;
	cout<<"  La ecuacion es:\n";
	ecuacion();
	cout<<"  La derivada es:\n";
	despeje();
	cout<<"\n\n  > De favor, coloque X0= ";
	cin>>x0;
	cout<<"  > Coloque el margen de error: ";
	cin>>e;
	cout<<"\n --------------------------------\n";
	cout<<"   It     Xi     Xi+1      Error";
	cout<<"\n --------------------------------\n";
	xi=x0;
	e2=0;
	for(i=0;e>fabs(e2);i++)
	{
		gx=sustitucion(x0);
		e2=x0-xi;
		gx=sustitucionfx(x0);
		gx2=sustitucion(x0);
		gx3=1-(gx/gx2);
		cout<<"  "<<i+1<<"   "<<x0<<"    "<<gx3<<"    "<<fabs(e2)<<endl;
		xi=x0;
		x0=gx3;
	}
	cout<<"\n\n\n   Zúñiga Sánchez Enrique.";
	
}

void despejefx()
{
	system("cls");
	int i, o;
	cout<<"\n                <<  N E W T O N  -  R A P H O N  >>\n"<<endl;
	cout<<"   > Derivada de la funcion f(x)."<<endl;
	cout<<"   Para el funcionamiento de este metodo, se le solicita que coloque"<<endl;
	cout<<"   la funcion derivada de f(x), de la siguiente manera:"<<endl;
	cout<<"    1. Se pedira cuantas operaciones son, ejemplo, de ser x3 + 2x + 1,"<<endl;
	cout<<"       se colocaran 3 operaciones."<<endl;
	cout<<"    2. En todas las operaciones se colocara x predeterminadamente, en"<<endl;
	cout<<"       caso de no llevar x, en su exponente le coloca 0."<<endl;
	cout<<"    3. Al inicio, se le pedira saber si es una funcion exponencial y/o"<<endl;
	cout<<"       en caso de ser trigonometrica colocara 1 y en ser exponencial, 2."<<endl;
	cout<<"       Si no tiene, se coloca 0."<<endl;
	cout<<"    4. Para el coeficiente, en caso de ser fraccion, colocarla en forma"<<endl;
	cout<<"       decimal."<<endl;
	cout<<"   Cuntas operaciones contiene la ecuacion: ";
	cin>>o;
	for(int i=1;i<=o;i++)
	{
		cout<<"\n >>OPERACION "<<i<<endl;
		if(pg==NULL)
		{
			pg=new(gx);
			pg->numero=i;
			cout<<"   -> Coeficiente: ";
			cin>>pg->coeficiente;
			cout<<"   -> Identidad trigonometrica(1) o Exponencial(2), (0) Ninguna: ";
			cin>>pg->toe;
			switch(pg->toe)
			{
				case 0:
					break;
				case 1:
					cout<<"   -> identidad trigonometrica: (1) cos, (2) sen, (3) tan: ";
					cin>>pg->trigonometrica;
					break;
				case 2:
					cout<<"   -> Identidad exponencial: (1) log, (2) ln: ";
					cin>>pg->exponencial;
					break;
				default:
					break;
			}
			cout<<"   -> Exponente de la variable: ";
			cin>>pg->exponente;
			pg->sig=NULL;
			pg->ant= NULL;
			fg=pg;
		}
		else
		{
			auxg=new(gx);
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
}

void despeje()
{
	int o=0, band=0;
	cout<<"  df(x)/dx = ";
	aux=p;
	while(auxg!=NULL)
	{
		o++;
		auxg=auxg->sig;
	}
	auxg=pg;
	while(auxg!=NULL)
	{
		if(auxg->toe==0)
		{
			if(auxg->exponente==0)
			{
				cout<<auxg->coeficiente;
			}
			else
			{
				printf("%0.1fx%c%i",auxg->coeficiente,94,auxg->exponente);
			}
		}
		else
		{
			if(auxg->toe==1)
			{
				switch(auxg->trigonometrica)	
				{
					case 1:
						printf("%0.1fcos%c%i(x)",auxg->coeficiente,94,auxg->exponente);
						break;
					case 2:
						printf("%0.1fsen%c%i(x)",auxg->coeficiente,94,auxg->exponente);
						break;
					case 3:
						printf("%0.1ftan%c%i(x)",auxg->coeficiente,94,auxg->exponente);
						break;	
				}	
			}
			else
			{
				switch(auxg->exponencial)	
				{
					case 1:
						printf("(%0.1flog(x))%c%i",auxg->coeficiente,94,auxg->exponente);
						break;
					case 2:
						printf("(%0.1fln(x))%c%i",auxg->coeficiente,94,auxg->exponente);
						break;	
				}
			}	
		}
		if(auxg->numero!=o)
		{
			cout<<" + ";
		}
		else
		{
			cout<<endl;
		}
		
		auxg=auxg->sig;
	}
	
}

float sustitucion(float x)
{
	int o, band;
	float r;
	while(auxg!=NULL)
	{
		o++;
		auxg=auxg->sig;
	}
	auxg=pg;
	while(auxg!=NULL)
	{
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
				switch(auxg->exponencial)	
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
		auxg=auxg->sig;
	}
	return r;
}

void funcionamiento()
{
	int o, i;
	cout<<"\n                <<  N E W T O N  -  R A P H O N  >>\n"<<endl;
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
				printf("%0.1fx%c%i",aux->coeficiente,94,aux->exponente);
			}
		}
		else
		{
			if(aux->toe==1)
			{
				switch(aux->trigonometrica)	
				{
					case 1:
						printf("%0.1fcos%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;
					case 2:
						printf("%0.1fsen%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;
					case 3:
						printf("%0.1ftan%c%i(x)",aux->coeficiente,94,aux->exponente);
						break;	
				}	
			}
			else
			{
				switch(aux->exponencial)	
				{
					case 1:
						printf("(%0.1flog(x))%c%i",aux->coeficiente,94,aux->exponente);
						break;
					case 2:
						printf("(%0.1fln(x))%c%i",aux->coeficiente,94,aux->exponente);
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

float sustitucionfx(float x)
{
	int o, band;
	float r;
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
				r=r+ aux->coeficiente;
			}
			else
			{
				r=r + (aux->coeficiente* pow(x,aux->exponente));
			}
		}
		else
		{
			if(aux->toe==1)
			{
				switch(aux->trigonometrica)	
				{
					case 1:
						r= r + pow(cos(x),aux->exponente);
						break;
					case 2:
						r= r + pow(sin(x),aux->exponente);
						break;
					case 3:
						r= r + pow(tan(x),aux->exponente);
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
		aux=aux->sig;
	}
	return r;
}








