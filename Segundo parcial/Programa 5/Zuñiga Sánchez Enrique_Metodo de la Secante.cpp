#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;

void ecuacion(void);
void ecuacion2(void);
float fx(float);
float formula(float, float);

int main()
{
	float a, b, c, e, e2;
	int i, band;
	ecuacion();
	system("cls");
	cout<<"\n    << M E T O D O  D E  L A  S E C A N T E >>"<<endl;
	cout<<"\n f(x)=";
	ecuacion2();
	cout<<"\n  Coloque los valores solicitados:"<<endl;
	cout<<"  - Xo = ";
	cin>>a;
	cout<<"  - X1 = ";
	cin>>b;
	cout<<"  - Margen de error = ";
	cin>>e;
	cout<<"\n----------------------------------------"<<endl;
	cout<<"  It    Xi-1    Xi    Xi+1     Error";
	cout<<"\n----------------------------------------"<<endl;
	for(i=0; band=!0; i++)
	{
		c= formula(a, b);//a=xo y b=xi
		e2=fabs(c-b);
		cout<<"  "<<i+1<<"  "<<a<<"  "<<b<<"  "<<c<<"  "<<e2<<endl;
		if(e>e2)
		{
			band=1;
			break;
		}
		a=b;
		b=c;		
	}
	cout<<"\n----------------------------------------"<<endl;
	cout<<"\n\n    ZUNIGA SANCHEZ ENRIQUE - GRUPO 4CM11";
}

float formula(float a, float b)//a=xo y b=xi
{
	float fxi, fxo, r, r2, m, d;
	fxi=fx(b);
	fxo=fx(a);
	r=b-a;
	r2=fxi-fxo;
	m=r*fxi;
	d=m/r2;
	return b-d;
}

void ecuacion()
{
	int o;
	system("cls");
	cout<<"\n                        << M E T O D O  D E  L A  S E C A N T E >>"<<endl;
	cout<<"\n  Para esto, se le pedira que mediante la ecuacion, ejemplo:  f(x)= x3 + 2x2 + 10x - 20,"
	      "\n  coloque la cantidad de operaciones, en este caso 4 y despues se le pediran que ingrese"
		  "\n  lo elementos de cada operacion, como son los exponentes en caso de ser x, colocar 1," 
		  "\n los coeficientes, al igual en caso de ser x, colocar 1 y si contiene"
		  "\n  variable, en caso de no tener variable colocar un 1 y si tiene un 2";
	cout<<"\n\n  -> Cuantas operaciones tiene la funcion = ";
	cin>>o;
	for(int i=1;i<=o;i++)
	{
		cout<<"\n >>OPERACION "<<i<<endl;
		if(p==NULL)
		{
			p=new(operaciones);
			p->numero=i;
			cout<<"   -> Coeficiente: ";
			cin>>p->coeficiente;
			cout<<"   -> Tiene variable (1) si, (2) no: ";
			cin>>p->variable;
			if(p->variable == 1)
			{
				cout<<"   -> Exponente de la variable: ";
				cin>>p->exponente;	
			}
			p->sig=NULL;
			p->ant= NULL;
			f=p;
		}
		else
		{
			aux=new(operaciones);
			aux->numero=i;
			cout<<"   -> Coeficiente: ";
			cin>>aux->coeficiente;
			cout<<"   -> Tiene variable (1) si, (2) no: ";
			cin>>aux->variable;
			if(aux->variable == 1)
			{
				cout<<"   -> Exponente de la variable: ";
				cin>>aux->exponente;	
			}
			aux->sig=NULL;
			aux->ant=f;
			f->sig=aux;
			f=aux; 
		}
	}
	cout<<"\n La ecuacion es: f(x)= ";
	ecuacion2();
	system("pause");
}

void ecuacion2()
{
	int o;
	while(aux!=NULL)
	{
		o++;
		aux=aux->sig;
	}
	aux=p;
	while(aux!=NULL)
	{
		if(aux->variable==1)
		{
			cout<<"("<<aux->coeficiente<<"x"<<aux->exponente<<")";
		}
		else
		{
			cout<<"("<<aux->coeficiente<<")";
		}
		cout<<" + ";
		aux=aux->sig;
	}
}

float fx(float x)
{
	float s;
	s=0;
	aux=p;
	while(aux!=NULL)
	{
		if(aux->variable==1)
		{
			s =s + aux->coeficiente*pow(x,aux->exponente);
		}
		else
		{
			s = s + aux->coeficiente;
		}
		aux=aux->sig;
	}
	return s;
} 


