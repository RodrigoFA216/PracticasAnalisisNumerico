#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
float fun (float x);
int main() {
 float error,x0,x1,x2,Ea;
 printf ("Metodo Secante");
 printf ("\nDigite el primer valor ");
 scanf ("%f",&x0);
 printf ("Digite el segundo valor ");
 scanf ("%f",&x1);
 printf ("Digite el error ");
 scanf ("%f",&error);
 Ea=error+1;
 while (Ea>error)
 {x2=(x1-((x0-x1)/(fun(x0)-fun(x1))*fun(x1)));
 printf ("%f \n",x2);
 Ea=(fabs (x1-x2));
 x0=x1;
 x1=x2;
 }
 printf ("la raiz es:%f \n",x2);
 return 0;
}
float fun(float x)
{float f;
f=pow(x,3)+2*pow(x,2)+10*x-20;
return f;
}
