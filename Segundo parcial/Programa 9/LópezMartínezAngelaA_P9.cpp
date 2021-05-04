/*  LÓPEZ MARTÍNEZ ANGELA A.
	4CV11*/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10

using namespace std;
int main()
{
	 float a[SIZE][SIZE], x[SIZE], pb;
	 int i,j,k,n;
     cout<< setprecision(3)<< fixed;
     cout<< "\t\tMETODO MATRIZ INVERSA\n";
	 cout<<"Introduzca numero de terminos de incognitas x1, x2, x3... \nTerminos= ";
	 cin>>n;
	 cout<<"Introduza los coeficientes correspondientes: \n";
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			   cout<<"x["<< i<<"]"<< j<<"]= ";
			   cin>>a[i][j];
		  }
		  
	 }
	cout<<"\nMatriz introducida:\n";
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n+1;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }   
 
     for(i=1;i<=n;i++)
     {
          if(a[i][i] == 0.0)
          {
               cout<<"Error";
               exit(0);
          }
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                    pb = a[j][i]/a[i][i];
                    for(k=1;k<=n+1;k++)
                    {
                        a[j][k] = a[j][k] - pb*a[i][k];
                    }
               }
          }
     }
     
     for(i=1;i<=n;i++)
     {
        x[i] = a[i][n+1]/a[i][i];
     }
	 cout<< endl<<"Solucion: \n";
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"X"<< i<<"= "<< x[i]<< endl;
	 }
     
     for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
			if(i==j)
			{
				a[i][j]=1;
			}
		}
	}
	
	cout<<"\nMatriz identidad:\n";
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }  
     
     
     
	 return(0);
}

