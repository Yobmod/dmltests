import tkinter as tk
from tkinter import ttk

# name and design the box
root = tk.Tk()
root.geometry('400x500')
root.title("DML QCM")


# define the functions
def Q_datapath() -> None:
    datapath = tk.Toplevel()
    datapath.geometry('300x200')
    datapath.title("Help: Data Path")

    def close_help() -> None:
        datapath.destroy()
    Button_C = tk.Button(datapath, text="Close", bg="darksalmon", command=close_help)
    Button_C.pack(pady=10, ipadx=20)


def Q_savepath() -> None:
    savepath = tk.Toplevel()
    savepath.geometry('300x200')
    savepath.title("Help: Save Path")

    def close_help() -> None:
        savepath.destroy()
    Button_close_help = tk.Button(savepath, text="Close", bg="darksalmon", command=close_help)
    Button_close_help.pack(pady=10, ipadx=20)


def close_all() -> None:
    root.destroy()


def go() -> None:
    print("this will run the pragramme eventually...")
    #from dmlQCM import P
    #P()


# label and give jobs to the buttons. Pack/grid/place to place them
ttk.Label(root, text="Select data folder").grid(column=0, row=1)
Button_datapath_help = ttk.Button(root, text="?", command=Q_datapath).grid(column=1, row=1)

ttk.Label(root, text="Select output folder").grid(column=0, row=2)
Button_savepath_help = ttk.Button(root, text="?", command=Q_savepath).grid(column=1, row=2)

ttk.Label(root, text="exit program").grid(column=0, row=3)
Button_exit = ttk.Button(root, text="Exit", command=close_all).grid(column=1, row=3)

Button_go = ttk.Button(root, text="Go", command=go).grid(column=1, row=4)

root.mainloop()
