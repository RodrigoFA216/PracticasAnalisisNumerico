#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 6

using namespace std;

double f(double,int,int,int,int);

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double a, b, tolerancia,error,ite;
   int x3,x2,x,n,i=1;
   
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
	cout << "\ningresa la ecuacion N x^3+ N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nnumero que acompaña a x^3 = "; cin >> x3;
    cout << "\nnumero que acompaña a x^2 = "; cin >> x2;
    cout << "\nnumero que acompaña a x = "; cin >> x;
    cout << "\nnumero que acompaña = "; cin >> n;
    system("cls");
   cout << "\nIngrese el intervalo inicial [a, b] para tabular" << endl;
   cout << "\na = ";
   cin >> a;
   
   cout << "b = ";
   cin >> b;
   cout << "\n\tx\tF(x)\n\n";
   for (int i = a; i <=b ; i++) 
   {
      cout << "\t" << i << "\t" << f(i,x3,x2,x,n) << "\t\t\n";
   }
   
   cout << "\nEscoja el intervalo adecuado" << endl;
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
      cin >> tolerancia;
      system("cls");
      cout << "\nit\ta\tb\t\txm\tf(xm)\t\terror\n" << endl;
      ite=((log(a)-log(tolerancia))/log(2))+1;
      do {
	  
	  	xr1=xr;
         xr = (a + b) / 2.0;
         
		 error=fabs(xr1-xr);
         cout <<i << "\t"<< a << "\t" << b << "\t\t" << xr << "\t";
         cout  << f(xr,x3,x2,x,n) << "\t\t" << error << endl;
         i++;
         ite--;
         if (abs(f(xr,x3,x2,x,n)) <= tolerancia) { 
         
            cout << "\n\nPara una tolerancia " << tolerancia << " la raiz de f es " << ite << endl;
         
            break;
            
         } else {
            if (f(xr,x3,x2,x,n) * f(a,x3,x2,x,n) > 0) {
               a = xr;
            } else if (f(xr,x3,x2,x,n) * f(b,x3,x2,x,n) > 0) {
               b = xr;
            }
         }
         
      } while (ite>1);
   }
   
   cin.get();
   cin.get();
   return 0;
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}


