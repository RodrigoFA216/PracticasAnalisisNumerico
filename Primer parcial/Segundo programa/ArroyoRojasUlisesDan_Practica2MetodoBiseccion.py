
from os import system
import time

xi = 1
meta = 0.001
xd = 2 

def mensajeError(eleccion):
	system("cls")
	print("\t\t\tEl dato ",eleccion," no es valido, Ingrese una opcion correcta por favor :)\n\n\n")
	time.sleep(3)

def y(x):
	resultado = pow(x,3) + 2 * pow(x,2) + 10 * x - 20
	return resultado

def capturaDatos():
	while (True):
		system("cls")
		numeroIteraciones = int(input("Ingrese el numero de iteraciones: "))
		if (numeroIteraciones > 0):
			break
		else:
			mensajeError(numeroIteraciones)
	impresionDatos(numeroIteraciones)


def impresionDatos(numeroIteraciones):
	global xi, xd, meta
	print("{:^15}{:^15}{:^15}{:^15}{:^15}{:^15}".format("Iteración","xi","xd","xm","f(xm)","error"))
	for i in range(numeroIteraciones):
		xm = (xi + xd)/2
		fxi = y(xi)
		fxd = y(xd)
		fxm = y(xm)

		if((fxi * fxd) < 0):
			cambio = "Cambio xm -> xi"
		else:
			cambio = "Cambio xm -> xd"

		if (i > 0):
			error = abs(xm - oldxm)
			oldxm = xm
		else:
			error = 0
			oldxm = xm 

		print("{:^15}{:^15.4f}{:^15.4f}{:^15.4f}{:^15.4f}{:^15.4f}".format(i + 1,xi,xd,xm,fxm,error))	

		if(error < meta and i > 0):
			print("\n\n\nEn la Iteración ", (i+1), " se consiguió un error ({:.6f}) menor a la meta ({:.6f})".format(error,meta))
			break
			s
		if((fxi * fxd) < 0):
			xi = xm
		else:
			xd = xm







capturaDatos()





