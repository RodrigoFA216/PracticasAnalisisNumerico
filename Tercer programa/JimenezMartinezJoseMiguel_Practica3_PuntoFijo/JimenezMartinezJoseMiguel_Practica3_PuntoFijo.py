import math
from math import *
from os import system




error = float(input("Ingresa el error a alcanzar (ejemplo: 0.001): "))
x0 = int(input("Ingresa el valor de X0: "))
conv = 0
i=0 


print("\nIngresa el despeje de la funcion, ejemplo g(x)=2*X+3,g(x)=pow(((x+5)/2),1/2) [ingresa solo la parte despues del igual] ")
despeje = input("g(x)= ")
system("cls")

g = lambda x: eval(despeje) #convierte a codigo un string

print("{:^25}{:^25}{:^25}{:^25}{:^25}".format("Iteración","X0","g(x)","Error Absoluto","Comparativa"))

while(True):
		gx = g(x0)
		errorab = abs(x0 - gx)
		if(errorab > error):
			comparacion = "{} > {}".format(errorab,error)
		else:
			comparacion = "{} < {} Error menor al ingresado".format(errorab,error)	
		print("{:^25}{:^25.4f}{:^25.4f}{:^25.4f}{:^25}".format(i+1,x0,gx,errorab,comparacion))
		i=i+1
		x0 = gx
		if(errorab > 1):
			conv = conv + 1
			if(conv > 2):
				print("El despeje ingresado no tiene convergencia ")
				break
		if (errorab < error):
			print("El despeje es convergente")
			break
