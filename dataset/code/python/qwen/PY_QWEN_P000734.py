import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, sr, sc = int(d[0]), int(d[1]), int(d[2])
    board = [[-1]*n for _ in range(n)]
    moves = [(2,1),(1,2),(-1,2),(-2,1),(-2,-1),(-1,-2),(1,-2),(2,-1)]
    def rec(r, c, step):
        board[r][c] = step
        if step == n * n: return True
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and board[nr][nc] == -1:
                if rec(nr, nc, step + 1): return True
        board[r][c] = -1
        return False
    if rec(sr, sc, 1):
        for row in board: print(" ".join(map(str, row)))
    else:
        print("-1")
solve()
