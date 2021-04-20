#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{

     system("color 3E");

     float x, it, i, e = 2.7182, euler;
     float valorAX;
     float resultado, aux;
     float p, frl, dv, EP, i1;

     cout << "\n Programa para calcula Mcladjagdad"
          << "\n\n";

     cout << "Ingresa el valor de X:\n "
          << "x= ";
     cin >> x;

     cout << "Cuantas iteraciones se haran?:\n "
          << "Iteraciones= ";
     cin >> it;
     euler = pow(e, x);
     cout << "El valor de "
             "e^x"
             " es: "
          << euler
          << "\n\n";

     for (i = 1; i < it + 1; i++)
     {
          if (i == 1)
          {

               valorAX = 1;
               cout << "Tu valor aproximado es: " << valorAX
                    << "\n\n";
          }

          else if (i == 2)
          {
               valorAX = 1 + x;
               cout << "Tu valor aproximado es: " << valorAX
                    << "\n";
               EP = ((valorAX - EP) / valorAX) * 100;
               cout << "EL error es: " << EP << "%\t";
          }
          else if (i > 2)
          {

               p = pow(x, i - 1);
               frl = 1;
               for (int j = i - 1; j >= 1; j--)
               {
                    frl = frl * j;
               }

               dv = p / frl;
               valorAX = (aux + dv);
               EP = ((valorAX - EP) / valorAX) * 100;
               cout << "Tu valor aproximado es: " << valorAX
                    << "\n";
               cout << "EL error es: " << EP << "%\t";
          }
          EP = valorAX;
          aux = valorAX;
     }
}
