#include <iostream>
#include <complex>
#include <stdlib.h>
#include <math.h>

void portada()
{
	printf("\t\t\t\t\tInstituto Politecnico Nacional\n");
	printf("\t\t\t\tEscuela Supérior de Ingeneria Electrica y Mecanica\n");
	printf("\t\t\t\t\t\tUnidad Culhuacan\n");
	printf("\n\n\n\n\n\n");
	printf("Analisis Numerico\n");
	printf("Programa: Serie de Maclaurin\n");
	printf("Profesor:Olivares Mercado Jesus\n");  
	printf("Grupo:4CM11\n");
	printf("Alumno: Mosco Garcia Juan Eduardo\n\n");
	system("pause");
}

int it, i, j, z, k, coe,l,f,n,u,op,sw,maxit;
int g[20], M[20],P[20];

double xi, xa, gxi,e,p,b,a,x,fa,fb,fp,tol,x0;

using namespace std;

int main()
{
	portada();
	cout<<"\n\aPOLINOMIO A DESARROLLAR\n";
	cout<<"Digite el grado de la ecuacion:";cin >>n;
	/*lectura del polinomio*/
	for (i=0; i < n; i++ )
	{
		cout<<"Digite el coeficiente" <<i<<": ";
		cin >>g[i];
	}
	system("cls");
	cout <<"El polinomio es: \n";
	for(j=0;j<=n;j++)
	{
		cout<<g[j]<<"x^"<<j<<" + ";
	}
	cout <<("\n Ingrese el valor de x0:");
	cin>>x0;
	cout <<("\n Ingrese Maxima iteraciones:");
	cin>>maxit;
	cout <<("\n Ingrese el valor del Error:");
	cin>>tol;
	sw = 0;
	it = 0;
	xa = 0;
	
	while ((sw==0)&& (it <=maxit))
	{
		gxi =0;
		for (j=0;j <=n;j++)
		{
			gxi = gxi + g[j]*pow(x0,j);
		}
		xi = gxi;
		e = fabs(xi-x0);
		if(e <= tol)
		{
			sw = 1;
		}
		else {
			it = it +1;
			x0 = xi;
		}
		cout <<it <<"	"<<x0<<"	"<<gxi<<"	"<<e<<"		"<<"\n";
		
	}
	if(sw == 1)
	{
		cout <<"La raiz es: "<<xi;
	}else{
		cout <<"No converge";
	}
	system("pause");
	
	 
}
