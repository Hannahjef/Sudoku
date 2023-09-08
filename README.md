# Sudoku
## Solving sudoku with backtracking

### Specification:
Sudoku:
The basic Sudoku game begins with a grid of 81 squares and many starter (fixed) numbers. Generally, the
more starter numbers there are, the easier the problem. The grid is split into nine 3x3 blocks, each of which
has nine squares. Each number (1-9) can only occur once in a row, column, or block.

The program's goal is to solve the sudoku problem by taking user input and marking the numbers 1-9 as
fixed and 0 as variable, then solving the puzzle by filling in the variable squares using recursive backtracking
to obtain the best suitable solution. If the provided problem is unsolvable, we must inform the user.
The program is composed of two classes Puzzle which represents the overall puzzle and Puzzle::Square
class which represents each puzzle. The square class is nested inside the puzzle class.
Input:
The program will obtain input values from the user via the input Stream. This is accomplished by
overloading the extraction operator >>. Only the first 81 digits containing (0-9) are considered.
If the input contains alphabets or spaces, those characters should be ignored.
The numbers 1 through 9 are assigned as fixed values and should not be changed, while the number 0
represents the value that must be solved.
The input 81 numbers are given like shown in the example and later extracted to separate squares.
The received input are checked and placed in the corresponding squares in the Puzzle places in row-major
order (starting at the upper left corner, reading across each row and then continuing with the next row,
ending at the bottom right corner).

### Output:
The output is displayed by overloading the insertion operator <<. It is displayed in the user readable sudoku
format by outputting puzzle with 11 lines of text, each having a row of numbers from the problem, each
separated by a single space. To split 3-by-3 blocks, use the '|', '+', and '-' symbols. As a result, each line of
output must be 19 printing characters long (9 numbers, 8 spaces, and 2 '|' for "non-divider" lines, and 17 '-'
and 2 '+' for "divider" lines).
If the given user input is not solvable then the output should be stated so.
