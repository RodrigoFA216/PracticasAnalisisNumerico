#include <stdio.h>
#include <math.h>
//huerta mellado francisco javier 4cm11
#define RAIZ(x) ((x)+2) 
 
int main() {
float xi, xd, xm, xa, ea;
int iteraciones;
printf("Limite superior de la raiz: ");
scanf("%f", &xi);
printf("Limite inferior de la raiz: ");
scanf("%f", &xd);
 
iteraciones = 0;
xa = 0.0;
ea = 0;
printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xi", "Xd", "Xm", "ea");
 
do{
iteraciones++;
xm = (xi + xd) / 2;
if(iteraciones >= 2) {
ea = ((xm - xa) / xm) * 100;
}
ea = fabs(ea); // Calculamos el valor absoluto del número
printf("%12d %10f %10f %10f %10f\n", iteraciones, xi, xd, xm, fabs(ea));
xa = xm;
if(RAIZ(xm) > 0) {
xi = xm;
} else{
xd = xm;
}
 
} while(ea > 0.5 || (ea == 0.0 && iteraciones == 1));
 
printf("\nLa raiz es de f(x) = x + 2; es: %f\n", xm);
 
return 0;
}
