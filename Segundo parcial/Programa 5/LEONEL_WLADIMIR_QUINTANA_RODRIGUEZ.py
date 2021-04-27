from ecuation import interpreter
import os

def newton():
    error = 0.001
    _x = 1
    list = []
    ecu = input('Ingrese la ecuacion a procesar: ')
    der = input('Ingrese la derivada a procesar: ')
    codeEcu = interpreter(ecu)
    codeDer = interpreter(der)

    for i in range(1, 50):
        x = _x - (eval(codeEcu.replace('u', str(_x)))/eval(codeDer.replace('u', str(_x))))
        E = abs(x - _x)
        _x = x

        list.append([dict({'Iteracion': i, 'x': '{:.5f}'.format(x), 'error': '{:.5f}'.format(E)})])
        if(E < error):
            break
    for i in list:
        print(i)

def secante():
    error = 0.001
    _x = 1
    list = []
    ecu = input('Ingrese la ecuacion a procesar: ')
    x0 = int(input('Ingrese X0: '))
    x1 = int(input('Ingrese X1: '))
    codeEcu = interpreter(ecu)

    for i in range(1, 50):
        ep1 = (x1 - x0)*(eval(codeEcu.replace('u', str(x1))))
        ep2a = eval(codeEcu.replace('u', str(x1)))
        ep2b = eval(codeEcu.replace('u', str(x0)))
        ep2 = ep2a - ep2b
        x = x1 - (ep1/ep2)
        E = abs(x - x1)
        x0 = x1
        x1 = x

        list.append([dict({'Iteracion': i, 'x': '{:.5f}'.format(x), 'error': '{:.5f}'.format(E)})])
        if (E < error):
            break
    for i in list:
        print(i)


def main():
    sel = int(input(r'\\MENU//'
                '\n1.-Metodo de Newton-Raphson'
                '\n2.-Metodo de la Secante'
                '\n3.-Salir\n'))
    if sel == 1:
        newton()
    elif sel == 2:
        secante()
    elif sel == 3:
        exit()
    else:
        main()
    os.system('pause')
    os.system('cls')
    main()

if __name__ == '__main__':
    main()

# x^3 + 2x^2 + 10x - 20
# 3x^2 + 4x + 10