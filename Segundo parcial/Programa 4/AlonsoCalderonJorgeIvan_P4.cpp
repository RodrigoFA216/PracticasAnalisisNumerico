#include <iostream>
#include <cmath>

using namespace std;
int A, B, C, D, E, F, G, x0;
float x1, x2,x3, E1, E2, E3, f1, f2, f3, d1, d2, d3;

int newton() {
	cout<<"Inserte su funcion: Ax^3+Bx^2+Cx+D\nA: ";cin>>A;
	cout<<"B: ";cin>>B;
	cout<<"C: ";cin>>C;
	cout<<"D: ";cin>>D;
	
	cout<<"Inserte la derivada de su funcion: Ex^2+Fx+G\nE: ";cin>>E;
		cout<<"F: ";cin>>F;
		cout<<"G: ";cin>>G;
		
	cout<<"Valor de x0: ";cin>>x0;
		f1=A*x0*x0*x0+B*x0*x0+C*x0+D;
		d1=E*x0*x0+F*x0+G;
		x1=x0-(f1/d1);
		
		f2=A*x1*x1*x1+B*x1*x1+C*x1+D;
		d2=E*x1*x1+F*x1+G;
		x2=x1-(f2/d2);
		
		f3=A*x2*x2*x2+B*x2*x2+C*x2+D;
		d3=E*x2*x2+F*x2+G;
		x3=x2-(f3/d3);
		
		E1=abs(x1-x0);
		E2=abs(x2-x1);
		E3=abs(x3-x2);
		
		
	//1
		cout<<"It x1: "<<x1;		               cout<<"		Error: "<<E1;		cout<<"\n";
	//2
		cout<<"It x2: "<<x2;		               cout<<"		Error: "<<E2;		cout<<"\n";	
	//3
		cout<<"It x3: "<<x3;		               cout<<"		Error: "<<E3;		cout<<"\n";
	}
	

int main(){
	newton();
	
}





