from os import system
import math 

def capturaDatos():
	system("cls")
	print("\t\t\t Programa Newton Raphson\n\n")

	errorMeta = float(input("Ingrese el error que se debe superar (0.001): "))
	x0 = int(input("Ingrese  x0: "))
	x1 = int(input("Ingrese  x1: "))
	print("\nA continuación se ingresaran funciones,\nconsidere ingresarlas de manera que python pueda entenderlas (consultar libreria math)")
	print("UTILIZA x COMO INCOGNITA")

	funcion = input("Ingresa la funcion (y= 5*+2. f(x) = pow((7*x + 5)/2)): ")
	funcion = funcion[funcion.find("=")+1:len(funcion)]

	f = lambda x: eval(funcion)#<---  Amo a python por esto xD
	impresionDatos(errorMeta,x0,x1,f)


def impresionDatos(errorMeta,x0,x1,f):
	iteracion=0
	comprobadorConvergencia = 0
	print("{:^25}{:^25}{:^25}{:^25}{:^25}{:^25}{:^25}{:^25}".format("Iteración","xi","xf","xf+1","f(xi)","f(xf)","Error Absoluto","Comparación"))
	while(True):
		fxi = f(x0)
		fxf = f(x1)
		aux = x0 
		x0 = x1
		x1 = x0 - ((x0-aux)*(fxf)/(fxf-fxi))
		errorAbsoluto = abs(x1 - x0)
		if(errorAbsoluto > errorMeta):
			comparacion = "{:.5f} > {}".format(errorAbsoluto,errorMeta)
		else:
			comparacion = "{:.5f} < {} Se Consiguio la meta".format(errorAbsoluto,errorMeta)
			
		print("{:^25}{:^25.5f}{:^25.5f}{:^25.5f}{:^25.5f}{:^25.5f}{:^25.5f}{:^25}".format(iteracion+1,aux,x0,x1,fxi,fxf,errorAbsoluto,comparacion))
		iteracion+=1

		if(errorAbsoluto < errorMeta):
			break	


capturaDatos()

