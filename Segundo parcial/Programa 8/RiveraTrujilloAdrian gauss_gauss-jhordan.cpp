#include<iostream>
#include<cmath>
using namespace std;

int m,n,i,j,k,l,q,r;
double ext,aux=0;

void ingresar_coeficientes(double M[20][20],int n);
void gauss_jordan(double M[20][20],int n);
void gauss(double M[20][20],int n);

int main () 
{
    int n,de;
    double M[20][20];
    cout<<"ingrese numero de ecuaciones:";
    cin>>n;
    ingresar_coeficientes(M,n);
    cout<<"matriz aumentada:"<<endl;
    for(i=0;i<n;i++)
	{
        for(j=0;j<n+1;j++)
		{
            cout<<M[i][j]<<"\t";
        }
		cout<<endl;
    }
    cout<<"ingrese que metodo quiere hacer gauss = 1 | gauss-jhordan = 2:";
    cin>>de;
    switch(de) 
	{
    	case 1:
    		cout<<"reduccion:"<<endl;
    		gauss( M, n);
    		for(i=0;i<n;i++)
			{
		        for(j=0;j<n+1;j++)
				{
		            cout<<M[i][j]<<"\t";
		        }
				cout<<endl;
		    }
    	break;
    	case 2:
    		cout<<"reduccion:"<<endl;
		    gauss_jordan(M,n);
		    for(i=0;i<n;i++)
			{
		        for(j=0;j<n+1;j++)
				{
		            cout<<M[i][j]<<"\t";
		        }
				cout<<endl;
		    }
    	break;
		default:
			cout<<"esa opcion no es valido"<<endl;
		break;
	}
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
    cout<<"ingrese ecuaciones:"<<endl;
    for(i=0;i<n;i++)
	{
        
        for(j=0;j<n+1;j++)
		{
			cout<<"\t"<<"el valor ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>M[i][j];
        }
    }
}
void gauss(double M[20][20],int n)
{
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<(m);j++)
		{
			ext=(-1*(M[j][i]/M[i][i]));
			for(k=0;k<=n;k++)
			{
				M[j][k]+=ext*M[i][k];
			}
		}
	}
}
