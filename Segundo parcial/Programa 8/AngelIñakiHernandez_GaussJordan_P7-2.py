Ecuaciones = [[0,0,0,0],[0,0,0,0],[0,0,0,0]]

def ingresarDatos(): 
    for i in range(len(Ecuaciones)):
        for j in range(len(Ecuaciones[i])):
            if j < 3:
                Ecuaciones[i][j] = int(input("ingrese el valor de x{} de la ecuacion {}: ".format(j+1, i+1)))
            else:
                Ecuaciones[i][j] = int(input("ingrese el valor del resultado de la ecuacion {}: ".format(i+1)))

def acomodarMenor():
    lugar = Ecuaciones.index(min(Ecuaciones)) 
    if lugar != 0 and Ecuaciones[lugar][0] != 0: 
        caja = Ecuaciones[0]
        Ecuaciones[0] = min(Ecuaciones)
        Ecuaciones[lugar]= caja
        imprimirMatriz(0, lugar, "cambia")
    elif Ecuaciones[lugar][0] == 0: 
        caja = Ecuaciones[0]
        Ecuaciones[0] = Ecuaciones[2]
        Ecuaciones[2]= caja
        imprimirMatriz(0, lugar, "cambia")

def imprimirMatriz(lugar1 = None, lugar2 = None, operacion = None,numero = None):
    if lugar1 is not None:                                  
        if numero is None:                                  
            print("Ecu{} {} -> Ecu{}".format(lugar1+1, operacion, lugar2+1))
        else :
            print("Ecu{} {} ({})*Ecu{} -> Ecu{}".format( lugar1+1, operacion, numero, lugar2+1, lugar1+1))
    print("""
    |{}|
    |{}|
    |{}|
    """.format(Ecuaciones[0], Ecuaciones[1], Ecuaciones[2]))

def elimiarDatos(lugar1, lugar2, posicion):
    numerador = abs(Ecuaciones[lugar1][posicion])
    denominador = Ecuaciones[lugar2][posicion]
    if Ecuaciones[lugar1] != 0: 
        if Ecuaciones[lugar1][posicion] > 0:
            for i in range(len(Ecuaciones[lugar1])):
                Ecuaciones[lugar1][i] = Ecuaciones[lugar1][i] - Ecuaciones[lugar2][i]*(numerador/denominador)
            imprimirMatriz(lugar1, lugar2, "resta", (numerador/denominador))
        elif Ecuaciones[lugar1][posicion] < 0:
            for i in range(len(Ecuaciones[lugar1])):
                Ecuaciones[lugar1][i] = Ecuaciones[lugar1][i] + Ecuaciones[lugar2][i]*(numerador/denominador)
            imprimirMatriz(lugar1, lugar2, "suma", (numerador/denominador))

def elimDatArriba(lugar1, lugar2, posicion, uno = None):
    if uno == None:
        numerador = abs(Ecuaciones[lugar1][posicion])
        denominador = Ecuaciones[lugar2][posicion]
        if Ecuaciones[lugar1][posicion] > 0:
            for i in range(len(Ecuaciones[lugar1])):
                Ecuaciones[lugar1][i] = Ecuaciones[lugar1][i] - Ecuaciones[lugar2][i]*(numerador/denominador)
            imprimirMatriz(lugar1, lugar2, "resta", (numerador/denominador))
        elif Ecuaciones[lugar1][posicion] < 0:
            for i in range(len(Ecuaciones[lugar1])):
                Ecuaciones[lugar1][i] = Ecuaciones[lugar1][i] + Ecuaciones[lugar2][i]*(numerador/denominador)
            imprimirMatriz(lugar1, lugar2, "suma", (numerador/denominador))
    else:
        numerador = (Ecuaciones[lugar1][posicion])
        for i in range(len(Ecuaciones[lugar1])):
            Ecuaciones[lugar1][i] = Ecuaciones[lugar1][i]/numerador
        imprimirMatriz(lugar1, lugar1, "division", numerador)

def asignacionValores():
    x3 = Ecuaciones[2][3]
    x2 = Ecuaciones[1][3]
    x1 = Ecuaciones[0][3]
    print("x1 = {}|| x2 = {}|| x3 = {}". format(x1,x2,x3))
ingresarDatos()
acomodarMenor()
elimiarDatos(2,0,0)
elimiarDatos(1,0,0)
elimiarDatos(2,1,1)
elimDatArriba(2,2,2, 1)
elimDatArriba(1,2,2)
elimDatArriba(1,1,1, 1)
elimDatArriba(0,2,2)
elimDatArriba(0,1,1)
elimDatArriba(0,0,0,1)
asignacionValores()
