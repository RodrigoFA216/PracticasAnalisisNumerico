from os import system
import math 
from math import factorial

def capturaDatos():
	system("cls")
	x = float(input("Ingrese el valor de x: "))
	numeroIteraciones = int(input("Ingrese el numero de iteraciones: "))
	numeroExacto = pow(math.e,x)
	print("Valor de e^",x,": {:.4f}".format(numeroExacto))
	impresionDatos(x,numeroIteraciones,numeroExacto)

def impresionDatos(x,numeroIteraciones,numeroExacto):
	print("{:^15}{:^15}{:^15}{:^15}{:^15}".format("Iteración","p*","Error Absoluto","Error Relativo","Error Relativo Porcentual"))
	for i in range(numeroIteraciones):
		y = serieMaclaurin(x,i)
		errorAbsoluto = abs(numeroExacto - y)
		errorRelativo = abs(1-y/numeroExacto)
		errorRelativoPorcentual = errorRelativo * 100
		print("{:^15}{:^15.4f}{:^15.4f}{:^15.4f}{:^15.4f}".format(i+1,y,errorAbsoluto,errorRelativo,errorRelativoPorcentual))

def serieMaclaurin(x,i):
	if (i >= 0):
		resultado =pow(x,i)/factorial(i)
		if(i-1 >= 0):
			resultado += serieMaclaurin(x,i-1)
		else:
			return resultado	
	return resultado		


capturaDatos()

