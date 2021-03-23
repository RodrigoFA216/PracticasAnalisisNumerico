//  Programa #1 Serie de Maclourin
//  Created by José Manuel Bernal Florencio
//  Grupo: 4CM11

#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

double e, s, r;
int a, i, x, f=1, k;

int factorial(int a)
{
    for(i=1;i<=a;i++)
    {
        f=f*i;
    }
    return f;
}

void error()
{
    r=e*100;
}

void elementos ()
{
    cout<<"Recuerda que entre mas numeros de elementos tomes, más preciso será el calculo para el  error..."<<endl<<endl;
    
    cout<<"Ingresa el numero de elementos: ";
    cin >>a;
}
    
int main()
{

    cout<<"      **** Serie de Maclourin ****"<<endl;
    cout<<"Alumno: Jose Manuel Bernal Florencio"<<endl<<endl;

    elementos();
    cout<<"Introduce el valor de x:  ";
    cin>>x;
    cout<<endl;
    
    for(k=0;k<a;k++)
    {
        e=1+x+pow(x,k)/factorial(k);
        s += e;
    }
    
    cout<<"El numero de elementos tomados fueron: "<<a<<endl;
    cout<<"El valor de p* es: "<<fixed<<setprecision(4)<<e<<endl;
    cout<<"El error porcentual para "<<x;
    cout<<" es de: "<<fixed<<setprecision(2)<<e*100<<" porciento"<<endl<<endl;
    
    
}



