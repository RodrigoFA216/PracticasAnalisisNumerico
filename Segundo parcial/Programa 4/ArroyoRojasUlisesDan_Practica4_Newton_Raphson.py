from os import system
import math 


#PEDIR EL POLINOMIO Y LA DERIVADA, PUNTO INICIAL, EL ERROR
def capturaDatos():
	system("cls")
	print("\t\t\t Programa Newton Raphson\n\n")

	errorMeta = float(input("Ingrese el error que se debe superar (0.001): "))
	x0 = int(input("Ingrese  x0: "))

	print("\nA continuación se ingresaran funciones,\nconsidere ingresarlas de manera que python pueda entenderlas (consultar libreria math)")
	print("UTILIZA x COMO INCOGNITA")

	funcion = input("Ingresa la funcion (y= 5*+2. f(x) = pow((7*x + 5)/2)): ")
	funcion = funcion[funcion.find("=")+1:len(funcion)]

	derivada = input("Ingresa la derivada de la funcion (g(x)= (x*2+3)/5,  g = (pow((x+2),2)): ")
	derivada = derivada[derivada.find("=")+1:len(derivada)]
	print(derivada)
	f = lambda x: eval(funcion)#<---  Amo a python por esto xD
	g = lambda x: eval(derivada)#<---  Amo a python por esto xD
	impresionDatos(errorMeta,x0,f,g)


def impresionDatos(errorMeta,x0,f,g):
	iteracion=0
	comprobadorConvergencia = 0
	print("{:^25}{:^25}{:^25}{:^25}{:^25}{:^25}".format("Iteración","x0","f(x)","g(x)","Error Absoluto","Comparación"))
	while(True):
		gx = g(x0)
		fx = f(x0)
		x1 = x0 - fx/gx
		errorAbsoluto = abs(x1 - x0)
		if(errorAbsoluto > errorMeta):
			comparacion = "{} > {}".format(errorAbsoluto,errorMeta)
		else:
			comparacion = "{} < {} Se Consiguio la meta".format(errorAbsoluto,errorMeta)
			
		print("{:^25}{:^25.5f}{:^25.5f}{:^25.5f}{:^25.5f}{:^25}".format(iteracion+1,x0,fx,gx,errorAbsoluto,comparacion))
		iteracion+=1
		x0 = x1

		if(errorAbsoluto < errorMeta):
			break	


capturaDatos()

