#include <iostream>                                                                   //Martell Madrigal Emily
#include <cmath>    //almacena funciones para poder realizar operaciones matemáticas
#include <iomanip> //setprecision

#define PRECISION 6

using namespace std;

double f(double x);
void imprimePuntos(double a, double b);                   

int main()
{
   cout<<setprecision(PRECISION); //Establecemos la precisión
   
   double a, b, error;

   cout<<"\t\t ° Metodo de Biseccion °"<<endl;
   cout<<"\nCalculo de las raices de una funcion."<<endl;
   cout<<"\nIngrese el intervalo inicial [a, b]"<<endl;
   cout<<"\na = ";
   cin>>a;
   cout<<"b = ";
   cin>>b;
   
   imprimePuntos(a, b);
   
   cout<<"\nEscoja el intervalo adecuado"<<endl;
   cout<<"\na = ";
   cin>>a; 
   cout<<"b = ";
   cin>>b;
   
   // [a, b]
   float rf; // raiz de la función
   
   /*
   cout<<"\nf("<<a<<")="<<f(a)<<endl;
   cout<<"f("<<b<<")="<<f(b)<<endl;
   */
   
   if(f(a)*f(b)>0) 
   {
      cout<<"\n\t\tNo se puede aplicar el metodo de biseccion "<<"porque f("<<a<<") y f("<<b<<") tienen el mismo signo."<<endl;
      
   } else
     {
      cout<<"Error = ";
      cin>>error;
      cout<<"\n\t a \t\tb \t\tx \t\tf(a) \t\tf(b) \t\tf(x)\n"<<endl;
      do 
	  {
         rf=(a+b)/2.0;
         cout<<"\t"<<a<<"\t\t"<<b<<"\t\t"<<rf<<"\t\t"<<f(a)<<"\t"<<f(b)<<"\t"<<f(rf)<<endl;

         // se ve si cumple o no cumple
         if(abs(f(rf))<=error) 
		 { //rf sería la raiz de f
            cout<<"\n\nPara un error "<<error<<" la raiz de f es "<<rf <<endl;
            break;
         } 
		 else 
		 {
            if(f(rf)*f(a)>0) 
			{
               a=rf;                          //f(a), f(b) y f(x) son las imagenes conrespondientes a 'a', 'b' y 'x' 
            } 
			else if(f(rf)*f(b)>0) 
			{
               b=rf;
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
   return exp(-3*x)-cos(7*x)-0.5;
}

#define INTERVALOS 12
void imprimePuntos(double a, double b)
{
   int puntos=INTERVALOS+1;   
   double ancho=(b-a)/INTERVALOS;   
   cout<<"\n";
   cout<<"\tx \tf(x)\n"<<endl;
   for(int i=0; i<puntos; i++) 
   {
      cout<<"\t"<<a<<"\t"<<f(a)<<endl;
      a=a+ancho;
    }
}
