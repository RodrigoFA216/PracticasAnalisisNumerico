import math
from math import *
import sys

xi = [ ] #a
xd = [ ] #b
listaxm = [ ]
listafxm = [ ]
errorcalculado = [ ]
a = 1
b = 2
epsilon = 0.001
iteracion = int(input("Ingrese el numero de iteraciones: "))
estado = ["Sin cambio"]

def funcion(x):
	return  pow(x,3)+2*pow(x,2)+(10*x)-20
	
	

xi.append(a)
xd.append(b)
errorcalculado.append(0)

for i in range(iteracion):
	xm = (a+b)/2
	fxi = funcion(a)
	fxd = funcion(b)
	fxm = funcion(xm)
	listaxm.append(xm)
	listafxm.append(fxm)
		
	if(fxm < 0):
		a = xm
		b = b
		xi.append(a)
		xd.append(b)
		estado.append("Cambio en xi")
		
	if(fxm > 0):
		a = a
		b = xm
		xi.append(a)
		xd.append(b)
		estado.append("Cambio en xd")
	
	if(i>=1):
		k = i 
		error = abs(listaxm[k]-listaxm[k-1])
		errorcalculado.append(error)
	
		
	if(errorcalculado[i]>epsilon):
		print('No se encontro error menor en la iteracion ', i+1,'ya que: ' ,"{:.4f}".format(errorcalculado[i]),'>',epsilon)
		
		



i=0
print("\n")
print('{:^10}{:^10}{:^10}{:^20}{:^20}{:^20}{:^20}'.format('iteracion','Xi','Xd', 'Xm', 'f(Xm)','Estado', 'Error'))
while i<iteracion :
	
	print('{:^10}{:^10.4f}{:^10.4f}{:^20.4f}{:^20.4f}{:^20}{:^20.4f}'.format(i+1,xi[i],xd[i],listaxm[i],listafxm[i],estado[i],errorcalculado[i]))
	
	
	if(errorcalculado[i]<epsilon and i>0):
		print("\n","En la iteración numero:",i+1,'el error es menor')
		sys.exit()
	i=i+1







