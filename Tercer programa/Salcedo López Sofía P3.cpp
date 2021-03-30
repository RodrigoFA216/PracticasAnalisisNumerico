#include<iostream>
#include<complex>

int it,i,j,z,k,coe,f,n,u,op,sw,maxit;
int g[50], M[20], P[20];
double xi,xa,gxi,e,p,b,a,x,fa,fb,fp,tol,x0;

using namespace std;
int main(){
	
	system("cls");
	cout<<"\a Despeje \n";
	cout<<"Digite el grado de la ecuacion: ";
	cin>>n;
	//Lectura del polinomio g(x)
	
	for(i=0;i<=n;i++){
		cout<<"Digite el coeficiente: "<<i<<": ";
		cin>>g[i];
	}
	system("cls");
	cout<<"El polinomio es: \n";
	for(j=0;j<=n;j++){
		cout<<g[j]<<"x^"<<j<<" + ";
	}
	cout<<("\nIngrese el valor de x0 ");
	cin>>x0;
	cout<<("\nIngrese el numero maximo de iteraciones:  ");
	cin>>maxit;
	cout<<("\nIngrese la tolerancia: ");
	cin>>tol;
	sw=0;
	it=0;
	xa=0;
	
	while((sw==0)&&(it<=maxit)){
		gxi=0;
		for(j=0;j<=n;j++){
			gxi=gxi+g[j]*pow(x0,j);
		}
		xi=gxi;
		e=abs(xi-x0);
		if(e<=tol){
			sw=1;
		}else{
			it=it+1;
			x0=xi;
		}
		cout<<it<<"   "<<x0<<"   "<<gxi<<"   "<<"   "<<"\n";
	}
	if (sw==1){
		cout<<"La raiz es: "<<xi;
	}else{
		cout<<"No converge";
	}
	system("pause");
}
