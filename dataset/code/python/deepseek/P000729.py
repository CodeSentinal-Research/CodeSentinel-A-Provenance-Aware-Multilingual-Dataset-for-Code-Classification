Here's the Python code for the Sudoku Solver:

def solveSudoku(board):
    empty = '.'
    numbers = set(range(1,10))

    def is_valid(bo, row, col, num):
        for i in range(9):
            if bo[row][i] == num:
                return False

        for i in range(9):
            if bo[i][col] == num:
                return False

        box_row, box_col = row - row%3, col - col%3
        for i in range(3):
            for j in range(3):
                if bo[i+box_row][j+box_col] == num:
                    return False
        return True

    def solve(bo):
        for i in range(9):
            for j in range(9):
                if bo[i][j] == empty:
                    for num in numbers:
                        if is_valid(bo, i, j, num):
                            bo[i][j] = num
                            if solve(bo):
                                return True
                            else:
                                bo[i][j] = empty
                    return False
        return True

    solve(board)

And the main function:

def main():
    board = [['5','3','.'],['6','9','.'],['1','.','7']]
    solveSudoku(board)
    for row in board:
        print(row)

if __name__ == '__main__':
    main()

This program uses a recursive backtracking algorithm to solve the Sudoku puzzle. The function `is_valid` checks if a number can be placed at a given row and column in a Sudoku board. If the number is valid, it recurses on the rest of the board. If not, it returns False. The `solve` function attempts to place numbers on the board and recursively solves the board if there are no more valid numbers to place.