"""
Programa Punto Fijo

Requisitos:

Se debe pedir La funcion ORIGINAL, el DESPEJE, el error y X_0

Debe de decir si converge o no 

Si es asi que diga en que iteración el error obtenido es menor al error solicitado

"""
from os import system
import math 
from math import factorial





def capturaDatos():
	system("cls")
	print("\t\t\t Programa Punto Fijo\n\n")

	errorMeta = float(input("Ingrese el error que se debe superar (0.001): "))
	x0 = int(input("Ingrese  x0: "))

	print("\nA continuación se ingresaran funciones,\nconsidere ingresarlas de manera que python pueda entenderlas (consultar libreria math)")
	print("UTILIZA x COMO INCOGNITA")

	funcion = input("Ingresa la funcion (y= 5*+2. f(x) = pow((7*x + 5)/2)): ")
	funcion = funcion[funcion.find("=")+1:len(funcion)]

	despeje = input("Ingresa el despeje de la funcion (g(x)= (x*2+3)/5,  g = (pow((x+2),2)): ")
	despeje = despeje[despeje.find("=")+1:len(despeje)]
	print(despeje)
	f = lambda x: eval(funcion)#<---  Amo a python por esto xD
	g = lambda x: eval(despeje)#<---  Amo a python por esto xD
	impresionDatos(errorMeta,x0,g)
	
def impresionDatos(errorMeta,x0,g):
	iteracion=0
	comprobadorConvergencia = 0
	print("{:^25}{:^25}{:^25}{:^25}{:^25}".format("Iteración","x0","g(x)","Error Absoluto","Comparación"))
	while(True):
		gx = g(x0)
		errorAbsoluto = abs(x0 - gx)
		if(errorAbsoluto > errorMeta):
			comparacion = "{} > {}".format(errorAbsoluto,errorMeta)
		else:
			comparacion = "{} < {} Se Consiguio la meta".format(errorAbsoluto,errorMeta)	

		print("{:^25}{:^25.4f}{:^25.4f}{:^25.4f}{:^25}".format(iteracion+1,x0,gx,errorAbsoluto,comparacion))
		iteracion+=1
		x0 = gx
		if(errorAbsoluto > 1):
			comprobadorConvergencia += 1
			if(comprobadorConvergencia > 2):
				print("El despeje ingresado no tiene convergencia ")
				break
		if (errorAbsoluto < errorMeta):
			print("El despeje es convergencte")
			break







capturaDatos()

#y = f(5)
#print (y)