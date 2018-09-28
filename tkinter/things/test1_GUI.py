#!/usr/bin/python
# -*- coding: utf-8 -*-
from PIL import Image, ImageTk
import tkinter as tk
import tkinter.ttk as ttk


class Example(ttk.Frame):

	def __init__(self, parent: tk.Tk) -> None:
		ttk.Frame.__init__(self, parent)
		self.parent = parent
		self.initui()

	def initui(self) -> None:
		self.parent.title("Absolute positioning")
		self.pack(fill=tk.BOTH, expand=1)
		style = ttk.Style()
		style.configure("TFrame", background="#333")
		style.configure("dml.TLabel", background="white")

		bard = Image.open("lighthouse.jpg").resize((300, 200))
		bardejov = ImageTk.PhotoImage(bard)
		label1 = tk.Label(self, image=bardejov, borderwidth=10)
		label1.image = bardejov
		label1.place(x=20, y=20)
		# print(width)

		rot = Image.open("Penguins.jpg")
		rotunda = ImageTk.PhotoImage(rot)
		label2 = ttk.Label(self, image=rotunda, style="dml.TLabel")
		label2.image = rotunda
		label2.place(x=40, y=160)

		minc = Image.open("Tulips.jpg")
		width, height = minc.size
		ratio = 2; new_size = (int(width / ratio), int(height / ratio))
		minc = minc.resize(new_size)
		mincol = ImageTk.PhotoImage(minc)
		label3 = tk.Label(self, image=mincol)
		label3.image = mincol
		label3.place(x=170, y=50)


def main(width: int=600, height: int=500) -> None:
	size = str(width) + "x" + str(height)
	root = tk.Tk()
	root.geometry(size)  # widthxheight
	app = Example(root)
	app.mainloop()


if __name__ == '__main__':
	main(width=300, height=300)
