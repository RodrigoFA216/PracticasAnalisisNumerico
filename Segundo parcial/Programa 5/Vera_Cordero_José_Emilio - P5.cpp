/*
 * Método de Newton-Raphson
 * Autor: Vera Cordero José Emilio
 */

/*
 * Formulas: 
 * xn+1 = xn - f(xn)/f'(xn)
 * E = |xi+1 - xi|
 */

#include <iostream>
#include <math.h>

using namespace std;

double evaluar(
	int coef[64], int exp[64],
	int coefd[64], int expd[64],
	int inde[64], int d_inde[64],
	int numd, int numf, int numid,
	int numif, int punto
	)
{
	double evalf = 0;
	double evald = 0;

	for(int i = 0; i < numf; ++i)
	{
		evalf += (coef[i] * pow(punto, exp[i]));
	}

	for(int i = 0; i < numif; ++i)
	{
		evalf += inde[i];
	}

	for(int i = 0; i < numd; ++i)
	{
		evald += (coefd[i] * pow(punto, expd[i]));
	}

	for(int i = 0; i < numid; ++i)
	{
		evalf += d_inde[i];
	}

	return (punto - (evalf / evald));
}

int main()
{
	int numf, numd, numif, numid;
	int coef_buff[64] = {0};
	int exp_buff[64] = {0};
	int d_coef_buff[64] = {0};
	int d_exp_buff[64] = {0};
	int inde_buff[64] = {0};
	int d_inde_buff[64] = {0};
	double error;
	double punto;

	cout<<"¿Cuántos terminos dependientes tiene su polinomio?: ";
	cin>>numf;
	for(int i = 0; i < numf; ++i)
	{
		cout<<"Dé el coeficiente del termino"
		"dependiente número "<<i+1<<": ";
		cin>>coef_buff[i];

		cout<<"Dé el exponente del termino"
		"dependiente número "<<i+1<<": ";
		cin>>exp_buff[i];
	}

	cout<<"¿Cuántos terminos independientes tiene su polinomio?: ";
	cin>>numif;
	for(int i = 0; i < numif; ++i)
	{
		cout<<"Dé el termino independiente "<<i+1<<": ";
		cin>>inde_buff[i];
	}

	cout<<"¿Cuántos terminos dependientes tiene su derivada?: ";
	cin>>numd;
	for(int i = 0; i < numd; ++i)
	{
		cout<<"Dé el coeficiente del termino"
		"dependiente número "<<i+1<<" de la derivada: ";
		cin>>d_coef_buff[i];

		cout<<"Dé el exponente del termino"
		"dependiente número "<<i+1<<" de la derivada: ";
		cin>>d_exp_buff[i];
	}

	cout<<"¿Cuántos terminos independientes tiene su derivada?: ";
	cin>>numid;
	for(int i = 0; i < numid; ++i)
	{
		cout<<"Dé el termino independiente "<<i+1<<" de su derivada: ";
		cin>>d_inde_buff[i];
	}

	cout<<"Dé el error: ";
	cin>>error;

	cout<<"Dé el punto inicial: ";
	cin>>punto;

	/* Algoritmo */
	for(int i = 0; i < 10; ++i)
	{
		double val_ev = evaluar(
			coef_buff, exp_buff,
			d_coef_buff, d_exp_buff,
			inde_buff, d_inde_buff,
			numd, numf, numid, numif, punto
		);
		double e_tmp = fabs(val_ev - punto);

		cout<<"It "<<i+1<<": X"<<i+1<<" = "<<val_ev;
		cout<<"; E = "<<e_tmp<<endl;

		if(e_tmp < error)
		{
			break;
		}

		punto = val_ev;
	}


	return 0;
}