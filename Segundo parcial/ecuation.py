def interpreter(string):
    string = string.replace(" ", "")
    string = string.replace("x^8", "x**8")
    string = string.replace("x^7", "x**7")
    string = string.replace("x^6", "x**6")
    string = string.replace("x^5", "x**5")
    string = string.replace("x^4", "x**4")
    string = string.replace("x^3", "x**3")
    string = string.replace("x^2", "x**2")
    string = string.replace("x", "*u")
    string = string.replace("x+", "u+")
    string = "(" + string + ")"
    string = string.replace("(*", "(")
    string = string.replace("+*", "+")
    string = string.replace("-*", "-")
    return string
