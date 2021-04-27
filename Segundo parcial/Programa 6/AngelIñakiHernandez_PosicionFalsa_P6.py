import math

def tabulacion(n, xf, xi , xm_caja):
    xm = xf - ((xf - xi)*(fx(xf))) / (fx(xf) - fx(xi))

    if fx(xm) < 0: xi = xm
    else : xf = xm
    print ("{:^20}{:^20.4f}{:^20.4f}{:^20.4f}{:^20.4f}{:^20.4f}".format(n, xi, xf, fx(xm), xm, abs(xm - xm_caja)))
    if abs(xm - xm_caja) > error:
        xm_caja = xm
        tabulacion(n+1, xf, xi, xm_caja )

def Find_xi_xf(iteracion):
    for x in range(iteracion*-1, iteracion):
        if fx(x) > 0 and fx(x-1) < 0:
            fxi = x -1
            fxf = x 
            return fxi, fxf
        if fx(x) < 0 and fx(x-1) > 0:
            fxi = x -1
            fxf = x 
            return fxi, fxf

funcion = input("ingrese la funcion ( pow(x,3) + 2*pow(x,2)+10*x-20 )f(x): ")
error = float(input("ingrese el margen de error (0.001): "))
fx = lambda x: eval(funcion)

xi, xf = Find_xi_xf(5)
xm = 0
xm_caja = 0
print ("{:^20}{:^20}{:^20}{:^20}{:^20}{:^20}".format("iteraciones", "xi", "xd", "fx(xm)", "xm", "error"))
tabulacion(1, xf, xi, xm_caja )
    