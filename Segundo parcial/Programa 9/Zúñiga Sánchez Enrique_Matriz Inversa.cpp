#include<iostream>
#include<cmath>
using namespace std;

int m,n,i,j,k,l,q,r;
double ext,aux=0;

void ingresar_coeficientes(double M[20][20],int n);
void gauss_jordan(double M[20][20],int n);

int main () 
{
    int n,de;
    double M[20][20];
    cout<<"\n       >>  M A T R I Z  I N V E R S A  <<";
    cout<<"\n  - LLene el sistema de ecuaciones 3x3.\n";
    n=3;
    ingresar_coeficientes(M,n);
    system("cls");
    cout<<"\n                 >>  M A T R I Z  I N V E R S A  <<"<<endl;
    cout<<"\n  > Matriz:"<<endl;
    for(i=0;i<n;i++)
	{
        for(j=0;j<7;j++)
		{
            if((i==0&&j==3)||(i==1&&j==3)||(i==2&&j==3))
            {
            	cout<<"| "<<M[i][j]<<" |\t";
			}
			else
			{
				cout<<M[i][j]<<"\t";	
			}
        }
		cout<<endl;
    }
	cout<<"\n \n  > Reduccion:"<<endl;
    gauss_jordan(M,7);
    for(i=0;i<n;i++)
	{
        for(j=0;j<7;j++)
		{
            if((i==0&&j==3)||(i==1&&j==3)||(i==2&&j==3))
            {
            	cout<<"| "<<M[i][j]<<" |\t";
			}
			else
			{
				cout<<M[i][j]<<"\t";	
			}
        }
		cout<<endl;
    }
    cout<<"\n\n Zuñiga Sánchez Enrique - 4CM1"<<endl;
	cout<<endl;
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
void ingresar_coeficientes(double M[20][20],int n)
{
    cout<<"\n  Ingrese ecuaciones:"<<endl;
    for(i=0;i<n;i++)
	{
        cout<<"   Ecuacion"<<i+1<<endl; 
        for(j=0;j<7;j++)
		{
			if(j<4)
			{
				if(j<3)
				{
					cout<<"    Ingrese el valor de X"<<j+1<<": ";
				}
				else
				{
					cout<<"    Ingrese el valor de R"<<i+1<<": ";
				}
				cin>>M[i][j];
			}
			else
			{
				if((i==0&&j==4)||(i==1&&j==5)||(i==2&&j==6))
				{
					M[i][j]=1;
				}
				else
				{
					M[i][j]=0;
				}
			}
			
        }
    }
}
