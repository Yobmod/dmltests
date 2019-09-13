from typing import List, Sequence
from typing_extensions import Final, Literal

sudokuType = Sequence[List[int]]  # Tuple and therefore sequence does not support index assignment

SIZE: Final[int] = 9
_: Literal[0] = 0

# sudoku problem
# cells with value 0 are vacant cells
test_matrix: List[List[int]] = [
    [6, 5, _, 8, 7, 3, _, 9, _],
    [_, _, 3, 2, 5, _, _, _, 8],
    [9, 8, _, 1, _, 4, 3, 5, 7],
    [1, _, 5, _, _, _, _, _, _],
    [4, _, _, _, _, _, _, _, 2],
    [_, _, _, _, _, _, 5, _, 3],
    [5, 7, 8, 3, _, 1, _, 2, 6],
    [2, _, _, _, 4, 8, 9, _, _],
    [0, 9, 0, 6, 2, 5, 0, 8, 1]]
# function to print sudoku


cdef print_sudoku(sudoku_matrix: sudokuType) -> None:
    for i in sudoku_matrix:
        print(i)

# function to check if all cells are assigned or not
# if there is any unassigned cell
# then this function will change the values of
# row and col accordingly


cdef number_unassigned(row: int, col: int) -> List[int]:
    num_unassign = 0
    for i in range(0, SIZE):
        for j in range(0, SIZE):
            #cell is unassigned
            if test_matrix[i][j] == 0:
                row = i
                col = j
                num_unassign = 1
                a = [row, col, num_unassign]
                return a
    a = [-1, -1, num_unassign]
    return a
# function to check if we can put a
# value in a paticular cell or not


cdef is_safe(sudoku_matrix: sudokuType,
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


cdef solve_sudoku(sudoku_matrix: sudokuType) -> bool:
    row = 0
    col = 0
    # if all cells are assigned then the sudoku is already solved
    # pass by reference because number_unassigned will change the values of row and col
    a = number_unassigned(row, col)
    if a[2] == 0:
        return True
    row = a[0]
    col = a[1]
    # number between 1 to 9
    for i in range(1, 10):
        # if we can assign i to the cell or not
        # the cell is matrix[row][col]
        if is_safe(sudoku_matrix, i, row, col):
            sudoku_matrix[row][col] = i
            # backtracking
            if solve_sudoku(sudoku_matrix):
                return True
            # f we can't proceed with this solution
            # reassign the cell
            sudoku_matrix[row][col] = 0
    return False


if solve_sudoku(test_matrix):
    print_sudoku(test_matrix)
else:
    print("No solution")

input("Press ENTER to quit")
