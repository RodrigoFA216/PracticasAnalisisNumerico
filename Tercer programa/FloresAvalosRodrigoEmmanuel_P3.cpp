#include<iostream>
#include<math.h>

using namespace std;

int contador, it;
float gx, xi, error, aux;

void func(){
    for (int i = contador; i <= it + 1; i++)
    {
        contador++;
        aux=xi;
        gx=sqrt((xi + 5) / 2);
        xi=gx;
        cout<<"iteracion: "<<i<<endl;
        cout<<"xi= "<<aux<<" g(x)= "<<gx<<endl;
        error = abs(xi - aux);
        cout <<"El error es "<<error<<endl<<endl;
        if (error < 0.0001)
        {
            break;
        }
    }
}

main(){
    
    cout<<"El despeje que se va  aevaluar en este programa es f(x)=((x+5)/2)^(1/2)"<<endl;
    cout<<"ingrese el valor de X con el que quiere iniciar a operar"<<endl;
    cin>>xi;
    func();
    system("pause");
}