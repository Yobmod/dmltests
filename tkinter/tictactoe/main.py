import sys
import tkinter as tk
from tkinter import Button, Label
from tkinter.messagebox import showinfo
from itertools import permutations

from typing import List


class TTT(tk.Frame):
    def __init__(self, master: tk.Tk) -> None:
        self.master = master
        self._setupUI()
        self.y = ""
        self.x = 2
        self.player1: List[int] = []
        self.player2: List[int] = []

    def _setupUI(self) -> None:
        font_type = "times"
        font_size = 15
        font_def = f"{font_type} {font_size}"

        self.l1 = Label(self.master, text="player 1: X", font=font_def)
        self.l1.grid(row=0, column=1)

        self.l2 = Label(self.master, text="player 1: O", font=font_def)
        self.l2.grid(row=0, column=2)

        self.b1 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(1))
        self.b1.grid(row=1, column=1)

        self.b2 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(2))
        self.b2.grid(row=1, column=2)

        self.b3 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(3))
        self.b3.grid(row=1, column=3)

        self.b4 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(4))
        self.b4.grid(row=2, column=1)

        self.b5 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(5))
        self.b5.grid(row=2, column=2)

        self.b6 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(6))
        self.b6.grid(row=2, column=3)

        self.b7 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(7))
        self.b7.grid(row=3, column=1)

        self.b8 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(8))
        self.b8.grid(row=3, column=2)

        self.b9 = Button(self.master, width=20, height=10, command=lambda: self.define_sign(9))
        self.b9.grid(row=3, column=3)

        self.clear_b = Button(self.master, text="Clear", width=40, height=5, command=self.clear_game)
        self.clear_b.grid(row=4, column=1, columnspan=3)

    def clear_game(self) -> None:
        self.x = 2
        self.y = ""
        self.player1 = []
        self.player2 = []
        self.b1.config(text="")
        self.b2.config(text="")
        self.b3.config(text="")
        self.b4.config(text="")
        self.b5.config(text="")
        self.b6.config(text="")
        self.b7.config(text="")
        self.b8.config(text="")
        self.b9.config(text="")

    def define_sign(self, number: int) -> None:
        if number in self.player1 or number in self.player2:
            return

        if len(self.player1) >= 3:
            if check_win(self, self.player1) is True:
                return
        if len(self.player2) >= 3:
            if check_win(self, self.player2) is True:
                return

        if self.x % 2 == 0:  # even x
            self.y = "X"
            self.player1.append(number)
            print(self.player1)

        elif self.x % 2 != 0:  # odd x
            self.y = "O"
            self.player2.append(number)
            print(self.player2)

        self.x += 1

        y = self.y
        if number == 1:
            self.b1.config(text=y)
        elif number == 2:
            self.b2.config(text=y)
        elif number == 3:
            self.b3.config(text=y)
        elif number == 4:
            self.b4.config(text=y)
        elif number == 5:
            self.b5.config(text=y)
        elif number == 6:
            self.b6.config(text=y)
        elif number == 7:
            self.b7.config(text=y)
        elif number == 8:
            self.b8.config(text=y)
        elif number == 9:
            self.b9.config(text=y)

        if len(self.player1) >= 3:
            if check_win(self, self.player1) is True:
                return
        if len(self.player2) >= 3:
            if check_win(self, self.player2) is True:
                return


def check_win(self: TTT, player: List[int]) -> bool:
    player_name = "player 1" if player == self.player1 else "player 2"
    win_lists = [(1, 2, 3), (4, 5, 6), (7, 8, 9),
                 (1, 4, 7), (2, 5, 8), (3, 6, 9),
                 (1, 5, 9), (3, 5, 7)]
    for win_tup in win_lists:
        matches = [num for num in player if num in win_tup]
        if len(matches) >= 3:
            print(f"{player_name} Won!")
            showinfo("Result", f"{player_name} Won!")
            return True
    return False


if __name__ == "__main__":
    root = tk.Tk()
    w = 450
    h = 600
    size = f"{w}x{h}"
    root.geometry(size)
    app = TTT(root)
    root.mainloop()
