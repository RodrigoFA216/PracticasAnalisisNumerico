
#include <iostream> 
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
	double a00,a01,a02,a10,a11,a12,a20,a21,a22,total;
	
    cout<<"\n\n\t\t\t\t\t\tTORRES RANGEL JESUS"<<endl;
    cout<<"\n\n\t\t\t\t\t\t  MATRIZ INVERSA"<<endl;
	
	cout<<"\n\n\tIngrese los valores de A:\n\n"<<endl;
    cout<<"\t\t\t\t\t|a00 a01 a02|" <<endl;
    cout<<"\t\t\t\t\t|a10 a11 a12|" <<endl;
    cout<<"\t\t\t\t\t|a20 a21 a22|" <<endl;
    
    cout<<"\n a00: ";
    cin>>a00;
    cout<<" a01: ";
    cin>>a01;
    cout<<" a02: ";
    cin>>a02;
    cout<<" a10: ";
    cin>>a10;
    cout<<" a11: ";
    cin>>a11;
    cout<<" a12: ";
    cin>>a12;
    cout<<" a20: ";
    cin>>a20;
    cout<<" a21: ";
    cin>>a21;
    cout<<" a22: ";
    cin>>a22;
    
    cout <<"\n";

    total=a00*a11*a22 + a10*a21*a02 +a20*a01*a12;
    total=total+(a02*a11*a20)*-1 + (a12*a21*a00)*-1 + (a22*a01*a10)*-1;



if(total!=0)
{
	cout<<(a11*a22-a21*a12)/total<<' '<<((a01*a22-a21*a02)*-1)
    / total<<' '<<(a01*a12-a11*a02)/total<<endl;
    cout<<((a10*a22-a20*a12)*-1)/total<<' '<<((a00*a22-a20*a02))
    / total<<' '<<((a00*a12-a10*a02)*-1)/total<<endl;
    cout<<((a10*a21-a20*a11))/total<<' '<<((a00*a21-a20*a01)*-1)
    / total<<' '<<(a00*a11-a10*a01)/total<<endl;

    cout<<"\nDeterminante 3x3:"<<total;

}
else
{
	cout<<"Error el det. da 0";
}


}
