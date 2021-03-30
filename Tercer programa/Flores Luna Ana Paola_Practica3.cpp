#include <iostream>

#include <cstdlib>



using namespace std;



int lado;

int perimetro;



int main(){

    cout << "Ingrese la medida de un lado del cadrado" << endl;

    cin >> lado; // Aqui capturamos el lado

    perimetro=lado*4; // Hacemos la operacion

    cout << "El perimetro de su cuadrado es: " << perimetro << endl;

system("pause");

return 0;

}
