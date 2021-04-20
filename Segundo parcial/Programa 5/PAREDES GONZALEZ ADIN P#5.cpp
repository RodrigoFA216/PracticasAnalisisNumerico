
#include <iostream>
#include <cmath>

using namespace std;

double x0, x1, xi, error;

int iteraciones = 0;


double funcion(double x) {
return pow(x,3)+2*pow(x,2)+10*x-20;
}

double errorAbsoluto(double viejo, double nuevo) {
 return abs((nuevo - viejo) / nuevo) * 100;
}

double Secante(double x0, double x1, double exactitud) {

 do {

 xi = x1 - ((funcion(x1)*(x0-x1)) / (funcion(x0)-funcion(x1)));
 error = errorAbsoluto(x1, xi);

 x0 = x1;
 x1 = xi;

 iteraciones++;

 
 } while (error > exactitud);


 return x1;
}

int main() {
cout<<"Metodo de la Secante"<<endl;
 double res = Secante(0, 1, 0.00001);
 cout << "La raiz es: " << res << "\n";
 cout << "Iteraciones: " << iteraciones;

 return 0;
}
