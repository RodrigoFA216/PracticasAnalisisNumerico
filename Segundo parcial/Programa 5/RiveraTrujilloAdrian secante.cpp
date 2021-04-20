#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#define ERROR 0.000000001

using namespace std;
struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL, *f, *aux, *aux2, *aux3;
double Funcion(double);
void making_funcion();
double Secante(double x1, double x0);
double calculaError(int t, double vant, double vact);
int counter;
double xa, xb, res, error;



int main(int argc, char const *argv[]) 
{
	cout<<"--------------Metedo de Secante--------------";
	making_funcion();
	double x1, x0;
	cout << "Dame el primer valor semilla: ";
	cin >> x1;
	cout << "Dame el segundo valor semilla: ";
	cin >> x0;
	
	double raiz = Secante(x1, x0);
	cout << "La raíz es: " << raiz << '\n';
	
	return 0;
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
double Secante(double x1, double x0)
{
  xa = x1;
  xb = x0;
  counter = 0;
  do
  {
    res = xa - ((Funcion(xa) * (xb - xa)) / (Funcion(xb) - Funcion(xa)));
    error = calculaError(1, xa, res);//Cambiar primer imput según el error que quiero Calcular
    xa = xb;
    xb = res;
    counter ++;

    //cout << res << '\n';
    //getchar();

    if(res != res)
	{
      cout << "La función se indetermina: " << '\n';
      return res;
    }
  }while(abs(error) > ERROR); //ERROR
  cout << counter <<" interacion(es)." << '\n';
  return res;
}
double calculaError(int t, double vant, double vact)
{
  //INPUT: tipo de Error, Valor Anterior, Valor Actual
  double err = 0.0;
  switch (t)
  {
    case 0 :
      //Error Absoluto
      err = vant - vact;
      break;
    case 1 :
      //Error relativo
      err = (vant - vact) / vant;
      break;
    case 2 :
      //Error porcentual
      err = ((vant - vact) / vant) * 100;
      break;
	}
  return err;
}

