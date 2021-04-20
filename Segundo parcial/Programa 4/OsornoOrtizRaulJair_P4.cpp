#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class polinomio
{
    private:
    int n;
    double x,x0,fx[100][100],fdx;
public:
    void pedir_polinomio(int a)
    {
        n=a;
        cout<<"Ingresa el polinomio:"<<endl;
          for (int j=0;j<((n+1)*2);j=j+2)
          {
              cout<<"Coeficiente de x^"<<a<<":";
              cin>>fx[0][j];
              cout<<endl;
              fx[0][j+1]=a;
              a--;

          }
    }
    void imprimir_polinomio(int a)
    {
        cout <<endl<<"el polinomio es :"<<endl;
        for(int j=0;j<((a+1)*2);j=j+2)
        {
            cout<<fx[0][j]<<"x^"<<fx[0][j+1];
            if(fx[0][j+1]>0)
            {
                if(fx[0][j+2]<0)
                    cout <<"  ";
                else
                    cout<<" + ";
            }
            //i++;
        }
        cout<<endl;
    }

     void derivar(int a)
        {
           // for(int i=0;i<(gradoa+1);i++)
            //{
                for(int j=0;j<((a+1)*2);j=j+2)
                {
                    if(fx[0][j+1]==0)//Coeficiente de los terminos de la derivada
                        fx[1][j]=0;
                    else
                        fx[1][j]=fx[0][j+1]*fx[0][j];

                    if(fx[0][j+1]==0)//Exponente de los terminos de la derivada
                        fx[1][j+1]=0;
                    else
                        fx[1][j+1]=fx[0][j+1]-1;
                }
           // }
         }

    void leer(double a)
    {
        x=a;
    }
    double evaluarpolinomio(double x0N, int a)
    {
        x0=x0N;
        double resultado1=0;
        for(int j=0;j<((a+1)*2);j=j+2)
        {
            /*if (fx[0][j]==0)
            {

               return resultado1;
            }*/
                if(fx[0][j+1]==0)
                {

                    resultado1 = resultado1 + (fx[0][j]);
                    return resultado1;

                }
                else
                {
                 resultado1=resultado1 + (fx[0][j]*(pow(x0,fx[0][j+1])));

                }

        }
    }

    double evaluarderivada(double x0N, int a)
    {
        x0=x0N;
        double resultado2=0;
        for(int j=0;j<((a+1)*2);j=j+2)
        {
            if (fx[1][j]==0)
            {
               return resultado2;
            }
            else
            {
            if(fx[1][j+1]==0)
            {
                resultado2 = resultado2 + fx[1][j];

            }
            else
            {
            	resultado2=resultado2 + (fx[1][j]*(pow(x0,fx[1][j+1])));
            
            }
        	}
            
        }
    }


    double Newton_Raphson(double x0, int a)
    {
        double res1;
        double res2;
        double xn;

        res1=evaluarpolinomio(x0,a);
        res2=evaluarderivada(x0,a);
        

        xn = x0-(res1/res2);
        return xn;

    }
    
};

int main()
{
 int grado,it=0;
    double x0,tol,Ea,xi = 0,x_1;
    double valores_Xi[10];
    polinomio obj1;
    system("cls");
    cout<<"Ingrese el grado del polinomio:";
    cin>>grado;
    obj1.pedir_polinomio(grado);
    obj1.imprimir_polinomio(grado);
    obj1.derivar(grado);
    cout<<"Ingrese el punto x0:"<<endl;
    cin>>x0;
    cout<<"Ingrese la tolerancia:"<<endl;
    cin>>tol;
    system("pause");
    system("cls");
    cout<<"\tN E W T O N - R A P H S O N "<<endl;
    cout<<"it\txi\t\t\tError a"<<endl;
    
    valores_Xi[it]=x0;
    xi=obj1.Newton_Raphson(x0,grado);
    valores_Xi[it]=xi;
	Ea=fabs((valores_Xi[it])-(valores_Xi[it-1]));
    cout<<fixed<<setprecision(6)<<it<<"\t"<<xi<<"\t\t"<<Ea<<endl;
	x0=xi;
	it++;
	

    do
    {
        xi=obj1.Newton_Raphson(x0,grado);
        valores_Xi[it]=xi;
        Ea=fabs((valores_Xi[it])-(valores_Xi[it-1]));
        cout<<fixed<<setprecision(6)<<it<<"\t"<<xi<<"\t\t"<<Ea<<endl;
        x0=xi;
        it++;

    }while(Ea>tol);

    system("pause");
    system("cls");
}
