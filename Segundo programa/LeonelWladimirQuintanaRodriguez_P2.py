from tkinter import *
# from PIL import Image, ImageTk, ImageSequence
# import numpy as np
import math


def work(item):
    ecu = processText(item)

    x1 = 0
    x2 = 0
    interval = 1

    error = float()

    while x1 == x2:
        for i in range(-100, 100, interval):
            a = float(eval(ecu.replace("u", str(i))))
            b = float(eval(ecu.replace("u", str(i + 1))))
            print("Para ", i, "y ", i + 1, ": ", a, " ", b)
            if a <= 0 and b >= 0:
                x1 = i
                x2 = i + 1
                break
    interval += interval + 1

    n = (math.log(x2 - x1) - math.log(0.001)) / (math.log(2))

    print('\nNumero de iterasiones: ', n)
    n = math.ceil(n)
    print('Numero de iterasiones real: ', n, '\n')

    for j in range(9, n + 9):
        xm = (x1 + x2) / 2
        fmx = eval(ecu.replace("u", str(xm)))
        for i in range(2, 8):
            table = Label(mainWin, width=9)
            table.config(fg="black", bg="white", font=("Arial", 12))
            table.grid(row=j, column=i)
            if i == 2:
                table.config(text=j - 8)
            if i == 3:
                table.config(text="{:.5f}".format(x1))
            if i == 4:
                table.config(text="{:.5f}".format(x2))
            if i == 5:
                table.config(text="{:.5f}".format(xm))
            if i == 6:
                table.config(text="{:.5f}".format(fmx))
            if i == 7:
                table.config(text="{:.5f}".format(abs(xm - error)))
        if fmx > 0:
            x2 = xm
            error = x1
        if fmx < 0:
            x1 = xm
            error = x2


def processText(intro):
    intro = intro.replace(" ", "")
    intro = intro.replace("x9", "*pow( u,9)")
    intro = intro.replace("x8", "*pow( u,8)")
    intro = intro.replace("x7", "*pow( u,7)")
    intro = intro.replace("x6", "*pow( u,6)")
    intro = intro.replace("x5", "*pow( u,5)")
    intro = intro.replace("x4", "*pow( u,4)")
    intro = intro.replace("x3", "*pow( u,3)")
    intro = intro.replace("x2", "*pow( u,2)")
    intro = intro.replace("x", "*u")
    intro = "(" + intro + ")"
    intro = intro.replace("(*", "(")
    intro = intro.replace("+*", "+")
    intro = intro.replace("-*", "-")
    return intro


def txtGui():
    item = processText(enter.get(1.0, END))
    print(item)
    enter.delete(1.0, END)
    work(item)


mainWin = Tk()
mainWin.geometry("900x600")
mainWin.title('Metodo de biseccion')

for c in range(2, 8):
    cell = Label(mainWin, width=9)
    cell.config(fg="black", bg="white", font=("Arial", 12))
    cell.grid(row=8, column=c)
    if c == 2:
        cell.config(text='Iterasion')
    if c == 3:
        cell.config(text='Xi')
    if c == 4:
        cell.config(text='Xd')
    if c == 5:
        cell.config(text='Xm')
    if c == 6:
        cell.config(text='f(Xm)')
    if c == 7:
        cell.config(text='Error')

enter = Text(mainWin, font="Arial 12", width=30, height=1)
start = Button(mainWin, text="Start", command=txtGui, width=10, height=3)
label = Label(mainWin, text="f(x)", font="Arial 12", width=4, height=1)
enter.grid(row=0, column=1)
start.grid(row=1, column=1)
label.grid(row=0, column=0)

mainWin.mainloop()

# 1x3 + 2x2 + 10x - 20

# file = r".\teemo.gif"
# canvas = Canvas(mainWin, width=200, height=200)
# canvas.pack()
# sequence = [ImageTk.PhotoImage(img) for img in ImageSequence.Iterator(Image.open(r'.\teemo.gif'))]
# image = canvas.create_image(100, 100, image=sequence[0])
# animate(1)

# canvas.grid(row=4, column=0, columnspan=2, rowspan=20, padx=10, pady=10)

# def animate(counter):
# canvas.itemconfig(image, image=sequence[counter])
# mainWin.after(50, lambda: animate((counter + 1) % len(sequence)))
