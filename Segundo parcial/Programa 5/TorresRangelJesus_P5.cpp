#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#define ERROR 0.001

using namespace std;

double calculaError(int t, double vant, double vact){
  double err = 0.0;
  switch (t){
    case 0 :
      err = vant - vact;
      break;
    case 1 :
      err = (vant - vact) / vant;
      break;
    case 2 :
      err = ((vant - vact) / vant) * 100;
      break;
  }
  return err;
}

double f(double x)
{
  return pow(x,2) - (2*pow(x,2)) + (10*x) - 20;
}

int counter;
double xa, xb, res, error;

double Secante(double x1, double x0)
{
  xa = x1;
  xb = x0;
  counter = 0;
  do{
    res = xa - ((f(xa) * (xb - xa)) / (f(xb) - f(xa)));
    error = calculaError(1, xa, res);
    xa = xb;
    xb = res;
    cout<<counter<<"\t\t"<<res<<"\t\t"<<error<<endl;
    counter ++;

    if(res != res)
	{
      cout << "La función se indetermina: " << '\n';
      return res;
    }
  }while(abs(error) > ERROR);
  
  cout <<"\n"<< counter <<"   interacion(es)." << '\n';
  return res;
}

int main(int argc, char const *argv[])
 {
 	cout << "\t\t\t\t\tJesus Torres Rangel\n ";
 	cout << "\t\t\t\t\tANALISIS NUMERICO\n ";
 	cout << "\t\t\t\t\tMETODO DE LA SECANTE\n\n ";
 	cout << "\t\t\tEcuacion: pow(x,2) - (2*pow(x,2)) + (10*x) - 20\n ";
    double x1, x0;
    cout << "Dame el valor de x1: ";
    cin >> x1;
    cout << "Dame el valor de x0: ";
    cin >> x0;
  
    cout<<"Iteraciones\t   Xi\t\t   Error\n\n";
    double raiz = Secante(x1, x0);
    cout << "La raiz es: " << raiz << '\n';

    return 0;
}
