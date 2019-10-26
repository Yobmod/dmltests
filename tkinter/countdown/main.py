import sys
import tkinter as tk

from typing import Any


class Countdown(tk.Frame):
    def __init__(self, master: tk.Tk) -> None:
        # tk.Frame.__init__(self, master)
        # super().__init__()
        self.master = master
        self._setupUI()
        self.t = 0

    def _setupUI(self) -> None:
        self.l1 = tk.Label(self.master, font="times 20")
        self.l1.grid(row=1, column=2)

        times = tk.StringVar()
        self.e1 = tk.Entry(self.master, textvariable=times)
        self.e1.grid(row=3, column=2)

        self.b1 = tk.Button(self.master, text="Set", width=20, command=self.set_timer)
        self.b1.grid(row=4, column=2, padx=20)

        self.add_b = tk.Button(self.master, text="Add", width=20, command=self.add_timer)
        self.add_b.grid(row=5, column=2, padx=20)

        self.b2 = tk.Button(self.master, text="Start", width=20, command=self.countdown)
        self.b2.grid(row=6, column=2, padx=20)

        self.clear_b = tk.Button(self.master, text="Clear", width=20, command=self.clear_timer)
        self.clear_b.grid(row=8, column=2, padx=20)



    def set_timer(self) -> int:
        try:
            self.t = int(self.e1.get())
            self.l1.config(text=self.t)
        except ValueError:
            print("Non-integer value given")
        finally:
            return self.t

    def add_timer(self) -> int:
        try:
            self.t = self.t + int(self.e1.get())
            self.l1.config(text=self.t)
        except ValueError:
            print("Non-integer value given")
        finally:
            return self.t

    def clear_timer(self) -> int:
        self.l1.config(text="")
        self.t = 0
        return self.t

    def countdown(self) -> None:
        if self.t > 0:
            self.l1.config(text=self.t)
            self.t = self.t - 1
            self.l1.after(1000, self.countdown)
        elif self.t == 0:
            print("end")
            self.l1.config(text="")







if __name__ == "__main__":
    root = tk.Tk()
    w = 200
    h = 200
    size = f"{w}x{h}"
    root.geometry(size)
    app = Countdown(root)
    root.mainloop()
