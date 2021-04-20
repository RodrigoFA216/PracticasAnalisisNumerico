from os import system
import math
from math import factorial

fx = input("ingrese la funcion f(x): ")
f = lambda x: eval(fx)
x = int(input("ingrese x0: "))
fdx = input("ingrese la derivada de la funcion f'(x): ")
fd = lambda x: eval(fdx)
error = float(input("ingrese el margen de error: "))
i = 1
x1 = x - ( f(x) / fd(x) )
print("{:^20}{:^20}{:^20}{:^20}{:^20}".format("iteracion", "x", "f(x)", "f'(x)", "error"))
print("{:^20}{:^20.5f}{:^20.5f}{:^20.5f}{:^20.5f}".format(i, x, f(x), fd(x), abs(x-x1)))
while abs(x-x1) > error:
    i+=1
    x = x1
    x1 = x - ( f(x) / fd(x) )
    print("{:^20}{:^20.5f}{:^20.5f}{:^20.5f}{:^20.5f}".format(i, x, f(x), fd(x), abs(x-x1)))


