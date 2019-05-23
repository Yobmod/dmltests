import tkinter as tk
from tkinter import ttk
from typing import Optional  # , Union, Any
import brainfuck


class Application(tk.Frame):

	def __init__(self, master: Optional[tk.Tk]=None) -> None:
		super().__init__(master)
		self.pack()
		self.create_widgets()
		style = ttk.Style()
		style.configure("R.TButton", foreground="red", background="red")
		style.configure("G.TButton", foreground="green", background="green")

	def create_widgets(self) -> None:

		self.hi_there = ttk.Button(self)
		self.hi_there["text"] = "Hello World\n(click me)"
		self.hi_there["command"] = self.say_hi
		self.hi_there["style"] = "G.TButton"
		self.hi_there.pack(side="top")

		self.bf_button = ttk.Button(self, text="Brainfuck", command=self.bf_command)
		self.bf_button.pack(side="top")

		self.quit_button = ttk.Button(self, text="QUIT", style="R.TButton", command=root.destroy)
		self.quit_button.pack(side="bottom")

	"""
	* radiobutton for src = input field OR src = file
	* bf button command takes source and outputs
	* optional input fields for bf() in subwindow
	"""

	def bf_command(self) -> None:
		bf_src = self.bf_src()
		bf_outputstr = brainfuck.bf(bf_src)
		# len(bf_outputstr))
		print(bf_outputstr)

	def bf_src(self) -> str:
		src = "+.>+++.>+++++++++++.>"
		return src

	def say_hi(self) -> None:
		print("hi there, everyone!")


root = tk.Tk()
app = Application(master=root)
app.mainloop()
