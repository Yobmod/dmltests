import tkinter as tk
from tkinter import ttk
from tkinter.filedialog import askdirectory, askopenfilename
# from tkinter.ttk import Frame, Button, Label

from typing import Any, Optional  #, NewType, Union, TypeVar

#FileType = NewType('FileType', str)
FileType = str
PathType = str


class Example(ttk.Frame):
	def __init__(self, master: tk.Tk) -> None:
		ttk.Frame.__init__(self, master)
		super().__init__()
		self.master = master
		# master.geometry('400x400')
		# master.title("DML dggffg")
#		self.columnconfigure(0, weight=1, uniform=1, pad=1)
#		self.columnconfigure(1, weight=1, uniform=1, pad=1)
#		self.columnconfigure(2, weight=1, uniform=1, pad=1)
#		self.columnconfigure(3, weight=1, uniform=1, pad=1)
#		self.rowconfigure(1, weight=1, pad=7)
#		self.rowconfigure(2, pad=7)
		self.create_row0()
		self.create_row1()
		self.create_row2()
		self.create_row3()
		self.create_row4()

	def create_row0(self) -> None:
		label0 = ttk.Label(self.master, text="")
		label0.grid(column=0, columnspan=5, row=0)

	def create_row1(self) -> None:
		label1 = ttk.Label(self.master, text="Select data folder:")
		label1.grid(column=0, columnspan=1, row=1, padx=5, pady=5)

		Button_datapath = ttk.Button(self.master, text="", command=self.get_datapath)
		Button_datapath.grid(column=1, row=1, padx=5)

		Button_datapath2 = ttk.Button(self.master, text="select", command=self.get_datafile)
		Button_datapath2.grid(column=2, row=1)

		Button_datapath_help = ttk.Button(self.master, text="?", command=self.Q_datapath)
		Button_datapath_help.grid(column=4, row=1)

	def create_row2(self) -> None:
		label2 = ttk.Label(self.master, text="Select output folder")
		label2.grid(column=0, row=2, padx=10, pady=5)

		Button_savepath_help = ttk.Button(self.master, text="?", command=self.Q_savepath)
		Button_savepath_help.grid(column=4, row=2)

	def create_row3(self) -> None:
		label3 = ttk.Label(self.master, text="exit program")
		label3.grid(column=0, row=3, padx=10, pady=5)

		Button_exit = ttk.Button(self.master, text="Exit", command=self.close_all)
		Button_exit.grid(column=4, row=3)

	def create_row4(self) -> None:
		Button_go = ttk.Button(self.master, text="Go", command=self.go)
		Button_go.grid(column=5, row=4)

	def get_datapath(self) -> str:
		data_dir: PathType = askdirectory()
		print(data_dir)
		return data_dir

	def get_datafile(self) -> str:
		data_file: FileType = askopenfilename()
		print(data_file)
		return data_file

	def Q_datapath(self) -> None:
		self.datapath = tk.Toplevel(self.master)
		self.datapath.geometry('300x200')
		self.datapath.title("Help: Data Path")
		self.Button_C = ttk.Button(self.datapath, text="Close", command=self.datapath.destroy)
		self.Button_C.pack(pady=10, ipadx=20)

	def Q_savepath(self) -> None:
		self.savepath = tk.Toplevel(self.master)
		self.savepath.geometry('300x200')
		self.savepath.title("Help: Save Path")
		self.Button_close_help = ttk.Button(self.savepath, text="Close", command=self.savepath.destroy)
		self.Button_close_help.pack(pady=10, ipadx=20)

	def close_all(self) -> None:
		self.master.destroy()

	def go(self) -> Any:
		print("this will run the programme eventually...")


def main(width: int=500, height: int=500) -> None:
	size = str(width) + "x" + str(height)
	root = tk.Tk()
	root.geometry(size)
	root.title("DML dggffg")
	root.iconbitmap('favicon.ico')
	app = Example(root)
	root.mainloop()


if __name__ == '__main__':
	main()
	# reveal_type(app)
