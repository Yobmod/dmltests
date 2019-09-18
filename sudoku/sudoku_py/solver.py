from datetime import datetime, timedelta
import sys

from typing import List, Sequence, Union, Tuple, cast
from typing_extensions import Final, Literal


allowedNums = Literal[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
sudokuType = Sequence[List[allowedNums]]  # Tuple and therefore sequence does not support index assignment


SIZE: Final[int] = 9
_: Literal[0] = 0

# sudoku problem
# cells with value 0 are vacant cells
test_matrix: sudokuType = [
    [6, 5, _, 8, 7, 3, _, 9, _],
    [_, _, 3, 2, 5, _, _, _, 8],
    [9, 8, _, 1, _, 4, 3, 5, 7],
    [1, _, 5, _, _, _, _, _, _],
    [4, _, _, _, _, _, _, _, 2],
    [_, _, _, _, _, _, 5, _, 3],
    [5, 7, 8, 3, _, 1, _, 2, 6],
    [2, _, _, _, 4, 8, 9, _, _],
    [0, 9, 0, 6, 2, 5, 0, 8, 1]
]

insol_matrix: sudokuType = [
    [0, 0, 0, 7, 0, 0, 0, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 4, 3, 0, 2, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 6],
    [0, 0, 0, 5, 0, 9, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 4, 1, 8],
    [0, 0, 0, 0, 8, 1, 0, 0, 0],
    [0, 0, 2, 0, 0, 0, 0, 5, 0],
    [0, 4, 0, 0, 0, 0, 3, 0, 0],
]

empty_matrix: sudokuType = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
]

# function to print sudoku


def print_sudoku(sudoku_matrix: sudokuType) -> None:
    for i in sudoku_matrix:
        print(i)  # just prints each line

# function to check if all cells are assigned or not
# if there is any unassigned cell
# then this function will change the values of
# row and col accordingly


def number_unassigned(sudoku_matrix: sudokuType) -> Tuple[int, int, bool]:
    num_unassign = False

    for row in range(0, SIZE):
        for col in range(0, SIZE):
            #cell is unassigned
            if sudoku_matrix[row][col] == 0:
                num_unassign = True
                a = (row, col, num_unassign)
                return a
    a = (-1, -1, num_unassign)
    return a
# function to check if we can put a
# value in a paticular cell or not


def is_safe(sudoku_matrix: sudokuType,
            n: int,
            r: int,
            c: int) -> bool:
    #checking in row
    for i in range(0, SIZE):
        # there is a cell with same value
        if sudoku_matrix[r][i] == n:
            return False
    #checking in column
    for i in range(0, SIZE):
        # there is a cell with same value
        if sudoku_matrix[i][c] == n:
            return False
    row_start = (r // 3) * 3
    col_start = (c // 3) * 3
    # checking submatrix
    for i in range(row_start, row_start + 3):
        for j in range(col_start, col_start + 3):
            if sudoku_matrix[i][j] == n:
                return False
    return True

# function to check if we can put a
# value in a paticular cell or not


def solve_sudoku(sudoku_matrix: sudokuType) -> bool:
    # if all cells are assigned then the sudoku is already solved
    start_time = datetime.now()

    def time_it() -> None:
        rep_time = datetime.now() - start_time
        if rep_time > timedelta(0, 30):
            cont = input("30 seconds passed. Continue? Y/N\n")
        elif rep_time > timedelta(0, 60):
            cont = input("600 seconds passed. Continue? Y/N")
        else:
            cont = "Y"

        if cont in "Nn":
            sys.exit()

    def backtrack(sudoku_matrix: sudokuType) -> bool:

        row, col, unsolved = number_unassigned(sudoku_matrix)

        if unsolved is False:
            return True

        time_it()
        for i in range(1, 10):
            # if we can assign i to the cell or not the cell is matrix[row][col]

            if is_safe(sudoku_matrix, i, row, col):
                sudoku_matrix[row][col] = cast(allowedNums, i)
                # backtracking
                if backtrack(sudoku_matrix):
                    return True
                # if we can't proceed with this solution reassign the cell
                sudoku_matrix[row][col] = 0
        return False

    if backtrack(sudoku_matrix):
        return True
    else:
        return False


if solve_sudoku(test_matrix):
    print_sudoku(test_matrix)
else:
    print("wrongun")


if solve_sudoku(insol_matrix):
    print("\n solved insoluble matrix? HOW!")
    print_sudoku(insol_matrix)
else:
    print("Correct: No solution")


input("Press ENTER to quit")


"""
def must_be_1to5(num: Literal[1, 2, 3, 4, 5]) -> None:
    print(x)


must_be_1to5(8)

# x: Literal[1, 2, 3, 4, 5]
for x in range(1, 8):
    # x = cast(Literal[1, 2, 3, 4, 5], x)
    y: Literal[1, 2, 3, 4, 5] = cast(Literal[1, 2, 3, 4, 5], x)
    must_be_1to5(y)
"""
