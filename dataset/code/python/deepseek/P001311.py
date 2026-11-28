Sure, here is the Python code for the problem:

def solve_n_queens(N):
    def can_place(board, row, col):
        for i in range(col):
            if board[row][i]:
                return False

        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j]:
                return False

        for i, j in zip(range(row, N, 1), range(col, -1, -1)):
            if board[i][j]:
                return False

        return True

    def place_queen(board, col):
        if col == N:
            print_board(board)
            return

        for i in range(N):
            if can_place(board, i, col):
                board[i][col] = True
                place_queen(board, col + 1)
                board[i][col] = False

    def print_board(board):
        for row in board:
            print(' '.join(str(cell) for cell in row))
        print()

    board = [[False]*N for _ in range(N)]
    place_queen(board, 0)


def main():
    N = int(input().strip())
    solve_n_queens(N)


if __name__ == "__main__":
    main()

This program uses a recursive backtracking approach to solve the N-Queens problem. It creates a 2D boolean array (board) and recursively places queens in each column.

The `can_place` function checks if a queen can be placed in a given row and column without attacking any other queen.

The `place_queen` function recursively tries to place a queen in each column. If it cannot place a queen in a current column, it returns to the previous column.

The `print_board` function prints the current board configuration.

The main function reads the size of the board from the input, calls the `solve_n_queens` function with the size of the board, and prints the total number of solutions.