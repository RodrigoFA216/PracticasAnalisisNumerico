from math import pow, fabs

class ecuation:
    def __init__(self, _array: str, _point: float, objetive: float):
        self.array = _array
        self.point = _point
        self.flag = False
        self.results = [_point]
        self.i = 0
        self.end = objetive
        self.total: float

    def proccess(self):
        done = False
        while(done == False):
            done = self.evaluate()

    def evaluate(self):
        preEc = self.processText(self.array)
        preEc = preEc.replace('u', str(self.point))
        self.total = eval(preEc)
        if self.flag == True:
            self.total = pow(self.total, 1 / 2)
        error = self.point - self.total
        if error < 0:
            error = error * -1
        if error > self.end:
            if self.total < self.point:
                print('Iterasion ', self.i,
                      ' tiene un valor de ',
                      "{:.5f}".format(self.total),
                      ' con un error de ',
                      "{:.5f}".format(error))
                self.point = self.total
                self.results.append(self.total)
                self.i += 1
                return False
            else:
                print('El despeje no converge')
                return True
        else:
            self.results.append(self.total)
            print('Se ha llegado al valor minimo en la iteracion ', self.i)
            for n in range(0, self.i + 1):
                print('Para la iterasion ', n, ' se tiene el punto :',
                      str("{:.5f}".format(self.results[n])), ' con un error de ',
                      abs(self.results[n-1] - self.results[n]))
            return True

    def processText(self, string: str):
        string = string.replace(" ", "")
        if(string.find('^1/2') != -1):
            self.flag = True
            string = string.replace('^1/2', '')
        string = string.replace("x^8", "*pow( u,8)")
        string = string.replace("x^7", "*pow( u,7)")
        string = string.replace("x^6", "*pow( u,6)")
        string = string.replace("x^5", "*pow( u,5)")
        string = string.replace("x^4", "*pow( u,4)")
        string = string.replace("x^3", "*pow( u,3)")
        string = string.replace("x^2", "*pow( u,2)")
        string = string.replace("x", "*u")
        string = string.replace("x+", "u+")
        string = "(" + string + ")"
        string = string.replace("(*", "(")
        string = string.replace("+*", "+")
        string = string.replace("-*", "-")
        return string
    # ((x+5)/2)^1/2

ecu = ecuation(input('Ingrese el despeje a evaluar: '),
               float(input('Ingrese el punto inicial a evaluar: ')),
               float(input('Maximo porcentaje de error: ')))

ecu.proccess()

