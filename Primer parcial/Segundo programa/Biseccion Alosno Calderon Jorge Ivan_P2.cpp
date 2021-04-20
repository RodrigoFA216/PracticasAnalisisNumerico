#include <iostream>
#include <cmath>

float funcion(float x){
     float y=pow(x,3)+(2*pow(x,2))+(10*x)-20;
     return y;
}
int main() {
     float xi = 1;
     float xd = 2;
     int n = 10;
     float xm, xm1;
     float e;
     std::cout << "x^3+2x^2+10x-20" << '\n';
     for (int i = 1; i <= n; i++) {
          xm = (xd+xi)/2;
          e = xm-xm1;
          xm1 = xm;
    
          std::cout<<"it: "<<i<<" |xd: "<<xd<<" |xi: "<<xi<<" |xm: "<<xm<<" |f(Xm): "<<funcion(xm)<<std::endl;
          
          if (funcion(xm)>0) {
               xd=xm;
          }
          if (funcion(xm)<0) {
               xi=xm;
          }
     }
}
