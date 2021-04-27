#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

int polinomio(int);
float mpf(float);

int n;
float e,va,xm,fxm,fxi,fxf,xi,xf;

int main()
{
	cout<<"\n\t Metodo de Posicion Falsa \n"<<endl;
	
	cout<<"\n Introduce el numero de coeficientes del polinomio"<<endl;
	cin>>n;
	
	polinomio(n);
	
   
}

int polinomio (int n)
{
	float p[n];
	
	for(int i=0; i<n; i++)
	{
		cout<<"\n introduce el coeficiente para x^"<<i<<endl;
		cin>>p[i];
	}
	
	
	
	cout<<"Introduce Xi y Xf"<<endl;
	cout<<"Xi :";
	cin>>xi;
	cout<<" "<<endl; 
	cout<<"Xf :";
	cin>>xf;
	cout<<" "<<endl;
	
	
	fxi;
	fxf;
	
	
	for(int i=0; i<n; i++)
	{
		fxi= fxi + p[i]* pow(xi, i);
		 
	}
	cout<<"F(xi)= "<<fxi<<endl;
	
	for(int i=0; i<n; i++)
	{
		fxf=fxf + p[i]* pow(xf, i);
	}
	
	cout<<"F(xf)= "<<fxf<<endl;
	
	cout<<"Introduce el error"<<endl;
    cin>>e;
    
    do{
    	xm=(xf)-((xf-xi)*(fxf))/((fxf-fxi));
    	cout<<"\n Xm= "<<xm;
    	fxm=(pow(xm,3))+(2*pow(xm,2))+(10*xm)-20;
    	cout<<"  F(xm)="<<fxm;
    	va=abs(xm-xi);
    	cout<<"  e="<<va<<endl;
    	
    	
		if(fxm<0)
    	{
    		xi=xm;
    		fxi=fxm;
        } 
    	 else
    	 {
    	 
    	  xf=xm,
    	  fxf=fxm;
        }
       
    
	}
	
	while(va>e);
	{
		
		xm=(xf)-((xf-xi)*(fxf))/((fxf-fxi));
    	cout<<"\n Xm= "<<fixed<<setprecision(4)<<xm;
    	fxm=(pow(xm,3))+(2*pow(xm,2))+(10*xm)-20;
    	cout<<"  F(xm)="<<fixed<<setprecision(4)<<fxm;
    	va=abs(xi-xm);
    	cout<<"  e="<<fixed<<setprecision(4)<<va<<endl;
    	
        	if(fxm<0)
    	{
    		xi=xm;
    		fxi=fxm;
        } 
    	 else
    	 {
    	 
    	  xf=xm,
    	  fxf=fxm;
        }
        
       	
	}
	cout<<"La raiz es igual a:"<<fixed<<setprecision(4)<<xm;
	
}
	
