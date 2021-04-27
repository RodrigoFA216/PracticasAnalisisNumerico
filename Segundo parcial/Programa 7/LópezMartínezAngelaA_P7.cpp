/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/

#include<iostream>
#include<iomanip>
#include <stdlib.h> 
using namespace std;
int main()
{
    int n,i,j,k;
    cout.precision(3); 
    cout.setf(ios::fixed);
    cout<< "\t\tMETODO GAUSS\n";
	cout<<"Introduzca numero de terminos de incognitas x1, x2, x3... \nTerminos= ";      
    cin>>n;
    float a[n][n+1],x[n];
    cout<<"Introduza los coeficientes correspondientes: \n";
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)    
            cin>>a[i][j];
    for (i=0;i<n;i++)
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    cout<<"\nMatriz introducida:\n";
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n;j++)
            cout<<a[i][j]<<setw(16);
        cout<<"\n";
    }    
    for (i=0;i<n-1;i++)
        for (k=i+1;k<n;k++)
            {
                double t=a[k][i]/a[i][i];
                for (j=0;j<=n;j++)
                    a[k][j]=a[k][j]-t*a[i][j];
            }
    cout<<"\n\nHaciendo metodo Gauss:\n";
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n;j++)
            cout<<a[i][j]<<setw(16);
        cout<<"\n";
    }
    for (i=n-1;i>=0;i--)
    {                   
        x[i]=a[i][n];   
        for (j=i+1;j<n;j++)
            if (j!=i)   
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
    }
    cout<<"\nSolucion: \n";
    for (i=0;i<n;i++)
        cout<<"X"<< i+1<<"= "<< x[i]<< endl;
    return 0;
}
