#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    // definimos la variables a usar tipo float
    float evaluacion, dato_inicial, dato_final, dato_medio, Num_veces, error, Xm_anterior;

    // pedimos Xi,Xd y las veces de iteracion//

    cout << "Ingresa el valor inicial del intervalo" << endl;
    cin >> dato_inicial;
    cout << "Ingresa el valor final del intervalo" << endl;
    cin >> dato_final;
    cout << "Cuantas iteraciones vas a necesitar\n";
    cin >> Num_veces;
    cout << "\n\n\n";
    //iniciamos un for para hacer los calculo con respecto a las iteraciones solicitadas//

    for (int i = 1; i < Num_veces + 1; i++)
    {

        //calculamos xm=(xi+xd)/2
        dato_medio = (dato_inicial + dato_final) / 2;
        //con respecto al resultado de dato_medio(Xm) evaluamos la funcion//
        evaluacion = pow(dato_medio, 3) + (2 * pow(dato_medio, 2)) + (10 * dato_medio) - 20;

        //mostraremos en pantalla Xi,Xd y Xm
        cout << "#" << i << "\nEl valor de Xi: " << dato_inicial;
        cout << "\tEl valor de Xd: " << dato_final;
        cout << "\tEl valor de Xm: " << dato_medio << endl;
        cout << "____________________________________________" << endl;
        //con respecto al la evaluacion de la funcion vamos a asignar a xi o xd su nuevo valor//

        if (evaluacion > 0) //si la evaluacion es mayor que 0 a Xd se le asignara el valor de Xm//
        {
            dato_final = dato_medio;
        }
        else // caso contrario que la evaluacion se menor que 0 se le asginara a xi el valor de xm//
        {
            dato_inicial = dato_medio;
        }

        error = abs(dato_medio - Xm_anterior); //calcularemos el error para saber cuando se tiene que detener las iteraciones//
        Xm_anterior = dato_medio;              //esta varaible guardara el valor de xm de la iteracion anterior//

        //cuando el valor de error sea menor que e=0.001 se detendra el programa//
        if (error < 0.001)
        {
            break;
        }
    }
}
