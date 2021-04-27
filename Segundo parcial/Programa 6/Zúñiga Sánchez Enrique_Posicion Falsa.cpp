#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;

void eleccion(void);
int ab (float, float);
void tabulacion (float, float);

void ecuacion(void);
void ecuacion2(void);
float fx(float);
float formula(float, float);

int main ()
{
	eleccion();
}

//--------Funciones-------------

void eleccion(void) // Obtencion de Xi y Xf
{
	float a,b;
	int verificacion;
	ecuacion();
	system("cls");
	cout<<"\n    << M E T O D O   D E   P O S I C I O N  F A L S A >>"<<endl;
	cout<<"\n  Seleccione los intervalos a obtener [a,b], estos tienen que ser enteros.";
	cout<<"\n   -> a = ";
	cin>>a;
	cout<<"   -> b = ";
	cin>>b;
	
	
	verificacion = ab(a,b);
	if(verificacion != 0)
	{
		//Tabulacion de los intervalos entre a y b
		tabulacion(a,b);
		//seleccion de Xi y Xd
		float x, y;
		cout<<"\n  Selecciones los intervalos a trabajar:";
		cout<<"\n   -> Xi = ";
		cin>>x;
		cout<<"   -> Xf = ";
		cin>>y;
		if(fx(x)*fx(y)>0)
		{
			cout<<"\n  No sera posible aplicar el metodo";
			cout<<"\n  debido a que f("<<x<<") y f("<<y<<") deben de ser de diferente signo";
		}
		else
		{
			int t=1;
			float Xmn=0;
			system("cls");
			cout<<"\n    << M E T O D O   D E   P O S I C I O N  F A L S A >>"<<endl;
			cout<<"\n\n  La ecuacion es: \n  f(x)= ";
			ecuacion2();
			//checar si es posible hacer el calculo
			float Xm;//Punto medio
			float ep;
			cout<<"\n  Coloque el margen minimo de error epsilon: ";
			cin>>ep;
			cout<<"\n   -> Xi = "<<x;
			cout<<"\n   -> Xf = "<<y;
			cout<<"\n   ----------------------------------------------------------------------------";
			cout<<"\n\tIt\t   Xi\t   Xf\t   Xm\t   f(Xi)    f(Xf)    f(Xm)\tERROR\n";
			cout<<"   ----------------------------------------------------------------------------"<<endl;;
			do
			{
				Xm=formula(x, y);
				
				if(t<3)
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"     "<<fx(x)<<"       "<<fx(y)<<"       "<<fx(Xm)<<"    "<<fabs(Xm-Xmn)<<endl;
				}
				else
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"  "<<fx(x)<<"  "<<fx(y)<<"  "<<fx(Xm)<<"  "<<fabs(Xm-Xmn)<<endl;
				}
				if(fabs(Xm-Xmn)<=ep)
				{
					break;
				}
				else
				{
					if(fx(Xm)>0)
					{
						y=Xm;
					}
					else
					{
						if(fx(Xm)<0)
						{
							x=Xm;
						}
					}
				}
				t++;
				Xmn=Xm;
			}
			while(1);
			cout<<"\n   ----------------------------------------------------------------------------"<<endl;;
		}
	}
	else
	{
		cout<<"\n   Los intervalos ni pueden ser iguales\n";
	}
	
	cout<<"\n    ZUNIGA SANCHEZ ENRIQUE - GRUPO 4CM11";
		
}

int ab (float a, float b)
{
	if(a==b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void tabulacion (float a, float b)
{
	int i;
	float ancho, x;
	x=a;
	ancho=(b-a)/10;
	cout<<"\n\t  x \t f(x)"<<endl;
	for(i=0; i<11;i++)
	{
		cout<<"\t"<<x<<"\t"<<fx(x)<<endl;
		x=x+ancho;
	}
}

void ecuacion()
{
	int o;
	system("cls");
	cout<<"\n                    << M E T O D O   D E   P O S I C I O N  F A L S A >>"<<endl;
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

