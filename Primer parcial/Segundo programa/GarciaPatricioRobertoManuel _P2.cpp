//Garcia Patricio Roberto Manuel
#include <iostream>
#include <iomanip> 
#include <cmath>
#include<stdlib.h>

#define PRECISION 6

using namespace std;

double f(double,int,int,int,int);

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double a, b, tol,error,it;
   int x3,x2,x,n,i=1;
   
   cout << "\nCalculo de las raices por metodo de biseccion" << endl;
	cout << "\nIngresa la ecuacion N x^3+ N x^2 + N x + N = 0\n Tomar en cuenta si es positivo o negativo\n";
    cout << "\nConstante de x^3 = "; cin >> x3;
    cout << "\nConstante de x^2 = "; cin >> x2;
    cout << "\nConstante de x = "; cin >> x;
    cout << "\nConstante = "; cin >> n;
    system("cls");
   cout << "\nDigite el rango de valores para tabular [valor1,valor2]" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   cout << "\n\tx\tF(x)\n\n";
   for (int i = a; i <=b ; i++) 
   {
      cout << "\t" << i << "\t" << f(i,x3,x2,x,n) << "\t\t\n";
   }
   
   cout << "\nElija el intervalo" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;

   float xr=0,xr1; 
   
   if (f(a,x3,x2,x,n) * f(b,x3,x2,x,n) > 0) {
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienes el mismo signo" << endl;
      
   } else {
      cout << "Tolerancia = ";
      cin >> tol;
      system("cls");
      cout << "\nit\t\ta\t\t\tb\t\t\txm\t\tf(xm)\t\t\terror\n" << endl;
      it=((log(a)-log(tol))/log(2))+1;
      do {
	  
	  	xr1=xr;
         xr = (a + b) / 2.0;
         
		 error=fabs(xr1-xr);
         cout <<i << "\t\t"<< a << "\t\t\t" << b << "\t\t\t" << xr << "\t\t";
         cout  << f(xr,x3,x2,x,n) << "\t\t" << error << endl;
         i++;
         it--;
         if (abs(f(xr,x3,x2,x,n)) <= tol) { 
         
            cout << "\n\nPara una tolerancia " << tol << " la raiz de f es " << it << endl;
         
            break;
            
         } else {
            if (f(xr,x3,x2,x,n) * f(a,x3,x2,x,n) > 0) {
               a = xr;
            } else if (f(xr,x3,x2,x,n) * f(b,x3,x2,x,n) > 0) {
               b = xr;
            }
         }
         
      } while (it>1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}


