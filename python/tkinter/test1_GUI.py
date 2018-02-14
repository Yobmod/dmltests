#!/usr/bin/python
# -*- coding: utf-8 -*-
from PIL import Image, ImageTk
import tkinter as tk
import tkinter.ttk as ttk
from tkinter import Tk, Toplevel, Label, RIGHT, BOTH, RAISED
from tkinter.ttk import Frame, Style


class Example(Frame):

	def __init__(self, parent: Tk) -> None:
		Frame.__init__(self, parent)
		self.parent = parent
		self.initUI()

	def initUI(self) -> None:
		self.parent.title("Absolute positioning")
		self.pack(fill=BOTH, expand=1)
		Style().configure("TFrame", background="#333")
		#ttk.Style().configure("TLabel", borderwidth=10)

		bard = Image.open("lighthouse.jpg")
		bardejov = ImageTk.PhotoImage(bard)
		label1 = tk.Label(self, image=bardejov, borderwidth=5)
		label1.image = bardejov
		label1.place(x=20, y=20)

		rot = Image.open("Penguins.jpg")
		rotunda = ImageTk.PhotoImage(rot)
		label2 = ttk.Label(self, image=rotunda)  #, style="TLabel")
		label2.image = rotunda
		label2.place(x=40, y=160)

		minc = Image.open("Tulips.jpg")
		mincol = ImageTk.PhotoImage(minc)
		label3 = Label(self, image=mincol)
		label3.image = mincol
		label3.place(x=170, y=50)


def main(width: int=600, height: int=500) -> None:
	size = str(width) + "x" + str(height)
	root = Tk()
	root.geometry(size)  # widthxheight
	app = Example(root)
	root.mainloop()


if __name__ == '__main__':
	main(width=300, height=300)
