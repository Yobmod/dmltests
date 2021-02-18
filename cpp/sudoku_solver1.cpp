#include <iostream>
#include <iomanip>
#include <array>

using std::cout;
using std::cin;
using std::endl;

#define SIZE 9

/*
#include <vector>
std::vector<std::vector<int>> matrix = {
    {6, 5, 0, 8, 7, 3, 0, 9, 0},
    {0, 0, 3, 2, 5, 0, 0, 0, 8},
    {9, 8, 0, 1, 0, 4, 3, 5, 7},
    {1, 0, 5, 0, 0, 0, 0, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 5, 0, 3},
    {5, 7, 8, 3, 0, 1, 0, 2, 6},
    {2, 0, 0, 0, 4, 8, 9, 0, 0},
    {0, 9, 0, 6, 2, 5, 0, 8, 1}
    };
*/



#include <array>
std::array<std::array<int, SIZE>, SIZE> matrix = { {
    {6, 5, 0, 8, 7, 3, 0, 9, 0},
    {0, 0, 3, 2, 5, 0, 0, 0, 8},
    {9, 8, 0, 1, 0, 4, 3, 5, 7},
    {1, 0, 5, 0, 0, 0, 0, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 5, 0, 3},
    {5, 7, 8, 3, 0, 1, 0, 2, 6},
    {2, 0, 0, 0, 4, 8, 9, 0, 0},
    {0, 9, 0, 6, 2, 5, 0, 8, 1},
    } };

/*
int matrix[SIZE][SIZE] = {
    {6, 5, 0, 8, 7, 3, 0, 9, 0},
    {0, 0, 3, 2, 5, 0, 0, 0, 8},
    {9, 8, 0, 1, 0, 4, 3, 5, 7},
    {1, 0, 5, 0, 0, 0, 0, 0, 0},
    {4, 0, 0, 0, 8, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 5, 0, 3},
    {5, 7, 8, 3, 0, 1, 0, 2, 6},
    {2, 0, 0, 0, 4, 8, 9, 0, 0},
    {0, 9, 0, 6, 2, 5, 0, 8, 1}
    };
*/

//function to print sudoku
void print_sudoku() {

    for (size_t i = 0; i < SIZE; i++) {               // each col
        for (size_t j = 0; j < SIZE; j++) {           // each row
            cout << std::setw(5) << matrix[i][j];
        }
        cout << endl;

    }
    
    cout << endl << endl;
}

//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly
int number_unassigned(int* p_row, int* p_col) {
    int num_unassign = 0;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            //cell is unassigned
            if (matrix[i][j] == 0) {
                //changing the values of row and col
                *p_row = i;
                *p_col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;  //return early
            }
        }
    }
    return num_unassign;
}

//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c) {
    //checking in row
    for (size_t i = 0; i < SIZE; i++) {
        //there is a cell with same value
        if (matrix[r][i] == n) { 
            return 0;
        }
    }
    //checking column
    for (size_t i = 0; i < SIZE; i++) {
        //there is a cell with the value equal to i
        if (matrix[i][c] == n) {
            return 0;
        }
    }
    //checking sub matrix
    size_t row_start = (r / 3) * 3;
    size_t col_start = (c / 3) * 3;

    for (size_t i = row_start; i < row_start + 3; i++) {
        for (size_t j = col_start; j < col_start + 3; j++) {
            if (matrix[i][j] == n) {
                return 0;
            }
        }
    }
    return 1;
}

//function to solve sudoku
//using backtracking
int solve_sudoku()
{
    int row = 0;
    int col = 0;

    //if all cells are assigned then the sudoku is already solved
    //pass address because number_unassigned takes pointers to mutate the values of row and col
    if (number_unassigned(&row, &col) == 0)
        return 1;

    //number between 1 to 9
    for (size_t i = 1; i <= SIZE; i++) {
        //if we can assign i to the cell or not
        //the cell is matrix[row][col]
        if (is_safe(i, row, col)) {
            matrix[row][col] = i;

            //backtracking
            if (solve_sudoku()) {
                return 1;   // if solved, then end
            }
            else {
            //if we can't proceed with this solution
            //reassign the cell
            matrix[row][col] = 0;
            }
        }
    }
    return 0;
}

int main() {
    if (solve_sudoku()) {
        print_sudoku();
    }
    else
        cout << "No solution" << endl;


    cout << "Press ENTER key to Continue" << endl;
    cin.get();      // std::getchar();   // waits for ENTER
    return 0;
}