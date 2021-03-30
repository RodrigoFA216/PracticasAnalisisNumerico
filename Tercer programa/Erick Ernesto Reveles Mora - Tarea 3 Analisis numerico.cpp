#include <iostream>
#include <cmath>
//no le voy a mentir profe, este codigo esta muy feo y no estoy orguilloso de el, pero tuve muchas tareas y por salud mental decidi hacer un codigo tan complejo y basandome en uno de un compa�ero que tuvo el semstre pasado
using namespace std;

const double ErrorAceptable=0.001;

double FormulaAIngresar(double x) {
  return sqrt((x+5)/(2));//no se puede digitar, para ver que despeje quiere, debe cambiarlo desde el codigo
}

int main() {
	double x=0, GdeX_ValorARestar=1.5, NumeroDeIteraciones=0, Error=0, i=0;
	cout<<"Cuantas Iteraciones quieres?: "<<endl;
	cin>>NumeroDeIteraciones;
	cout<<endl;

	while(true){
    	x=FormulaAIngresar(x);
    
    if ((fabs(x-GdeX_ValorARestar))<ErrorAceptable){
      break;
    }
    cout<<"Valor de Xi: "<<x;
    Error=x-GdeX_ValorARestar;
    cout<<" El error eso: "<<Error<<endl;
    i++;
    GdeX_ValorARestar=x;
    
    if (i>NumeroDeIteraciones) {
      cout<<"Metodo Fallido"<<endl;
	  cout<<"Esta funcion no sirve"<<endl;
      break;
    }
  }
  system("pause");
  return 0;
}
