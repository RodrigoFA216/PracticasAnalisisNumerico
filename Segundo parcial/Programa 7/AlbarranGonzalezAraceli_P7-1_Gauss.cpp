#include <iostream>
#include <iomanip>
using namespace std;

int main (){
	char salir;
	int n, i, j, k;
	float factor, suma;
	float a[30][30], b[30], x[30];
	cout<<setprecision(2); cout<<fixed;
	do{
		cout<<"No. de ecuaciones"; cin>>n;
		cout<<"\nCoeficientes de las variables: ";
		for (i=0; i<n; i++){
			for (j=0; j<n; j++){
				cin>> a[i][j];
			}
		}
		cout<<"\nTermino independiente: ";
		for (i=0; i<n; i++){
			cin>>b[i];
		}
		for (k=0; k<n-1; k++){
			for (i=k+1; i<n; i++){
				factor=a[i][k]/a[k][k];
				for(j=k; j<n; j++){
					a[i][j]=a[i][j] -factor * a[k][j];
				}
				b[i]=b[i]-factor * b[k];
			}
		}
		x[n-1]=b[n-1]/a[n-1][n-1];
		for(i=n-2; i>=0; i--){
			suma=b[i];
			for (j=i+1; j<n; j++){
				suma=suma-a[i][j]*x[j];
			}
			x[i]=suma/a[i][i];
		}
		cout<<"\nMatriz escalonada\n";
		for (i=0; i<n; i++){
			for (j=0; j<n; j++){
				cout<<setw(12)<<a[i][j];
			}
			cout<<setw(12)<<b[i]<<"\n";
			
		}
		cout<<"\nSolucion\n";
		for (i=0; i<n; i++){
			cout<<x[i]<<"\n";
		}
		cout<<"\nDeseas salir?  s/n "; cin>>salir;
	} while (salir!='s' && salir!='S');
	return 0;
}
