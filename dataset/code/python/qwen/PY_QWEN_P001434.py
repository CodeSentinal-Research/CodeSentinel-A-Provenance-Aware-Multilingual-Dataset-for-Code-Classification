import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    board = [[' ']*3 for _ in range(3)]
    moves = []
    for _ in range(n):
        r = int(input_data[idx]); idx += 1
        c = int(input_data[idx]); idx += 1
        moves.append((r, c))
        
    player = 'X'
    winner = None
    
    for r, c in moves:
        board[r][c] = player
        # Check win
        if all(board[r][i] == player for i in range(3)) or \
           all(board[i][c] == player for i in range(3)) or \
           (r == c and all(board[i][i] == player for i in range(3))) or \
           (r + c == 2 and all(board[i][2-i] == player for i in range(3))):
            winner = player
            break
        player = 'O' if player == 'X' else 'X'
        
    if winner:
        print(winner)
    elif n == 9:
        print("DRAW")
    else:
        print("PENDING")

solve()

