#include <iostream>
#include <cmath>
#define epsilon 0.001
//angel iñaki hernandez brito  4cm11 metodo de biseccion
double xi=0;
double xd=0;
double xm = 0;
double xma = 0;
double error = 0;

double funcion(double x);
void find_xi_xd();

int main() {

     std::cout << "metodo de biseccion para la funcion x^3+2x^2+10x-20" << '\n';
     find_xi_xd();
     double n = (log(xd-xi)-log(epsilon))/log(2);
     std::cout << "iteracion" << '\t' <<  "xi" << '\t' <<'\t' << "xd" << '\t' << '\t' << "xm" << '\t' << '\t' << "f(xm)" << '\t' << '\t'<< "error" << '\n';
     for (size_t i = 1; i <= n+1; i++) {
          xm = (xd+xi)/2;
          error = xm-xma;
          if(error < 0){
               error *= -1;
          }
          std::cout << i << '\t' << '\t' <<  xi << '\t' <<'\t' << xd << '\t' << '\t' << xm << '\t' << '\t' << funcion(xm) << '\t' << '\t' << error << '\n';
          xma = xm;
          if (funcion(xm)>0) {
               xd=xm;
          }
          if (funcion(xm)<0) {
               xi=xm;
          }
     }
}

double funcion(double x){
     double y=pow(x,3)+(2*pow(x,2))+(10*x)-20;
     return y;
}

void find_xi_xd(){
     int x=0;
     while (x<1) {
          for (double i = 3; i > -3; i--) {
               if ( funcion(i)>0 && funcion(i-1)<0 ) {
                    xd=i;
                    xi=i-1;
                    x=1;
               }
               if (funcion(i)<0&&funcion(i-1)>0) {
                    xi=i;
                    xd=i-1;
                    x=1;
               }
          }
     }
}
