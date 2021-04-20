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
   
   double v1, v2, tolerancia,mistake,iterador;
   int x3,x2,x,n,i=1;
   
   cout << "\nCalculo de las raices " << endl;
	cout << "\ningresa la ecuacion N x^3+ N x^2 + N x + N = 0\t toma en cuenta el signo\n";
    cout << "\nvalor de x^3 = "; cin >> x3;
    cout << "\nvalor de acompaña a x^2 = "; cin >> x2;
    cout << "\nvalor de acompaña a x = "; cin >> x;
    cout << "\nvalor de la constante = "; cin >> n;
    system("cls");
   cout << "\nIngrese el intervalo inicial [v1, v2] para tabular" << endl;
   cout << "\nv1 = ";
   cin >> v1;
   
   cout << "v2 = ";
   cin >> v2;
   cout << "\n\tx\tF(x)\n\n";
   for (int i = v1; i <=v2 ; i++) 
   {
      cout << "\t" << i << "\t" << f(i,x3,x2,x,n) << "\t\t\n";
   }
   
   cout << "\nElija intervalo" << endl;
   cout << "\nv1 = ";
   cin >> v1;
   
   cout << "v2 = ";
   cin >> v2;

   float xr=0,xr1; 
   
   if (f(v1,x3,x2,x,n) * f(v2,x3,x2,x,n) > 0) {
      
      cout << "\nNo aplica el metodo de la biseccion\n";
      cout << "porque f(" << v1 << ") y f(" << v2 << ") son signos iguales" << endl;
      
   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;
      system("cls");
      cout << "\nit\ta\tb\t\txm\tf(xm)\t\terror\n" << endl;
      iterador=((log(v1)-log(tolerancia))/log(2))+1;
      do {
	  
	  	xr1=xr;
         xr = (v1 + v2) / 2.0;
         
		 mistake=fabs(xr1-xr);
         cout <<i << "\t"<< v1 << "\t" << v2 << "\t\t" << xr << "\t";
         cout  << f(xr,x3,x2,x,n) << "\t\t" << mistake << endl;
         i++;
        iterador--;
         if (abs(f(xr,x3,x2,x,n)) <= tolerancia) { 
         
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << iterador << endl;
         
            break;
            
         } else {
            if (f(xr,x3,x2,x,n) * f(v1,x3,x2,x,n) > 0) {
               v1 = xr;
            } else if (f(xr,x3,x2,x,n) * f(v2,x3,x2,x,n) > 0) {
               v2 = xr;
            }
         }
         
      } while (iterador>1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}


