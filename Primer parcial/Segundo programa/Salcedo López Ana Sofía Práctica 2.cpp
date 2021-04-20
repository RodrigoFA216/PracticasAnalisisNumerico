/*PRÁCTICA 2: Calculo de las raíces de una función utilizando el Método de Bisección
Salcedo López Sofía
Análisis numérico 4CM11*/

#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 6

using namespace std;

double f(double x);
void imprimePuntos(double a, double b);

int main()
{
   cout << setprecision(PRECISION); // Establecemos la precisión
   
   double xi, xd, epsilon;
   double valor_ant, valor_act;
   
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion" << endl;
   cout << "\nIngrese el intervalo inicial [xi, xd]" << endl;
   cout << "\nxi = ";
   cin >> xi;
   
   cout << "xd = ";
   cin >> xd;
   
   imprimePuntos(xi, xd);
   
   cout << "\nEscoja el intervalo adecuado" << endl;
   cout << "\nxi = ";
   cin >> xi;
   
   cout << "xd = ";
   cin >> xd;
   
   // [xi, xd]
   float xm; // raiz de la función
   double error = abs(valor_act - valor_ant);
  
   
   if (f(xi) * f(xd) > 0) {
      
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << xi<< ") y f(" << xd << ") tienen el mismo signo" << endl;
      
   } else {
   	int j=0;
      cout << "Valor de Epsilon = ";
      cin >> epsilon;
      fflush(stdin);
      cout << "\nIteracion\tXI\tXD\tXM\tf(XM)\t\tError\n" << endl;
      
      	
      	do{
		  
		  
         xm = (xi + xd) / 2.0;
         valor_act = xm;
        error = abs(valor_ant - valor_act);
	 
	 	
         cout <<j+1<<"\t\t"<< xi << "\t" << xd << "\t" << xm<<"\t";
         cout << f(xm)<<"\t"<<error<<endl;
	
        
        
    	
			
            if (f(xm) > 0) {
    			
               xd = xm;
               valor_act = xm;
               valor_ant = xd;
               j++;
			   }
        	   else if (f(xm) <0) {
               xi = xm;
               valor_act=xm;
               valor_ant = xi;
               j++;
               fflush(stdin);
            }
        
	
      } while (error>epsilon);

   }

   cin.get();
   cin.get();
   return 0;
}


double f(double x) 
{
   return pow(x,3)+2*pow(x,2)+10*x-20;
}

#define INTERVALOS 4
void imprimePuntos(double a, double b)
{
   int puntos = INTERVALOS + 1;
   
   double ancho = (b - a) / INTERVALOS;
   
   cout << "\n";
   cout << "\tx\tf(x)\n" << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}
