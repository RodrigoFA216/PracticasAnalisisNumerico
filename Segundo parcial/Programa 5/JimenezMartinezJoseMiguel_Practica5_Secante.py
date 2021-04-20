import math
from math import *
from os import system


error = float(input("Ingresa el error a alcanzar (ejemplo: 0.001): "))
x0 = int(input("Ingresa el valor de X0: "))
x1 = int(input("Ingresa el valor de X1: "))
i=0 

print("\nIngresa la funcion, ejemplo f(x)=2*X+3,g(x)=pow(((x+5)/2),1/2) [ingresa solo la parte despues del igual] ")
funcionString = input("f(x)= ")
system("cls")

funcion = lambda x: eval(funcionString) #convierte a codigo un string

print("{:^25}{:^25}{:^25}{:^25}{:^25}".format("Iteración","X1","X2","Error absoluto","Comparativa"))

while(True):
		fx0 = funcion(x0)
		fx1 = funcion(x1)
		x2= x1-(((x1-x0)*(fx1))/((fx1-fx0)))

		errorab = abs(x2 - x1)
		if(errorab > error):
			comparacion = "{} > {}".format(errorab,error)
		else:
			comparacion = "{} < {}".format(errorab,error)	
		print("{:^25}{:^25.4f}{:^25.4f}{:^25.4f}{:^25}".format(i+1,x0,x1,errorab,comparacion))
		i=i+1
		x0 = x1
		x1 = x2
		if (errorab < error):
			print("Error menor al ingresado obtenido en la iteracion",i)
			break
