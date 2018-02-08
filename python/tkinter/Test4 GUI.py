import tkinter as tk

from tkinter import ttk
from tkinter.filedialog import askdirectory, askopenfilename

from typing import Any  # , Union, TypeVar


class Example(tk.Frame):

	def __init__(self, master: tk.Tk) -> None:
		self.master = master
		master.geometry('400x400')
		master.title("DML dggffg")

		self.label1 = ttk.Label(master, text="Select data folder:").grid(column=0, columnspan=1, row=1)
		self.Button_datapath = ttk.Button(master, text="", command=self.get_datapath).grid(column=1, absrow=1)
		self.Button_datapath = ttk.Button(master, text="select", command=self.get_datapath).grid(column=2, row=1)
		self.Button_datapath_help = ttk.Button(master, text="?", command=self.Q_datapath).grid(column=4, row=1)

		self.label2 = ttk.Label(master, text="Select output folder").grid(column=0, row=2)
		self.Button_savepath_help = ttk.Button(master, text="?", command=self.Q_savepath).grid(column=4, row=2)

		self.label3 = ttk.Label(master, text="exit program").grid(column=0, row=3)
		self.Button_exit = ttk.Button(master, text="Exit", command=self.close_all).grid(column=4, row=3)

		self.Button_go = ttk.Button(master, text="Go", command=self.go).grid(column=2, row=4)

	def get_datapath(self) -> None:
		self.data_dir = askdirectory()
		print(self.data_dir)
		return self.data_dir

	def Q_datapath(self) -> None:
		self.datapath = tk.Toplevel(self.master)
		self.datapath.geometry('300x200')
		self.datapath.title("Help: Data Path")
		self.Button_C = ttk.Button(self.datapath, text="Close", command=self.close_help)
		self.Button_C.pack(pady=10, ipadx=20)

	def close_help(self) -> None:
		if self.datapath:
			self.datapath.destroy()

	def Q_savepath(self) -> None:
		self.savepath = tk.Toplevel(self.master)
		self.savepath.geometry('300x200')
		self.savepath.title("Help: Save Path")
		self.Button_close_help = ttk.Button(self.savepath, text="Close", command=self.close_help2)
		self.Button_close_help.pack(pady=10, ipadx=20)

	def close_help2(self) -> None:
		if self.savepath:
			self.savepath.destroy()

	def close_all(self) -> None:
		self.master.destroy()

	def go(self) -> Any:
		print("this will run the programme eventually...")


if __name__ == '__main__':
	root = tk.Tk()
	app = Example(root)
	root.mainloop()
	# reveal_type(app)
