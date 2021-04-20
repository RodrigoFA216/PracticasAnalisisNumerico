// Método de NEWTON - RAPHSON para el cálculo de raíces
// 25/12/2015

#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 10
#define MAX_ITERACIONES 100
#define INTERVALOS 6

using namespace std;

struct operaciones
{
	int numero, coeficiente, exponente, variable;
	operaciones *sig, *ant;
}*p=NULL,*u=NULL , *f, *aux, *aux2, *aux3, *auxd;


double Funcion(double);
double Funciond(double);
void making_funcion();
void making_funciond();
void tabula(double a, double b, int intervalos);    

int main()
{
    double a;
    double b;
    double tolerancia;    // Tolerancia
    double x0; // Primera aproximación
    double x1; // Siguiente aproximación
    double error;    // Diferencia entre dos aproximaciones sucesivas: x1 - x0
    int iteracion; // # de iteraciones
    bool converge = true;
    cout<<"--------------Metedo de Newton - Raphson--------------";
    making_funcion();
    making_funciond();
    cout << setprecision(PRECISION);    // Se establece la precisión
    cout << "\nCalculo de las raices de una funcion aplicando el metodo de Newton - Raphson\n";
    cout << "\nIngrese el intervalo inicial [a,b]:" << endl;
    
    // Se ingresa el intervalo
    cout << "\na = ";
    cin >> a;
    
    cout << "b = ";
    cin >> b;
    
    // Se tabulan los valores de f para INTERVALOS intervalos
    tabula(a, b, INTERVALOS);
    
    // Se pide elegir una aproximación inicial
    cout << "\nEscoja el punto inicial adecuado:   x0 = ";
    cin >> x0;
    
    // Se pide ingresar la tolerancia
    cout << "Tolerancia = ";
    cin >> tolerancia;
    
    // Iteraciones
    
    // Se imprimen los valores de la primera aproximación
    cout << "\nAproximacion inicial:\n";
    cout << "x0 = " << x0 << "\n"
        << "f(x0) = " << Funcion(x0) << "\n"
        << "f'(x0) = " << Funciond(x0) << endl;
    
    iteracion = 1;
    do {
    
        if (iteracion > MAX_ITERACIONES) {
            converge = false;    // Se sobrepasó la máxima cantidad de iteraciones permitidas
            break;
        
        } else {
            x1 = x0 - Funcion(x0) / Funciond(x0); // Cálculo de la siguiente aproximación
            error = fabs(x1 - x0);    // El error es la diferencia entre dos aproximaciones sucesivas
            
            // Se imprimen los valores de la siguiente aproximación x1, f(x1), f_derivada(x1), error
            cout << "\nIteracion #" << iteracion << endl;
            cout << "x" << iteracion << " = " << x1 << "\n"
              << "f(x" << iteracion << ") = " << Funcion(x1) << "\n"
              << "f'(x" << iteracion << ") = " << Funciond(x1) << "\n"
              << "error = " << error << endl;
            
            // La diferencia entre dos aproximaciones sucesivas es también conocida como error.
            // La condición de terminación consiste en que que el error debe ser <= que la tolerancia dada
            // Si se cumple la condición de terminación, se ha encontrado la raiz aproximada buscada.
            if (error <= tolerancia) { // Condición de terminación
                converge = true;
                break;
                
                // Si no se cumple el criterio de terminación, se pasa a la siguiente iteración
            } else {
                x0 = x1;
                iteracion++;
            }
        }
    
    } while (1);
    
    // Respuesta final
    if (converge) {
        cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << x1 << endl;
    
    } else {
        cout << "\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
    }
    
    cin.get();
    cin.get();
    return 0;
}

void tabula(double a, double b, int intervalos)
{
    int puntos = intervalos + 1;
    
    double ancho = (b - a) / intervalos;
    
    cout << "\n\tx\t\tf(x) " << endl;
    for (int i = 0; i < puntos; i++) {
        cout << "\t" << a << "\t\t" << Funcion(a) << endl;
        a = a + ancho;
    }
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
void making_funciond()
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
				u=new(operaciones);
				u->numero=i;
				cout<<"    Coeficiente: ";
				cin>>p->coeficiente;
				cout<<"    Pose variable 1 si, 2 no: ";
				cin>>u->variable;
				cout<<"    Exponente de la variable: ";
				cin>>u->exponente;
				p->sig=NULL;
				p->ant= NULL;
				f=u;
			}
			else
			{
				auxd=new(operaciones);
				auxd->numero=i;
				cout<<"    Coeficiente: ";
				cin>>auxd->coeficiente;
				cout<<"    Pose variable 1 si, 2 no: ";
				cin>>auxd->variable;
				cout<<"    Exponente de la variable: ";
				cin>>auxd->exponente;
				aux->sig=NULL;
				aux->ant=f;
				f->sig=auxd;
				f=auxd; 
			}
		}
		cout<<"\n La ecuacion es: f(x)= ";
		aux=u;
		while(aux!=NULL)
		{
			if(auxd->variable==1)
			{
				cout<<"("<<auxd->coeficiente<<"x^"<<auxd->exponente<<")";
			}
			else
			{
				cout<<"("<<auxd->coeficiente<<")";
			}		
			if(auxd->numero!=o)
			{
				cout<<" + ";
			}
			else
			{
				cout<<endl;
			}		
			auxd=auxd->sig;
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
double Funciond(double x)
{
	double s;
	s=0;
	auxd=u;
	while(auxd!=NULL)
	{
		if(auxd->variable==1)
		{
			s =s + auxd->coeficiente*pow(x,auxd->exponente);
		}
		else
		{
			s = s + auxd->coeficiente;
		}
		auxd=auxd->sig;
	}
	return s;	
}
