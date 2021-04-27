from ecuation import interpreter
from matrix import MatrixGen


def Gauss(matriz):
    print('----------------------------------')

    for m in matriz:
        print(str(list(m.values())))

    print('----------------------------------')

    if matriz[1].get('x1') != 0:
        mul = matriz[1].get('x1')
        div = matriz[0].get('x1')
        op = mul / div
        before = str(list(matriz[1].values()))
        print('Linea 2 menos linea 1 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[1][key] = matriz[1][key] - matriz[0].get(key) * op
        print(before + ' -----> ' + str(matriz[1].values()))

    if matriz[2].get('x1') != 0:
        mul = matriz[2].get('x1')
        div = matriz[0].get('x1')
        op = mul / div
        before = str(list(matriz[2].values()))
        print('Linea 3 menos linea 1 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[2][key] = matriz[2][key] - matriz[0].get(key) * op
        print(before + ' -----> ' + str(matriz[2].values()))

    if matriz[2].get('x2') != 0:
        mul = matriz[2].get('x2')
        div = matriz[1].get('x2')
        op = mul / div
        before = str(list(matriz[2].values()))
        print('Linea 3 menos linea 2 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[2][key] = matriz[2][key] - matriz[1].get(key) * op
        print(before + ' -----> ' + str(matriz[2].values()))

    print('Despejando x3 de la matriz: ')
    print('----------------------------------')

    for m in matriz:
        print(str(list(m.values())))

    print('----------------------------------')

    x3 = matriz[2].get('r') / matriz[2].get('x3')
    print('x3 =', x3)
    x2 = (matriz[1].get('r') - matriz[1].get('x3') * x3) / matriz[1].get('x2')
    print('x2 =', x2)
    x1 = (matriz[0].get('r') - matriz[0].get('x3') * x3 - matriz[0].get('x2') * x2) / matriz[0].get('x1')
    print('x1 =', x1)

    print('\n\n\n')


def GaussJordan(matriz):
    print('----------------------------------')

    for m in matriz:
        print(str(list(m.values())))

    print('----------------------------------')

    if matriz[0].get('x1') != 1 and matriz[2].get('x1') != 1:
        div = matriz[0].get('x1')
        before = str(list(matriz[0].values()))
        print('Linea 1 entre ', div)
        for key in matriz[0].keys():
            matriz[0][key] = matriz[0].get(key) / div
        print(before + ' -----> ' + str(list(matriz[0].values())))

    elif matriz[2].get('x1') == 1:
        print('Debido a que L3 ya se encuentra en con x1 = 1, \nse hace cambio de linea')
        aux = matriz[2]
        matriz[2] = matriz[0]
        matriz[0] = aux
        for m in matriz:
            print(str(list(m.values())))

    if matriz[1].get('x1') != 0:
        mul = matriz[1].get('x1')
        div = matriz[0].get('x1')
        before = str(list(matriz[1].values()))
        op = mul / div
        print('Linea 2 menos linea 1 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[1][key] = matriz[1][key] - matriz[0].get(key) * op
        print(before + ' -----> ' + str(list(matriz[1].values())))

    if matriz[2].get('x1') != 0:
        mul = matriz[2].get('x1')
        div = matriz[0].get('x1')
        before = str(list(matriz[2].values()))
        op = mul / div
        print('Linea 3 menos linea 1 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[2][key] = matriz[2][key] - matriz[0].get(key) * op
        print(before + ' -----> ' + str(list(matriz[2].values())))

    if matriz[1].get('x2') != 1:
        div = matriz[1].get('x2')
        before = str(list(matriz[1].values()))
        print('Linea 2 entre ', div)
        for key in matriz[1].keys():
            matriz[1][key] = matriz[1].get(key) / div
        print(before + ' -----> ' + str(list(matriz[1].values())))

    if matriz[2].get('x2') != 0:
        before = str(list(matriz[2].values()))
        mul = matriz[2].get('x2')
        div = matriz[1].get('x2')
        op = mul / div
        print('Linea 3 menos linea 2 multiplicada por ', op)
        for key in matriz[0].keys():
            matriz[2][key] = matriz[2][key] - matriz[1].get(key) * op
        print(before + ' -----> ' + str(list(matriz[2].values())))

    if matriz[2].get('x3') != 1:
        before = str(list(matriz[2].values()))
        div = matriz[2].get('x3')
        print('Linea 3 entre ', div)
        for key in matriz[1].keys():
            matriz[2][key] = matriz[2].get(key) / div
        print(before + ' -----> ' + str(list(matriz[2].values())))

    print('----------------------------------')

    for m in matriz:
        print(str(list(m.values())))

    print('----------------------------------')

    if matriz[1].get('x3') != 0:
        mul = matriz[1].get('x3')
        before = str(list(matriz[1].values()))
        print('Linea 2 menos linea 3 multiplicada por ', mul)
        for key in matriz[1].keys():
            matriz[1][key] = matriz[1][key] - matriz[2][key] * mul
        print(before + ' -----> ' + str(list(matriz[1].values())))

    if matriz[0].get('x3') != 0:
        before = str(list(matriz[0].values()))
        mul = matriz[0].get('x3')
        print('Linea 1 menos linea 3 multiplicada por ', mul)
        for key in matriz[0].keys():
            matriz[0][key] = matriz[0][key] - matriz[2][key] * mul
        print(before + ' -----> ' + str(list(matriz[0].values())))

    if matriz[0].get('x2') != 0:
        before = str(list(matriz[0].values()))
        mul = matriz[0].get('x2')
        print('Linea 1 menos linea 2 multiplicada por ', mul)
        for key in matriz[0].keys():
            matriz[0][key] = matriz[0][key] - matriz[1][key] * mul
        print(before + ' -----> ' + str(list(matriz[0].values())))

    print('----------------------------------')

    for m in matriz:
        print(str(list(m.values())))

    print('----------------------------------')

    x1 = matriz[0]['r']
    print('x1 =', x1)
    x2 = matriz[1]['r']
    print('x2 =', x2)
    x3 = matriz[2]['r']
    print('x3 =', x3)
    print('\n\n\n')


def FakePos():
    ecu = interpreter(input('Ingrese la ecuacion evaluar: '))
    error = 0.001
    x0 = 0
    x = 0
    interval = 1
    E = 1
    Xm0 = 0
    out = []

    # Obtencion de los puntos iniciales
    while x == x0:
        for i in range(-100, 100, interval):
            Fa = float(eval(ecu.replace("u", str(i))))
            Fb = float(eval(ecu.replace("u", str(i + interval))))
            if Fa <= 0 and Fb >= 0:
                x0 = i
                x = i + 1
                break
        interval += interval + 1

    # Calculo de las iteraciones
    for i in range(1, 1000):
        Fx = float(eval(ecu.replace("u", str(x))))
        Fx0 = float(eval(ecu.replace("u", str(x0))))
        Xm = x - ((x - x0) * Fx / (Fx - Fx0))
        FXm = float(eval(ecu.replace("u", str(Xm))))

        if Xm0 == 0:
            dic = {'It': i, 'x0': x0, 'x': x, 'f(x0)': Fx0, 'f(x)': Fx, 'Xm': Xm}

        else:
            E = abs(Xm - Xm0)
            dic = {'It': i, 'x0': x0, 'x': x, 'f(x0)': Fx0, 'f(x)': Fx, 'Xm': Xm, 'Error': E}

        if FXm > 0:
            x = abs(Xm)

        elif FXm < 0:
            x0 = abs(Xm)

        out.append(dic)
        Xm0 = Xm

        if E < error:
            break

    text = str()
    for dictionary in out:
        for k, v in dictionary.items():
            if k == 'It':
                text = 'Iterasion ' + str(v) + '\n'

            else:
                text += '\t' + k + '= ' + '{:.5f}'.format(v) + '\n'
        print(text)


def main():
    # matriz = [{'x1': 4, 'x2': -9, 'x3': 2, 'r': 5}, {'x1': 2, 'x2': -4, 'x3': 6, 'r': 3}, {'x1': 1, 'x2': -1, 'x3': 3, 'r': 4}]
    matriz = MatrixGen()
    GaussJordan(matriz)
    Gauss(matriz)
    FakePos()


if __name__ == '__main__':
    main()

# x^3 + 2x^2 + 10x - 20
