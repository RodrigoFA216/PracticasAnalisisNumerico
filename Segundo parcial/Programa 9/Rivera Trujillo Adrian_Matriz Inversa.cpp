#include<iostream>
#include<cmath>
using namespace std;

int m,n,i,j,k,l,q,r;
double ext,aux=0;

void llenar_matriz(double M[20][20],int n);
void gauss_jordan(double M[20][20],int n);

int main () 
{
    int n,de;
    double M[20][20];
    cout<<"\n   Metodo de la Matriz Inverza   ";
   	do
   	{
   		cout<<"\n  Rivera Trujillo Adrian\n Introdusca el tamaño de la matriz cuadrada no mas 6 ni menos de 2\n\tn:";
   		cin>>n;
    	if(n<2||n>6)
    	{
    		cout<<"Valor invalido"<<endl;
		}
	}while(n<2||n>6);
    cout<<"\n   Introdusca el tamaño de la matriz cuadrada no mas 6 ni menos de 2\n";
    n=3;
    llenar_matriz(M,n);
    cout<<"\n  > Matriz:"<<endl;
    for(i=0;i<n;i++)
	{
        for(j=0;j<7;j++)
		{
            if((i==0&&j==3)||(i==1&&j==3)||(i==2&&j==3))
            {
            	cout<<"|| "<<M[i][j]<<" ||\t";
			}
			else
			{
				cout<<M[i][j]<<"\t";	
			}
        }
		cout<<endl;
    }
	cout<<"\n \n Matriz reducida:"<<endl;
    gauss_jordan(M,7);
    for(i=0;i<n;i++)
	{
        for(j=0;j<7;j++)
		{
            if((i==0&&j==3)||(i==1&&j==3)||(i==2&&j==3))
            {
            	cout<<"||"<<M[i][j]<<" |\t";
			}
			else
			{
				cout<<M[i][j]<<"\t";	
			}
        }
		cout<<endl;
    }
    return 0;
}
void gauss_jordan(double M[20][20],int n)
{
    double may;
    int ind;
    double aux;
    double pivote;

    for(k=0;k<n;k++)
	{
        may=abs(M[k][k]);
        ind=k;    
        for( l=k+1;l<n;l++)
		{
            if(may<abs(M[l][k]))
			{
                may=abs(M[l][k]);
                ind=l;
            }
            
        }
        //cambiar filas
        if(k!=ind){
            for(i=0;i<n+1;i++)
			{
                aux=M[k][i];
                M[k][i]=M[ind][i];
                M[ind][i]=aux;
            }
        }
        if(M[k][k]==0)
		{
            cout<<"no tiene solucion";
            break;
        }
        else
		{            
            for(i=0;i<n;i++)
			{
                if(i!=k)
				{
                    pivote=-M[i][k];
                    for(j=k;j<n+1;j++)
					{

                        M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k];
                    }
                }
                else
				{
                    pivote=M[k][k];
                    for(j=k;j<n+1;j++)
					{
                        M[i][j]=M[i][j]/pivote;
                    }
                }                
            }
        }
	}
}
void llenar_matriz(double M[20][20],int n)
{
    cout<<"\n  Ingrese los datos:"<<endl;
    for(i=0;i<n;i++)
	{
        cout<<"   Ecuacion"<<i+1<<endl; 
        for(j=0;j<=n;j++)
		{
			if(j<n)
			{
				cout<<"    Ingrese el valor de X"<<j+1<<": ";
			}
			else
			{
				cout<<"    Ingrese el resultado: "<<i+1<<": ";
			}
			cin>>M[i][j];					
        }
    }
}
