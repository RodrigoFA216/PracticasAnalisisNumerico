#include <iostream>
#include <iomanip> 
#include <cmath>

#define P 5

using namespace std;

double f(double x);
void impPuntos(double a, double b);

int main()
{
   cout << setprecision(P); 
   
   double a, b, e;
   
   cout << "\nMetodo de biseccion"<< endl;
   cout << "\nInserta el intervalo de a y b [a, b] para x^3+2x^2+10x-20" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   impPuntos(a, b);
   
   cout << "\nEscoge los intervalos donde a y b no tengan los mismos signos" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   
   
   float xr; 
   
   
   
   if (f(a) * f(b) > 0) {
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
      
   } else {
      cout << "Error = ";
      cin >> e;
      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {
         xr = (a + b) / 2.0;
         cout << a << "\t" << b << "\t" << xr << "\t";
         cout << f(a) << "\t" << f(b) << "\t" << f(xr)<< "\t" << xr << endl;

         
         if (abs(f(xr)) <= e) { 
         
            cout << "\n\nPara un error de: " << e << " la raiz de f es " << endl;
         
            break;
            
         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }
         
      } while (1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x) 
{
   return pow(x,3)+2*pow(x,2)+10*x-20;
}

#define inter 10
void impPuntos(double a, double b)
{
   int puntos = inter + 1;
   
   double ancho = (b - a) / inter;
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
