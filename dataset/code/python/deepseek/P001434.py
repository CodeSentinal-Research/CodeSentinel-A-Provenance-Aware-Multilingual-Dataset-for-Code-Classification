def tic_tac_toe():
    N = int(input().strip())
    moves = [input().strip() for _ in range(N)]

    board = [[' ' for _ in range(N)] for _ in range(N)]

    for move in moves:
        x, y = map(int, move.split())
        board[x][y] = 'X' if len(move) == 1 else 'O'

    def check_winner(board, N):
        for i in range(N):
            if board[i][0] == board[i][1] == board[i][2] != ' ':
                return board[i][0]
        for i in range(N):
            if board[0][i] == board[1][i] == board[2][i] != ' ':
                return board[0][i]
        if board[0][0] == board[1][1] == board[2][2] != ' ':
            return board[0][0]
        if board[0][2] == board[1][1] == board[2][0] != ' ':
            return board[0][2]
        return 'PENDING' if ' ' not in (board[0][0], board[0][1], board[0][2],
                                      board[1][0], board[1][1], board[1][2],
                                      board[2][0], board[2][1], board[2][2]) else 'DRAW'

    result = check_winner(board, N)
    print(result)


if __name__ == '__main__':
    tic_tac_toe()