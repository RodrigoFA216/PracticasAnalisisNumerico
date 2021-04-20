#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#define ERROR 0.000000001

using namespace std;

double calculaError(int t, double vant, double vact){
  double err = 0.0;
  switch (t){
    case 0:
      err=vant - vact;
      break;
    case 1:
      err=(vant - vact)/vant;
      break;
    case 2:
      err=((vant-vact)/vant)*100;
      break;
  }
  return err;
}

double f(double x){
  return (pow(x,3))+1;
}

int counter;
double xa, xb, res, error;

double Secante(double x1, double x0){
  xa=x1;
  xb=x0;
  counter=0;
  do{
    res=xa-((f(xa)*(xb-xa))/(f(xb)-f(xa)));
    error=calculaError(1, xa, res);
    xa=xb;
    xb=res;
    counter++;
    if(res!=res){
      cout<<"La función se indetermina: "<<endl;
      return res;
    }
  }
  while(abs(error)>ERROR);
  cout<<counter<<" interacion(es)."<<endl;
  return res;
}

int main(int argc, char const *argv[]) {
  double x1, x0;
  cout<<"Dame el primer valor semilla: ";
  cin>>x1;
  cout<<"Dame el segundo valor semilla: ";
  cin>>x0;

  double raiz = Secante(x1, x0);
  cout<<"La raíz es: "<<raiz<<endl;

  return 0;
}
