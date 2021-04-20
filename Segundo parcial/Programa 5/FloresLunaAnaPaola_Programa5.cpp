 //MÉTODO DE LA SECANTE 
 
 #include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
//#include<iostream.h>
using namespace std;
double f(float Xi);
double f1(float Xr);

int main(void){
int SI=1;
do{
system("cls" );
float Xi=0,Ea=0,Xz=0,Xr=0,XT=0;
int cont=0;
printf("ttPRACTICA #5n" );
printf("t METODO DE LA SECANTEn" );
printf("tfuncion e^x-xn" );
printf("instroduce Xi:n" );
scanf("%f",&Xi);
printf("nnI Xi-1 Xi Xz f(Xi-1) f(Xi) Ean" );

do
{
Xr=(Xi-1);
// Xz= Xi-((f(Xi)*(Xr-Xi))/(f1(Xr)-f(Xi)));
Xz= Xi-(((Xi)-(Xr))/((f(Xi))-f1(Xr)))*(f(Xi));

Ea=fabs((Xz-Xi)/Xz)*100;
printf("%d %f %.5f %f %.5f %.5f %fn",cont,Xr,Xi,Xz,f1(Xr),f(Xi),Ea);
cont++;
Xi=Xz;
}
while(Ea>=0.01); //<---AQUI PUEDEN MODIFICAR EL PORCENTAJE DE ERROR DESEADO
printf("nnn" );
printf("DESEAS REALIZAR LA OPERACION OTRA VEZ? SI[1] NO[2]n" );
scanf("%d",&SI);
}
while(SI<=1);
system("PAUSE" );
}

double f(float Xi){
return (exp(-Xi))-Xi;
}


double f1(float Xr){
float n = (exp(-Xr))-Xr;
return n;
}
 
 
