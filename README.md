# sudoku_solver

This code is a C++ program that implements a recursive algorithm to solve a Sudoku puzzle. The main goal of the program is to take a partially filled Sudoku puzzle as input, where the empty cells are represented by '.', and then output the complete solved Sudoku puzzle.

The `helper` function is a recursive backtracking function that tries to solve the Sudoku puzzle. It takes the row index (`r`), column index (`c`), the Sudoku grid (`a`), and various data structures to keep track of numbers used in rows, columns, and 3x3 subgrids. The function first checks if the row index has reached 9, which indicates that the puzzle has been completely solved. If so, it prints the solved Sudoku and returns. If the column index reaches 9, the function moves to the next row. If the current cell is not empty, it moves to the next column. Otherwise, it tries placing numbers from 1 to 9 in the empty cell and proceeds recursively. It checks whether a number can be placed in the cell based on the rules of Sudoku (no repetition in rows, columns, and subgrids). If a solution is found, it's printed, and if not, backtracking occurs to explore other possibilities.

The `solvethissudoku` function initializes the data structures and performs preprocessing to mark filled cells in the input Sudoku. Then, it starts the solving process by calling the `helper` function.

In the `main` function, the program reads the partially filled Sudoku from the user, line by line. It prompts the user to input the puzzle, replacing empty cells with '.'. After reading the input, the program calls the `solvethissudoku` function to solve the puzzle and outputs the complete solved Sudoku.

Overall, this code provides an interactive way to input a Sudoku puzzle, solve it using a backtracking algorithm, and display the solution.
