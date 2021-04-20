#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

double f(double x);    // Retorna el valor de la función evaluada en x
double f_derivada(double x); // Retorna la derivada de la función evaluada en x
void newton_raphson(double x0, double tolerancia, int max_interaciones);    // Función que calcula la raiz aproximada de una función
void tabla(double a, double b, int intervalos);    


int main(){
    double a;
    double b;
    double tolerancia;  
    double PrimeraApoximacionX0; 
    cout<<setprecision(10); 
    cout<<"\nCalculo de las raices de una funcion aplicando el metodo de Newton - Raphson\n";
    cout<<"\nIngrese el intervalo inicial [a,b]:" << endl;
    cout<<"\ a = ";
    cin>>a;
    cout<<" b = ";
    cin>>b;
    cout << "\nEscoja el punto inicial adecuado:   x0 = ";
    cin >> PrimeraApoximacionX0;
    cout<<"Tolerancia = ";
    cin>>tolerancia;
    tabla(a, b, 6);
    newton_raphson(PrimeraApoximacionX0, tolerancia, 100);
    return 0;
}


void tabla(double a, double b, int intervalos){
    int puntos=intervalos+1;
    
    double ancho=(b-a)/intervalos;
    
    cout<<"\n\tx\t\tf(x) "<<endl;
    for (int i=0; i<puntos; i++){
        cout<<"\t"<<a<<"\t\t"<<f(a)<<endl;
        a=a+ancho;
    }
}


double f(double x){
    return pow(x,3)*(2*pow(x,2))+(10*x)-20;
}

double f_derivada(double x){
    return pow(x,3)+(4*x)+10;
}


void newton_raphson(double x0, double tolerancia, int max_iteraciones){
    double x1;
    double error;
    int iteracion;
    bool converge = true;
    cout << "\nAproximacion inicial:\n";
    cout << "x0 = " <<x0<<endl;
        << "f(x0) = "<<f(x0)<<endl;
        << "f'(x0) = "<<f_derivada(x0)<<endl;
    iteracion=1;
    do{    
        if (iteracion > 100) {
            converge = false;
            break;
        }
		else{
            x1=x0-f(x0)/f_derivada(x0);
            error=fabs(x1-x0);
            cout<<"\a";
            cout<<"\n\nIteracion #"<<iteracion<<endl;
            cout<<"\nx"<< iteracion<< "     = "<<x1<<endl;
            cout<<"f(x"<< iteracion<< ")  = "<<f(x1)<<endl;
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
        cout << "\n\nPara una tolerancia de " << tolerancia << " la RAIZ APROXIMADA de f es = " << x1 << endl;
    
    }
	else{
        cout << "\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
    }
}
