#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;

void clase(void);
void eleccion(void);
int ab (float, float);
void tabulacion (float, float, int);
float fx(float, int);
void eleccionp1 (void);

int main()
{
	int opc;
	cout<<"\n    << M E T O D O   D E  B I S E C C I O N >>"<<endl;
	cout<<"\n  1) Problema visto en clase"<<endl;
	cout<<"  2) Colocar problema"<<endl;
	cout<<"     Selccione una opcion: ";
	cin>>opc;
	switch(opc)
	{
		case 1:
			clase();
			break;
		case 2:
			eleccion();
			break;
		default:
			cout<<"\nNo hay esa opcion.";
	}
	cout<<"\n\n    ZÚÑIGA SANCHEZ ENRIQUE - GRUPO 4CM11";
}

void clase(void)
{
	float a, b;
	int verificacion;
	system("cls");
	cout<<"\n    << M E T O D O   D E  B I S E C C I O N >>"<<endl;
	cout<<"\n  Mediante la ecuacion f(x)= x3 + 2x2 + 10x - 20, con margen de error epsilon = 0.001";
	cout<<"\n  Seleccione los intervalos a obtener [a,b], estos tienen que ser enteros.";
	cout<<"\n   -> a = ";
	cin>>a;
	cout<<"   -> b = ";
	cin>>b;
	
	verificacion = ab(a,b);
	if(verificacion != 0)
	{
		//Tabulacion de los intervalos entre a y b
		tabulacion(a,b,1);
		//seleccion de Xi y Xd
		float x, y;
		cout<<"\n  Selecciones los intervalos a trabajar:";
		cout<<"\n   -> x = ";
		cin>>x;
		cout<<"   -> y = ";
		cin>>y;
		//checar si es posible hacer el calculo
		float Xm;//Punto medio
		float ep;
		ep=0.001;
		if(fx(x,1)*fx(y,1)>0)
		{
			cout<<"\n  No sera posible aplicar el metodo";
			cout<<"\n  debido a que f("<<x<<") y f("<<y<<") deben de ser de diferente signo";
		}
		else
		{
			int t=1;
			float Xmn=0;
			cout<<"\n\tIt\t   Xi\t   Xd\t   Xm\t   f(Xi)    f(Xd)    f(Xm)\tERROR\n";
			do
			{
				Xm=(x+y)/2;
				
				if(t<3)
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"     "<<fx(x,1)<<"       "<<fx(y,1)<<"       "<<fx(Xm,1)<<"    "<<fabs(Xm-Xmn)<<endl;
				}
				else
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"  "<<fx(x,1)<<"  "<<fx(y,1)<<"  "<<fx(Xm,1)<<"  "<<fabs(Xm-Xmn)<<endl;
				}
				if(fabs(Xm-Xmn)<=ep)
				{
					break;
				}
				else
				{
					if(fx(Xm,1)>0)
					{
						y=Xm;
					}
					else
					{
						if(fx(Xm,1)<0)
						{
							x=Xm;
						}
					}
				}
				t++;
				Xmn=Xm;
			}
			while(1);
		}
	}
	else
	{
		cout<<"\n   Los intervalos ni pueden ser iguales\n";
	}
}
void tabulacion (float a, float b, int c)
{
	int i;
	float ancho, x;
	x=a;
	ancho=(b-a)/10;
	cout<<"\n\t  x \t f(x)"<<endl;
	for(i=0; i<11;i++)
	{
		if(c==1)
		{
			cout<<"\t"<<x<<"\t"<<fx(x,1)<<endl;
			x=x + ancho;	
		}
		else
		{
			if(c==2)
			{
				cout<<"\t"<<x<<"\t"<<fx(x,2)<<endl;
				x=x+ancho;
			}
		}
	}
}

float fx(float x, int c)
{
	float s;
	if(c==1)
	{
		return pow(x,3) + 2*pow(x,2) + 10*x - 20;	
	}
	else
	{
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

void eleccion(void)
{
	float a,b;
	int verificacion;
	eleccionp1();
	system("cls");
	cout<<"\n    << M E T O D O   D E  B I S E C C I O N >>"<<endl;
	cout<<"\n  Seleccione los intervalos a obtener [a,b], estos tienen que ser enteros.";
	cout<<"\n   -> a = ";
	cin>>a;
	cout<<"   -> b = ";
	cin>>b;
	
	
	verificacion = ab(a,b);
	if(verificacion != 0)
	{
		//Tabulacion de los intervalos entre a y b
		tabulacion(a,b,2);
		//seleccion de Xi y Xd
		float x, y;
		cout<<"\n  Selecciones los intervalos a trabajar:";
		cout<<"\n   -> x = ";
		cin>>x;
		cout<<"   -> y = ";
		cin>>y;
		//checar si es posible hacer el calculo
		float Xm;//Punto medio
		float ep;
		cout<<"  Coloque el margen minimo de error epsilon: ";
		cin>>ep;
		if(fx(x,2)*fx(y,2)>0)
		{
			cout<<"\n  No sera posible aplicar el metodo";
			cout<<"\n  debido a que f("<<x<<") y f("<<y<<") deben de ser de diferente signo";
		}
		else
		{
			int t=1;
			float Xmn=0;
			cout<<"\n\tIt\t   Xi\t   Xd\t   Xm\t   f(Xi)    f(Xd)    f(Xm)\tERROR\n";
			do
			{
				Xm=(x+y)/2;
				
				if(t<3)
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"     "<<fx(x,2)<<"       "<<fx(y,2)<<"       "<<fx(Xm,2)<<"    "<<fabs(Xm-Xmn)<<endl;
				}
				else
				{
					cout<<"\t"<<t<<"\t"<<x<<"\t"<<y<<"\t"<<Xm<<"  "<<fx(x,2)<<"  "<<fx(y,2)<<"  "<<fx(Xm,2)<<"  "<<fabs(Xm-Xmn)<<endl;
				}
				if(fabs(Xm-Xmn)<=ep)
				{
					break;
				}
				else
				{
					if(fx(Xm,2)>0)
					{
						y=Xm;
					}
					else
					{
						if(fx(Xm,2)<0)
						{
							x=Xm;
						}
					}
				}
				t++;
				Xmn=Xm;
			}
			while(1);
		}
	}
	else
	{
		cout<<"\n   Los intervalos ni pueden ser iguales\n";
	}
		
}

void eleccionp1 (void)
{
	int o;
	system("cls");
	cout<<"\n    << M E T O D O   D E  B I S E C C I O N >>"<<endl;
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
			cout<<"   -> Tiene exponente (1) si, (2) no: ";
			cin>>p->variable;
			cout<<"   -> Exponente de la variable: ";
			cin>>p->exponente;
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
			cout<<"   -> Exponente de la variable: ";
			cin>>aux->exponente;
			cout<<"   -> Tiene exponente (1) si, (2) no: ";
			cin>>aux->variable;
			aux->sig=NULL;
			aux->ant=f;
			f->sig=aux;
			f=aux; 
		}
	}
	cout<<"\n La ecuacion es: f(x)= ";
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
	system("pause");
}




