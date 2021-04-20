#include <iostream>
#include <cmath>

using namespace std;
int A, B, C, D, x0, x1;
float x2,x3,x4,x5,E2, E3, E4, E5, f0, f1, f2, f3, f4, i1, i2, i3, i4;

int newton() {
	cout<<"Inserte su funcion: Ax^3+Bx^2+Cx+D\nA: ";cin>>A;
	cout<<"B: ";cin>>B;
	cout<<"C: ";cin>>C;
	cout<<"D: ";cin>>D;
		
	cout<<"Valor de x0: ";cin>>x0;
	cout<<"Valor de x1: ";cin>>x1;
	
		i1=x1-x0;
		f1=A*x1*x1*x1+B*x1*x1+C*x1+D;
		f0=A*x0*x0*x0+B*x0*x0+C*x0+D;
		x2=x1-((i1*f1)/(f1-f0));
		
		i2=x2-x1;
		f2=A*x2*x2*x2+B*x2*x2+C*x2+D;
		f1=A*x1*x1*x1+B*x1*x1+C*x1+D;
		x3=x2-((i2*f2)/(f2-f1));
		
		i3=x3-x2;
		f3=A*x3*x3*x3+B*x3*x3+C*x3+D;
		f2=A*x2*x2*x2+B*x2*x2+C*x2+D;
		x4=x3-((i3*f3)/(f3-f2));
		
		i4=x4-x3;
		f4=A*x4*x4*x4+B*x4*x4+C*x4+D;
		f3=A*x3*x3*x3+B*x3*x3+C*x3+D;
		x5=x4-((i4*f4)/(f4-f3));
		
		E2=abs(x2-x1);
		E3=abs(x3-x2);
		E4=abs(x4-x3);
		E5=abs(x5-x4);

	//2
		cout<<"It x2: "<<x2;		               cout<<"		Error: "<<E2;		cout<<"\n";	
	//3
		cout<<"It x3: "<<x3;		               cout<<"		Error: "<<E3;		cout<<"\n";
	//4
		cout<<"It x4: "<<x4;		               cout<<"		Error: "<<E4;		cout<<"\n";
	//5
		cout<<"It x5: "<<x5;		               cout<<"		Error: "<<E5;		cout<<"\n";
	}
	

int main(){
	newton();
	
}





