/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/
#include <iostream>
#include <iomanip> 
#include <cmath>
#define Ep 4

using namespace std;

double f(double x);
void rangoo(double Xi, double Xd);

int main()
{
   cout << setprecision(Ep); 
   
   double Xi, Xd, Epsilon;
   
   cout << "\n\t\tMETODO BISECCION" << endl;
   cout << "Ingrese el intervalo(rango) [Xi, Xd]" << endl;
   cout << "Xi = ";
   cin >> Xi;
   cout << "Xd = ";
   cin >> Xd;
   
   rangoo(Xi, Xd);
   cout << "\nIntroduzca los valores correctos, es decir cuando exista un cambio de signo en f(x)" << endl;
   cout << "Xi = ";
   cin >> Xi;
   cout << "Xd = ";
   cin >> Xd;
	
   float Xm, n, nr, a, E=0;  // Para promedio 
   if (f(Xi) * f(Xd) > 0) 
     {   
      cout << "\n ---No se puede aplicar el metodo de la biseccion---\n";
      cout << "f (" << Xi << ") y f (" << Xd << ") tienen mismo signo" << endl;   
     } 
   else
	 {
      cout << "Introduzca valor de Epsilon = ";
      cin >> Epsilon;
      cout << "\nIt \t Xi \t Xd \t Xm \t f(Xi) \t \t f(Xd) \t \t f(Xm) \t\t E" << endl;
      	
		a= Xd-Xi;
      	n= ((log (a))-(log(Epsilon)))/log (2);
		nr= ceil(n);
		 for (int i=1; i<nr+1; i++)
		 
		 {
		 	E= abs(Xm-Xi);
			Xm = (Xi + Xd) / 2.0;
			
		cout << " " << i<< "\t" <<Xi<< "\t" << Xd<< "\t" <<Xm
			 << "\t" << f(Xi)<< "\t	" << f(Xd)<< "\t	" <<f(Xm)<< "\t	"<<E<<endl;
			
      
         if (abs(f(Xm)) <= Epsilon)
		  	 { 
                //E= abs(Xm-(f(Xm));
        	 } 
		 else 
		 	 { //Xd=Xm o Xi=Xm
             	if (f(Xm) * f(Xi) > 0) 
				 {
                 Xi = Xm;
            	 } 
				 else if (f(Xm) * f(Xd) > 0) 
				 {
               	 Xd = Xm;
            	 }
         	 }
      	 } 
	 }
   cin.get();
   cin.get();
   return 0;
}

double f(double x) 
	 {
     return pow(x,3)+2*pow(x,2)+10*x-20;
	 }

#define INTERVALOS 10
void rangoo(double Xi, double Xd)
	 {
	 int puntos = INTERVALOS + 1;
	 double ancho = (Xd - Xi) / INTERVALOS;
	 cout << "\n\t x \t f(x)" << endl;
	 for (int i = 0; i < puntos; i++) 
	 {
	 cout << "\t" << Xi << "\t" << f(Xi) << endl;
	 Xi = Xi + ancho;
   	 }
	 }

