import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    sr = int(input_data[idx]); idx += 1
    sc = int(input_data[idx]); idx += 1
    
    board = [[0]*n for _ in range(n)]
    moves = [(2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]
    
    def backtrack(move_num, r, c):
        if move_num == n * n:
            return True
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and board[nr][nc] == 0:
                board[nr][nc] = move_num + 1
                if backtrack(move_num + 1, nr, nc):
                    return True
                board[nr][nc] = 0
        return False
        
    board[sr][sc] = 1
    if backtrack(1, sr, sc):
        for row in board:
            print(" ".join(map(str, row)))
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

