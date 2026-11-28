# problem title : Knight's Tour
# Solve the stated task using standard input and standard output.
import sys
def knights_tour(n, sr, sc):
    board = [[-1]*n for _ in range(n)]
    moves = [(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)]
    board[sr][sc] = 0
    def backtrack(r, c, step):
        if step == n * n: return True
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and board[nr][nc] == -1:
                board[nr][nc] = step
                if backtrack(nr, nc, step + 1): return True
                board[nr][nc] = -1
        return False
    if backtrack(sr, sc, 1):
        for row in board:
            print(*row)
    else:
        print(-1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        sr = int(tokens[1])
        sc = int(tokens[2])
        knights_tour(n, sr, sc)
if __name__ == '__main__':
    main()
