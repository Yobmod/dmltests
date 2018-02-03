import tkinter as tk
# from tkinter.tk import tkk
from typing import Optional, Union, Any
import brainfuck


class Application(tk.Frame):
	def __init__(self, master: Any=None) -> None:
		super().__init__(master)
		self.pack()
		self.create_widgets()

	def create_widgets(self) -> None:
		self.hi_there = tk.Button(self)
		self.hi_there["text"] = "Hello World\n(click me)"
		self.hi_there["command"] = self.say_hi
		self.hi_there.pack(side="top")

		self.bf_button = tk.Button(self, text="Brainfuck", command=self.bf_command)
		self.bf_button.pack(side="bottom")

		self.quit = tk.Button(self, text="QUIT", fg="red", command=root.destroy)
		self.quit.pack(side="bottom")

	"""
	radiobutton for src = input field OR src = file
	bf button command takes source and outputs
	optional input fields for bf() in subwindow
	"""

	def bf_command(self) -> None:
		bf_src = self.bf_src()
		bf_output = brainfuck.bf(bf_src)
		bf_outputstr = " ".join(x.encode('UTF-8').decode('unicode_escape') for x in bf_output)
		print(len(bf_output), len(bf_outputstr))

	def bf_src(self) -> str:
		src = "++.>+++.>+++++++."
		return src

	def say_hi(self) -> None:
		print("hi there, everyone!")


root = tk.Tk()
app = Application(master=root)
app.mainloop()
