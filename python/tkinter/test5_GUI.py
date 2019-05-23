#!/usr/bin/env python
# -*- coding: utf-8 -*-
import tkinter as tk
import tkinter.ttk as ttk
from tkinter import BOTH, W, N, E, S  # , Tk, Toplevel, Text,
# from tkinter.ttk import Frame, Button, Label, Style


class Example(ttk.Frame):

	def __init__(self, parent: tk.Tk) -> None:
		ttk.Frame.__init__(self, parent)
		self.parent = parent
		self.initUI()

	def initUI(self) -> None:
		self.parent.title("Windows")
		self.pack(fill=tk.BOTH, expand=True)

		self.columnconfigure(1, weight=1)
		self.columnconfigure(3, pad=7)
		self.rowconfigure(3, weight=1)
		self.rowconfigure(5, pad=7)

		lbl = ttk.Label(self, text="Windows")
		lbl.grid(sticky=W, pady=4, padx=5)

		area = tk.Text(self)
		area.grid(row=1, column=0, columnspan=2, rowspan=4,
												padx=5, sticky=E + W + S + N)

		abttn = ttk.Button(self, text="Activate", command=self.greet_bttn)
		abttn.grid(row=1, column=3)

		cbttn = ttk.Button(self, text="Close", command=self.close_all)
		cbttn.grid(row=2, column=3, pady=4)

		hbttn = ttk.Button(self, text="Help", command=self.help_bttn)
		hbttn.grid(row=5, column=0, padx=5)

		obttn = ttk.Button(self, text="OK", command=self.go_bttn)
		obttn.grid(row=5, column=3)

	def greet_bttn(self) -> None:
		print("Greetings!")

	def help_bttn(self) -> None:
		help = tk.Toplevel()
		help.geometry('300x200')
		help.title("Help: Data Path")

		def close_help() -> None:
			help.destroy()
		Button_C = ttk.Button(help, text="Close", command=close_help)  # tk.Button, bg="color"
		Button_C.pack(pady=10, ipadx=20)

	def go_bttn(self) -> None:
		print("this will run the programme eventually...")

	def close_all(self) -> None:
		self.parent.destroy()


class HelpWindow(ttk.Frame):
	def __init__(self, parent: tk.Tk) -> None:
		ttk.Frame.__init__(self, parent)
		self.parent = parent
		# self.initUI()


def main() -> None:
	root = tk.Tk()
	root.geometry("350x300")
	Example(root)
	root.mainloop()


if __name__ == '__main__':
	main()
