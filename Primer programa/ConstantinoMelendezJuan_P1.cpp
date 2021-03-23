#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

float factorial(float num) //resiviendo i-1
{
  float fac = num; //fac = i-1
  for (int i = num - 1; i >= 1; i--)
  {
    fac = fac * i;
  }
  return fac;
}

int main()
{
  float potencia, iteraciones, euler, resultado, fac, x, aux = 0, div, ErroP;
  cout << "Practica 1: Metedo de Mclaurin" << endl;
  cout << "Ingresa el valor de x" << endl;
  cin >> x;
  cout << "Ingresa el numero de iteraciones" << endl;
  cin >> iteraciones;

  euler = exp(x);

  for (int i = 1; i < iteraciones + 1; i++)
  {
    if (i == 1)
    {
      resultado = 1;
      cout << "Iteracion [" << i << "]: " << resultado << endl;
    }
    else if (i == 2)
    {
      resultado = 1 + x;
      ErroP = ((resultado - ErroP) / resultado) * 100;
      cout << "Iteracion [" << i << "]: " << resultado << "\t\t|El error Porcentual es: " << ErroP << "%" << endl;
    }
    else if (i > 2)
    {
      //(x^n/x!) operaciones
      potencia = pow(x, i - 1);
      fac = factorial(i - 1);
      div = potencia / fac;
      //--------------------------//
      resultado = aux + div;
      ErroP = ((resultado - ErroP) / resultado) * 100;
      cout << "Iteracion [" << i << "]: " << resultado << "\t\t|El error Porcentual es: " << ErroP << "%" << endl;
    }
    ErroP = resultado;
    aux = resultado;
  }
}
