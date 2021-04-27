#include<iostream>
#include<cmath>
using namespace std; 
double l,k,e,t;
int m;
struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;
double Funcion(double);
void Menu();
void making_funcion();
double falsa_posicion(double a, double b,int MAXIT,double TOL,double Error);

int main () 
{
	making_funcion();
	Menu();
	cout<<falsa_posicion(l,k,m,t,e);//retorna la raiz     
    return 0;
}
double falsa_posicion(double a, double b,int Max_IT,double Tol,double Error)
{
    int cont=1;
    double fa=Funcion(a);
    double fb=Funcion(b);
    double c;     
    double fc;     
    while(cont<Max_IT)
	{
        c=(a*Funcion(b)-b*Funcion(a))/(Funcion(b)-Funcion(a));     
        fc=Funcion(c);
        if(abs(fc)<=Error)
		{
            
            return c;
        }
        if(abs(b-a)<=Tol)
		{
            c=(a+b)/2;
            return c;
        }
        if(fc*fb>0)
        {
        	a=c;
		}
        if(fa*fc>0)
        {
        	b=c;
		}
        cont=cont+1;
    }
	return c;
}
void Menu()
{
	cout<<"Introdusca el intervalo a"<<endl;
	cin>>l;
	cout<<"Introdusca el intervalo b"<<endl;
	cin>>k;
	cout<<"Introdusca el Error"<<endl;
	cin>>e;
	cout<<"Introdusca la tolerancia"<<endl;
	cin>>t;
	cout<<"Introdusca el numero limite de iteraciones"<<endl;
	cin>>m;
	
}
void making_funcion()
{
	int o,d;
	do
	{
		system("cls");
		cout<<"\n\n  Cuantos terminos tiene la funcion = ";
		cin>>o;
		for(int i=1;i<=o;i++)
		{
			cout<<"\n Funcion "<<i<<endl;
			if(p==NULL)
			{
				p=new(operaciones);
				p->numero=i;
				cout<<"    Coeficiente: ";
				cin>>p->coeficiente;
				cout<<"    Pose variable 1 si, 2 no: ";
				cin>>p->variable;
				cout<<"    Exponente de la variable: ";
				cin>>p->exponente;
				p->sig=NULL;
				p->ant= NULL;
				f=p;
			}
			else
			{
				aux=new(operaciones);
				aux->numero=i;
				cout<<"    Coeficiente: ";
				cin>>aux->coeficiente;
				cout<<"    Pose variable 1 si, 2 no: ";
				cin>>aux->variable;
				cout<<"    Exponente de la variable: ";
				cin>>aux->exponente;
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
				cout<<"("<<aux->coeficiente<<"x^"<<aux->exponente<<")";
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
		cout<<"La ecuacion es correcta 1 si, 2 no"<<endl;
		cin>>d;
		if(d<=0||d>=3)
		{
			cout<<"Ese valor no es valido"<<endl;
		}
		system("pause");
	}
	while(d!=1);
}
double Funcion(double x)
{
	double s;
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
