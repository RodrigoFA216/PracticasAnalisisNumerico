#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	char salir;
	int n,i,r,s;
	float ftor, suma; 
	float a[30][30], b[30], x[30];
	cout<<setprecision(4); cout<<fixed;
	do
	 {
	 	cout<<"\n\t\t\t\t ° Metodo de Gauss °";
		cout<<"\n\n\tNo. de ecuaciones: ";
	 	cin>>n;
	 	cout<<"\n Coeficientes de las variables:\n";         // (#fila,#columna)
	 	for(i=0; i<n; i++)
	 	 {
	 		for(r=0; r<n; r++)
	 		{
	 			cin>>a[i][r];
			 }
		 }
		 cout<<"\n Terminos Indep. :\n"; 
		  for(i=0; i<n; i++)
		   {
		   	cin>>b[i];
		   }
		  for(s=0; s<n; s++)
		  {
		  	for(i=s+1; i<n; i++)
		  	{
		  		ftor=a[i][s]/a[s][s];
		  		for(r=s; r<n; r++)
		  		 {
		  		   a[i][r]=a[i][r]-ftor*a[s][r];
				 }
				 b[i]=b[i]-ftor*b[s];
			}
		  }
		x[n-1]=b[n-1]/a[n-1][n-1];
		for(i=n-2; i>=0; i--)
		  {
		  	suma=b[i];
		  	for(r=i+1; r<n; r++)
		  	   {
		  	 	suma=suma-a[i][r]*x[r];
			   }
			x[i]=suma/a[i][i];
		  }
		  cout<<"\n Matriz Escalonada\n";
		  for(i=0; i<n; i++)
		   {
		   	for(r=0; r<n; r++)
		   	    {
		   	 	cout<<setw(12)<<a[i][r];
				}
				cout<<setw(12)<<b[i]<<"\n";
		   }
		   cout<<"\n Solucion \n";
		   for(i=0; i<n; i++)
		    {
		    	cout<<"\t"<<x[i]<<"\n";
			}
		   cout<<"\n\n\tDesea salir? si (s) / no (n) ";
		   cin>>salir;
	 } 
	 while (salir!='s' && salir!='S');
	 return 0; 
}
