#include<iostream>
#include<math.h>
#include<conio.h>

void main ()
{
int niter=0,i,x,iter=1;
float ranterior,et,porc=100,euler=1.648721,ractual;
float ractl,factor=1;

cout<<"Ingrese el numerode iteraciones a realizar ";
cin>>niter;
ranterior=1;
ractual=1.5;
et=((euler-ranterior)/euler)*100;
cout<<"\niteracion   \tp*           \t\tError%\n"
<<"\t"<<iter<<"\t"<<ranterior<<"\t\t\t"<<porc;
i++;
et=((euler-ractual)/euler)*100;
porc=((ractual-ranterior)/ractual)*100;
cout<<"   \n\t"<<iter<<"\t"<<ractual<<"\t\t\t"<<porc;
for(i=2;i<=niter-1;i++)
{

factor=1;
ranterior=ractual;
ractl=pow(0.5,i);
for(x=1;x<=i;x++)
{
factor=x*factor;
}

ractual=ranterior+ractl/factor;
et=((euler-ractual)/euler)*100;
porc=((ractual-ranterior)/ractual)*100;
iter=iter+1;
cout<<"   \n\t"<<iter<<"\t"<<ractual<<"\t\t\t"<<porc;

}
		  
cout<<"\n";
getch();

}