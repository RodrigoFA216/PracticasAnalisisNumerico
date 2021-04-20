from os import system
import math
from math import factorial

fx = input("ingrese la funcion ( pow(x,3) + 2*pow(x,2)+10*x-20 )f(x): ")
f = lambda x: eval(fx)
x0 = int(input("ingrese x0: "))
x1 = int(input("ingrese x1: "))
error = float(input("ingrese el margen de error: "))
i = 1
x = x1 - ( ((x1 - x0) * (f(x1))) / (f(x1) - f(x0)) )
print("{:^20}{:^20}{:^20}{:^20}{:^20}".format("iteracion", "x0", "x1", "f(x)", "error"))
print("{:^20}{:^20.5f}{:^20.5f}{:^20.5f}{:^20}".format(i, x0, x1, f(x), "no Error"))
while abs(x1-x0) > error:
    i+=1
    x0 = x1
    x1 = x
    x = x1 - ( ((x1 - x0) * (f(x1))) / (f(x1) - f(x0)) )
    print("{:^20}{:^20.5f}{:^20.5f}{:^20.5f}{:^20.5f}".format(i, x0, x1, f(x), abs(x0-x1)))


