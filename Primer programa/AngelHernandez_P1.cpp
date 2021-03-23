#include <iostream>
#include <cmath>
// angel iñaki hernandez brito 4cm11 serie de mclaurin
double serie(double n, int t);
int main() {

     double numero;
     int terminos;
     std::cout << "ingrese el valor de X para e^x :"; std::cin>>numero;
     std::cout << "ingrese el numero de terminos :"; std::cin>>terminos;

     for (size_t i = 0; i <= terminos; i++) {
          std::cout << " e^x en el termino " << i+1 << " = " << serie(numero, i) << '\n';
     }
     system("pause");
}

double serie(double n, int t){
     unsigned long long factorial = 1;
     int j = 1;
     double resultado = 0;
     for (int x = 0; x <= t; x++, j++) {
          resultado += pow(n,x)/factorial;
          factorial*=j;
     }
     return resultado;
}
