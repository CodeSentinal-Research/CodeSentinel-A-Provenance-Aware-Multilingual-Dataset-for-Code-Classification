def solve(n):
    def can_place(board, row, col):
        for i in range(col):
            if board[row][i]:
                return False

        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j]:
                return False

        for i, j in zip(range(row, n, -1), range(col, -1, -1)):
            if board[i][j]:
                return False

        return True

    def solve_n_queens(board, col):
        if col == n:
            print_board(board)
            return 1

        count = 0
        for i in range(n):
            if can_place(board, i, col):
                board[i][col] = True
                count += solve_n_queens(board, col + 1)
                board[i][col] = False

        return count

    def print_board(board):
        for i in range(n):
            for j in range(n):
                print('X' if board[i][j] else 'O', end=' ')
            print()
        print()

    n = int(input())

    board = [[False]*n for _ in range(n)]

    print(solve_n_queens(board, 0))