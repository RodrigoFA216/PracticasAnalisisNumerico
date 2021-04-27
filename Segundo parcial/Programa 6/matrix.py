def MatrixGen():
    mat = []
    for i in range(0, 3):
        print('linea ', i + 1)
        x1 = int(input('\tx1= '))
        x2 = int(input('\tx2= '))
        x3 = int(input('\tx3= '))
        r = int(input('\t r= '))
        line = {'x1': x1, 'x2': x2, 'x3': x3, 'r': r}
        mat.append(line)
    return mat