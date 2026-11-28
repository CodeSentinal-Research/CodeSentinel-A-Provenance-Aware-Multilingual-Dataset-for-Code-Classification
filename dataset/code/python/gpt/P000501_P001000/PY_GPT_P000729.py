# problem title : Sudoku Solver
# Solve the stated task using standard input and standard output.
import sys
def solve_sudoku(board):
    def is_valid(r, c, ch):
        for i in range(9):
            if board[r][i] == ch or board[i][c] == ch: return False
            if board[3*(r//3) + i//3][3*(c//3) + i%3] == ch: return False
        return True
    def backtrack():
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    for d in '123456789':
                        if is_valid(r, c, d):
                            board[r][c] = d
                            if backtrack(): return True
                            board[r][c] = '.'
                    return False
        return True
    backtrack()
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        board = [list(tokens[i]) for i in range(9)]
        solve_sudoku(board)
        for row in board:
            print("".join(row))
if __name__ == '__main__':
    main()
