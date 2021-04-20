#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

double funcion(double x);    
double f_derivada(double x); 
void Newton_Raphson(double x0, double tolerancia, int max_interaciones);   
void Resultado(double a, double b, int intervalos);  
double a;
double b;
double tolerancia;  
double PAproximx0;   


int main(){
  
    cout<<"\n Metodo de Newton - Raphson\n";
    cout<<"\nInserta los intervalos [a,b]:" << endl;
    cout<<"\ a = ";
    cin>>a;
    cout<<" b = ";
    cin>>b;
    cout << "\nIndica el punto inicial (X0):";
    cin >> PAproximx0;
    cout<<"Tolerancia= ";
    cin>>tolerancia;
    Resultado(a, b, 6);
    Newton_Raphson(PAproximx0, tolerancia, 100);
    return 0;
}


void Resultado(double a, double b, int intervalos){
    int puntos=intervalos+1;
    
    double ancho=(b-a)/intervalos;
    
    cout<<"\n\tx\t\tf(x) "<<endl;
    for (int i=0; i<puntos; i++){
        cout<<"\t"<<a<<"\t\t"<<funcion(a)<<endl;
        a=a+ancho;
    }
}


double funcion(double x){
    return pow(x,3)*(2*pow(x,2))+(10*x)-20;
}

double f_derivada(double x){
    return pow(x,3)+(4*x)+10;
}


void Newton_Raphson(double x0, double tolerancia, int max_iteraciones){
    double x1;
    double error;
    int iteracion;
    bool converge = true;
    cout << "\nAproximacion inicial:\n";
    cout << "x0 = " <<x0<<endl;
        cout<< "f(x0) = "<<funcion(x0)<<endl;
        cout<< "f'(x0) = "<<f_derivada(x0)<<endl;
    iteracion=1;
    do{    
        if (iteracion > 100) {
            converge = false;
            break;
        }
		else{
            x1=x0-funcion(x0)/f_derivada(x0);
            error=fabs(x1-x0);
            cout<<"\a";
            cout<<"\n\nIteracion No."<<iteracion<<endl;
            cout<<"\nx"<< iteracion<< "     = "<<x1<<endl;
            cout<<"f(x"<< iteracion<< ")  = "<<funcion(x1)<<endl;
            cout<<"f'(x"<< iteracion<< ") = "<<f_derivada(x1)<<endl;
            cout<<"error  = "<<error<<endl;
            if (error <= tolerancia){
            	converge = true;
                break;
            }
			else{
                x0 = x1;
                iteracion++;
            }
        }
    
    }
	while (1);

    cout << "\a";
    if (converge){
        cout << "\n\nTolerancia de " << tolerancia << " la RAIZ APROXIMADA de f es = " << x1 << endl;
    
    }
	else{
        cout << "\n\n Error demasiado numero de iteraciones permitidas" << endl;
    }
}
