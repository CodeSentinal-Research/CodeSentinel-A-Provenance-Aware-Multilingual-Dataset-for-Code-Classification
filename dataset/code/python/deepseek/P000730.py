Here is the Python code:

def solve_n_queens(N):
    def can_place(board, row, column):
        for i in range(row):
            if board[i][column] == 1:
                return False

        for i, j in zip(range(row, -1, -1), range(column, -1, -1)):
            if board[i][j] == 1:
                return False

        for i, j in zip(range(row, -1, -1), range(column, N)):
            if board[i][j] == 1:
                return False

        return True

    def solve(board, row):
        if row == N:
            print_board(board)
            print()
            return

        for column in range(N):
            if can_place(board, row, column):
                board[row][column] = 1
                solve(board, row + 1)
                board[row][column] = 0

    def print_board(board):
        for row in board:
            print(' '.join(str(cell) for cell in row))
        print()

    board = [[0] * N for _ in range(N)]
    solve(board, 0)


if __name__ == "__main__":
    while True:
        try:
            N = int(input("Enter the value of N: "))
            if N < 1 or N > 12:
                raise ValueError("Input should be in range 1 <= N <= 12")
            solve_n_queens(N)
        except ValueError as e:
            print(e)

In this code, we are using a recursive function `solve()` to place the queens on the board. If a queen can be placed in a column, it is placed there and then recursion is called for the next row. If a queen cannot be placed in the current column, it is backtracked and tries the next column.

The function `can_place()` is used to check if a queen can be placed in a specific location on the board or not.

In the main function, a while loop is used to keep asking for input until a valid input is provided.