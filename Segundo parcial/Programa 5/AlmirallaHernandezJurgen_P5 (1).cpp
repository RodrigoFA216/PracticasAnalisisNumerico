#include<iostream>
#include<math.h>

using namespace std;

int main(){
float xi,xo,error,e,x,f;

    cout<<"\t\tMetodo de la secante\n\n";
    cout<<"\nFuncion a evaluar x^3+2x^2+10x-20:";
    cout<<"\nIngrese xi: ";
    cin>>xi;
    cout<<"\nIngrese xo: ";
    cin>>xo;

    
   for (int i = 1; i < 100; i++)
   {
       x=xi-((xi-xo)*(pow(xi, 3) + (2 * pow(xi, 2) )+ (10 * xi) - 20))/((pow(xi, 3) + (2 * pow(xi, 2) )+ (10 * xi) - 20)-(pow(xo, 3) + (2 * pow(xo, 2) )+ (10 * xo) - 20));
       e=abs(x-xi);
       cout<<"\nIteracion--------"<<i<<"\n";
       cout<<x;
       cout<<"\nError: "<<e;
        xo=xi;
        xi=x;

      if(e<0.001){
          break;
      }
   }
    

}



   




