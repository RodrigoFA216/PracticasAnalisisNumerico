#include <iostream>
#include <cmath>

using namespace std;
int A, B, t=5, i;
float xi, x, x2,x3,x4,x5;

int punto_fijo() {
	cout<<"De su ecuacion de 2do grado despejada: x=[(x+A)/B]^(1/2)\ninserte los valores de\nA:";cin>>A;
	cout<<"B:";cin>>B;
	cout<<"Valor de xi: ";cin>>xi;
			x=sqrt((xi+A)/B);
			x2=sqrt((x+A)/B);
			x3=sqrt((x2+A)/B);
			x4=sqrt((x3+A)/B);
			x5=sqrt((x4+A)/B);
	//1
		cout<<"It: 0";		cout<<"     xi: "<<xi;       cout<<"                g(xi): "<<x;		cout<<"\n";
	//2
		cout<<"It: 1";		cout<<"     xi: "<<x;       cout<<"          g(xi): "<<x2;		cout<<"\n";
	//3
		cout<<"It: 2";		cout<<"     xi: "<<x2;       cout<<"          g(xi): "<<x3;		cout<<"\n";
	//4
		cout<<"It: 3";		cout<<"     xi: "<<x3;       cout<<"          g(xi): "<<x4;		cout<<"\n";
	//5 
		cout<<"It: 4";		cout<<"     xi: "<<x4;       cout<<"          g(xi): "<<x5;		cout<<"\n";
		
		cout<<"Su error es de: "<<abs(x5-x4);
		system("pause");
	}
	

int main(){
	punto_fijo();
	
}





