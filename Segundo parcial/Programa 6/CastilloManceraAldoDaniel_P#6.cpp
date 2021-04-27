//CASTILLO MANCERA ALDO DANIEL

#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cmath>


using namespace std;

double f(double,int,int,int,int);

int main()
{
   
   double A,B,error,error2,fx,ffx,x0,x_1,aux=0;
   int x3,x2,x,n,i=1;
   
	cout << "\ningresa la ecuacion N x^3+ N x^2 + N x + N = 0\n ingresa el signo junto con el numero\n";
    cout << "\nnumero que acompaña a x^3 = "; cin >> x3;
    cout << "\nnumero que acompaña a x^2 = "; cin >> x2;
    cout << "\nnumero que acompaña a x = "; cin >> x;
    cout << "\nnumero que acompaña = "; cin >> n;
    
    system("cls");
    
     cout << "\nIngrese el punto inicial para tabular  " << endl;
    cout << "\nX0 = ";
    cin >> x0;
    cout << "\nX1 = ";
    cin >> x_1;
    
    cout << "x\t\tf(x)\n";
    
    for (int i=x0;i<=x_1;i++)
    {
    	fx=f(i,x3,x2,x,n);
    	cout <<"\n"<<i<<"\t\t"<<fx;
	}
    
    cout << "\nIngrese el punto inicial " << endl;
    cout << "\nXI = ";
    cin >> x0;
    cout << "\nXF = ";
    cin >> x_1;
    
    system("cls");
   
    
	cout << "\n error: "; cin >> error2;
	
	system("cls");
	cout << "iteracion\tXn\t\terror\n\n";
	do 
	{
		fx=f(x0,x3,x2,x,n);
   		ffx=f(x_1,x3,x2,x,n);
   		
		A=x_1-(((x_1-x0)*ffx)/(ffx-fx));
		B=f(A,x3,x2,x,n);
		error=fabs(A-aux);
		aux=A;
		cout << i << "\t\t" << A << "\t\t" << error << "\n\n";
		
		i++;
		if(B<0)
		{
			x0=A;		
		}
		if(B>0)
		{
			x_1=A;
		}
		
		fx=f(x0,x3,x2,x,n);
    	ffx=f(x_1,x3,x2,x,n);
	}  
	while (error>error2);
}


double f(double x,int n3,int n2,int n1, int n) 
{
   return n3*(pow(x,3))+n2*(pow(x,2))+(n1*x)+n;
}

