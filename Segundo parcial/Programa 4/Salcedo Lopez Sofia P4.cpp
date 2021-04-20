/*Programa 4. Método de Newton-Raphson
Salcedo López Sofía
Análisis numérico 4CM11*/

#include<iostream>
#include<cmath>

using namespace std;

//Funcion f(x)

double f(double x){
	return pow(x,3)+2*pow(x,2)+10*x-20;
};

//Derivada de la funcion f(x)
double df(double x){
	return (double)3*pow(x,2)+4*x+10;
};

int main(){
	

	double epsilon, error;
	int puntos, intervalos, iteraciones = 0;
	double a,b,x0,x1;
	bool converge = true;
	
	cout<<"Este programa calcula la raiz de f(x)= x^3+2x^2+10x-20 con el Método de Newton-Raphson"<<endl;
	
	
	cout<<"Ingrese el valor de Épsilon: "<<endl;
	cin>>epsilon;
	
	cout<<"Defina un punto inicial: "<<endl;
	cin>>x0;
	
	//Se muestra la primera aproximacion
	cout<<"\nAproximacion inicial:\n";
	cout<<"x0 = "<<x0<<"\n"
	<<"f(x0)="<<f(x0)<<"\n"
	<<"f'(x0)="<<df(x0)<<endl;
	iteraciones ++;
	
	do{
		//Se establece 150 como limite de iteraciones max. para determinar que no converge
		if(iteraciones > 150){
			converge = false;
			break;
			
		}else{
			x1= x0-f(x0)/df(x0);
			error=fabs(x1-x0);
			
			cout<<"\nIteracion "<<iteraciones<<endl;
			cout<<"x"<<iteraciones<<" = "<<x1<<"\n"
			<<"f(x"<<iteraciones<< ")="<<f(x1)<<"\n"
			<<"f'(x"<<iteraciones<<")="<<df(x1)<<"\n"
			<<"error = "<<error<<endl;
			
			//Si el error es menor a la tolerancia se termina el proigrama
			if(error<=epsilon){
				converge = true;
				break;
			}else{
				x0=x1;
				iteraciones++;
			}
		}
	}while(1);
	
	//Si converge (iteraciones<150) se muestra el último valor x1 obtenido
	if(converge){
		cout<<"\nPara una epsilon con valor de "<<epsilon<<" la raiz de f es: "<<x1<<endl;
		
	} else{
		cout<<"\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas..."<<endl;
	}
	return 0;
}

