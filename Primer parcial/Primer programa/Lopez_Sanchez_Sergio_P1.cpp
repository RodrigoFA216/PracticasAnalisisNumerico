#include <iostream.>
#include <math.h>

int s_d_M();
using namespace std;

int nit=0;

int main()
{
	
	cout<<"Inserta el numero de elementos"<<endl;
	cin>>nit;
	
	s_d_M();
	
}

int s_d_M()
{
	int i,x,it=1;
	float r_an, por=100, v_e=1.648721271, r_ac;
	float r_ac1,factor=1;
	
	r_an=1;
	r_ac=1.5;
	
cout<<"\Elemntos   \tp*           \t\tERP\n"
	      <<"\t"<<it<<"\t"<<r_an<<"\t\t\t"<<por;
	      i++;
	      
	      por=((r_ac-r_an)/r_ac)*100;
	      cout<<"   \n\t"<<it<<"\t"<<r_ac<<"\t\t\t"<<por;
	      for(i=2;i<=nit-1;i++)
	      {
	      	
			  factor=1;
	      	r_an=r_ac;
	      	r_ac1=pow(0.5,i);
	      	for(x=1;x<=i;x++)
	      	{
	      		factor=x*factor;
			  }
			  
			r_ac=r_an+r_ac1/factor;
			por=((r_ac-r_an)/r_ac)*100;
			it=it+1;
			cout<<"   \n\t"<<it<<"\t"<<r_ac<<"\t\t\t"<<por;
			
		  }
		  
		  cout<<"\n";
		  system("PAUSE");
		  return 0;
}
