#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <limits>

using namespace std;

double VerificarDoub();
int VerificarInt();
double menu(double x);

int main(){
	double a;
	double b;
	double x;
	int cont = 0;
	bool c = false;
	double fx;
	double gx;
	double xd;
	double e;
	std::cout << "ingrese x0: " << '\n';
	std::cin >> x;
	std::cout << "ingrese el error" << '\n';
	std::cin >> e;
	std::cout << "ingrese f(x): " << '\n';
	fx = menu(x);
	std::cout << "ahora vamos a seguir con g(x), presione una tecla" << '\n';
	getch();
	system("cls");
	std::cout << "ingrese g(x):" << '\n';
	gx = menu(x);
	xd = gx;
	std::cout << "ahora vamos a seguir con los valores de convergencia, presione una tecla" << '\n';
	getch();
	system("cls");
	a = x - xd;
	if (a<0){
		a *=-1;
	}
	while(c!=true){
		std::cout << "la nueva x0 va a ser: " << xd << '\n';
		x = xd;
		std::cout << "vuleva a ingresar la misma funcion de g" << '\n';
		gx = menu(x);
		xd = gx;
		a = x - xd;
		if (a<0){
			a *=-1;
		}
		b = a;
		if (a<=e) {
			std::cout << "la funcion g(x) converge en g(" << xd << ")" << '\n';
			c=true;
		}
		if(a>e&&a>b){
			std::cout << "no va a converger porque el error de las funciones se aleja del error ingresado" << '\n';
			c=true;
		}
	}
}

double menu(double x){
     double a, b;
     int opc = -1;
     double caja;

     std::cout << "1.- sqrt ( a )" << '\n';
     std::cout << "2.- a / b" << '\n';
     std::cout << "3.- a*b" << '\n';
     std::cout << "4.- a+b" << '\n';
     std::cout << "5.- a-b" << '\n';
     std::cout << "6.- sen(a)" << '\n';
     std::cout << "7.- cos(a)" << '\n';
     std::cout << "8.- tan(a)" << '\n';
     std::cout << "9.- a^b" << '\n';
     std::cout << "10.- pi" << '\n';
     std::cout << "11.- e" << '\n';
     std::cout << "12.- X" << '\n';
     std::cout << "13.- numero" << '\n';

     std::cout << "ingrese una opcion para la funcion" << '\n';
     while(opc < 0 || opc > 13){
          opc = VerificarInt();
          if( opc < 0 || opc > 14 ){
               std::cout << "ingrese un valor aceptado" << '\n';
          }
     }

     if (opc == 1) {//raiz
          std::cout << "raiz_ ingrese un valor para a:" << '\n';
          caja = menu(x);
		return sqrt(caja);
     }
     if (opc == 2) {//division
          std::cout << "division_ ingrese un valor para a" << '\n';
          a = menu(x);
          std::cout << "division_ ingrese un valor para b" << '\n';
          b = menu(x);
		caja = a/b;
		return caja;
     }
     if (opc == 3) {//multiplicacion
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
          std::cout << "ingrese un valor para b" << '\n';
          b = menu(x);
		caja = (a)*(b);
		return caja;

     }
     if (opc == 4) {//suma
          std::cout << "suma_ ingrese un valor para a" << '\n';
          a = menu(x);
          std::cout << "suma_ ingrese un valor para b" << '\n';
          b = menu(x);
		caja = a+b;
		return caja;
     }
     if (opc == 5) {//resta
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
          std::cout << "ingrese un valor para b" << '\n';
          b = menu(x);
		caja = a-b;
		return caja;
     }
     if (opc == 6) {//seno
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
		caja = sin(a);
		return caja;
     }
     if (opc == 7) {//coseno
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
		caja = cos(a);
		return caja;
     }
     if (opc == 8) {//tangente
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
		caja = tan(a);
		return caja;
     }
     if (opc == 9) {//exponente
          std::cout << "ingrese un valor para a" << '\n';
          a = menu(x);
          std::cout << "ingrese un valor para b" << '\n';
          b = menu(x);
		caja = pow(a, b);
		return caja;
     }
     if (opc == 10) {//pi
          return 3.1415;
     }
     if (opc == 11) {//e
          return 2.7182;
     }
     if (opc == 12) {//x
		return x;
     }

     if (opc == 13) {//numeros
          std::cout << "ingrese un numero" << '\n';
          a = VerificarDoub();
		return a;
     }
}

int VerificarInt(){
     int variable;
     if(!(cin >> variable)){
          cout << "ingrese un valor aceptado" << '\n';
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          variable = VerificarInt();
     }

     return variable;
}

double VerificarDoub(){
     double variable;
     if(!(cin >> variable)){
          cout << "ingrese un valor aceptado" << '\n';
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          variable = VerificarInt();
     }

     return variable;
}
