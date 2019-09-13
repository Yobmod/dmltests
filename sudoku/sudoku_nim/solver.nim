import strformat
import times

const SIZE: int = 9

var 
  matrix: array[9, array[9, int]] = [
    [6, 5, 0, 8, 7, 3, 0, 9, 0],
    [0, 0, 3, 2, 5, 0, 0, 0, 8],
    [9, 8, 0, 1, 0, 4, 3, 5, 7],
    [1, 0, 5, 0, 0, 0, 0, 0, 0],
    [4, 0, 0, 0, 0, 0, 0, 0, 2],
    [0, 0, 0, 0, 0, 0, 5, 0, 3],
    [5, 7, 8, 3, 0, 1, 0, 2, 6],
    [2, 0, 0, 0, 4, 8, 9, 0, 0],
    [0, 9, 0, 6, 2, 5, 0, 8, 1]
    ]

  filled_matrix: array[9, array[9, int]] = [
    [6, 5, 1, 8, 7, 3, 2, 9, 4],
    [7, 4, 3, 2, 5, 9, 1, 6, 8],
    [9, 8, 2, 1, 6, 4, 3, 5, 7],
    [1, 2, 5, 4, 3, 6, 8, 7, 9],
    [4, 3, 9, 5, 8, 7, 6, 1, 2],
    [8, 6, 7, 9, 1, 2, 5, 4, 3],
    [5, 7, 8, 3, 9, 1, 4, 2, 6],
    [2, 1, 6, 7, 4, 8, 9, 3, 5],
    [3, 9, 4, 6, 2, 5, 7, 8, 1],
    ]

  hard_matrix: array[9, array[9, int]] = [
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

  hardest_matrix: array[9, array[9, int]] = [
    [8, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 3, 6, 0, 0, 0, 0, 0],
    [0, 7, 0, 0, 9, 0, 2, 0, 0],

    [0, 5, 0, 0, 0, 7, 0, 0, 0],
    [0, 0, 0, 0, 4, 5, 7, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0],

    [0, 0, 1, 0, 0, 0, 0, 6, 3],
    [0, 0, 8, 5, 0, 0, 0, 1, 0],
    [0, 9, 0, 0, 0, 0, 4, 0, 0],
    ]

  empty_matrix: array[9, array[9, int]] = [
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

  fake_matrix: array[9, array[9, int]] = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 9, 0],
    [0, 0, 0, 0, 0, 0, 0, 9, 9],
    ]

# function to print sudoku
proc print_sudoku(input: array[9, array[9, int]]) =

  var line: array[0..8, int] 

  for i in 0 .. SIZE - 1:
    line = input[i]
    stdout.write fmt"{line} "
    echo ""  # prints newline


proc number_unassigned(input: array[9, array[9, int]]): tuple[row: int, col: int, n_a: bool] = 
  # check if any number unassigned. if found report its position and true
  var 
    ret_tup: tuple[row: int, col: int, n_a: bool] = (0, 0, false)

  for i, row in input:
    for j, num in row:
      if num == 0:   # cell is unassigned
        # changing the values of row and col
        ret_tup = (i, j, true)
        return ret_tup  # return early
  return ret_tup

# function to check if we can put a value in a paticular cell or not
proc is_safe(input: array[9, array[9, int]], n: int, r: int, c: int): bool = 

  for i in 0 ..< SIZE:      # checking in row
    if input[r][i] == n:        # there is a cell with same value
      return false

  for i in 0 ..< SIZE:     # checking column
    if input[i][c] == n:  # there is a cell with the value equal to i
      return false
  
  #checking sub matrix
  let row_start: int = (r div 3) * 3
  let col_start: int = (c div 3) * 3

  for i in row_start ..< row_start + 3:
    for j in col_start ..< col_start + 3:
      if input[i][j] == n:
              return false

  return true

proc solve_sudoku(input: var array[9, array[9, int]]): bool = 
    # if all cells are assigned then the sudoku is already solved
    
  var unsolved = number_unassigned(input)

  if unsolved[2] == false:
    return true

  let 
    row: int = unsolved[0]
    col: int = unsolved[1]

  for num in 1 .. SIZE:
    # if we can assign i to the cell or not the cell is matrix[row][col]
    if is_safe(input, num, row, col):
      input[row][col] = num
        # backtracking
      if solve_sudoku(input):
        return true
      else: # if we can't proceed with this solution reassign the cell
          input[row][col] = 0

  return false

var 
  test = number_unassigned(matrix)
  filled = number_unassigned(filled_matrix)

if test.n_a == true:
  echo "test pass: unassigned number found"
else:
  echo "test_failed"

if filled.n_a == false:
  echo "test_pass: all numbers found"
else:
  echo "test_failed"


#var attempt_empty = solve_sudoku(empty_matrix)  # should work, but report error
#var attempt_fake = solve_sudoku(fake_matrix)  # should work, but report error

let start_time = cpuTime()
var solve_time: float

if solve_sudoku(matrix):
  solve_time = cpuTime() - start_time
  echo fmt"test pass: test matrix solved in {solve_time} seconds"
  print_sudoku(matrix)

else:
  echo "Failed test test"

if solve_sudoku(hard_matrix):
  solve_time = cpuTime() - start_time - solve_time
  echo fmt"test pass: difficult matrix in {solve_time} seconds"
  print_sudoku(hard_matrix)
else:
  echo "Failed test hard"

if solve_sudoku(hard_matrix):
  solve_time = cpuTime() - start_time - solve_time
  echo fmt"test pass: difficult matrix in {solve_time} seconds"
  print_sudoku(hard_matrix)
else:
  echo "Failed test hardest"
#[
if attempt_empty == true:
  echo "test pass: empty matrix solved (needs checks for multiple solutions)"
else:
  echo "test FAIL: why doesnt empty matrix work?"

if attempt_fake == false:
  echo "test pass: fake matrix should fail (needs checks of intial matrix)"
]#
