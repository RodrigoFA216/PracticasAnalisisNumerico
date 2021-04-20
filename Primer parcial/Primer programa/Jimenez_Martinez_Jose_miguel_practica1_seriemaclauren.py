import math
from math import factorial


x = float(input("Ingresa el valor de x: "))
iteracion = int(input("Ingresa el numero de Iteraciones: "))
aproximaciones = [ ] #p*
errorabsoluto = [ ] 
errorrelativo= [ ] 
errorrelativoporcentual = [ ]
i=0

def serie(iteracion,x,lista,lista2,lista3,lista4):
	r=0
	exp =float("{:.4f}".format(pow(math.e,x)))
	for i in range(iteracion):
		
		r = r + (pow(x,i)/factorial(i))
		lista.append("{:.4f}".format(r))
		eab = abs(exp - r)
		lista2.append("{:.4f}".format(eab))
		ere = abs((exp-r)/exp)
		lista3.append("{:.4f}".format(ere))
		erep = abs(ere*100)
		lista4.append("{:.4f}".format(erep))


serie(iteracion,x, aproximaciones, errorabsoluto, errorrelativo, errorrelativoporcentual)
print("\n\n")
print('{:^10}{:^10}{:^10}{:^20}{:^20}'.format('iteracion','P*','Error Absoluto', 'Error Relativo', 'Error Relativo Porcentual'))
while i<iteracion :
	
	print('{:^10}{:^10}{:^10}{:^25}{:^20}'.format(i+1,aproximaciones[i],errorabsoluto[i],errorrelativo[i],errorrelativoporcentual[i]))
	i=i+1	

