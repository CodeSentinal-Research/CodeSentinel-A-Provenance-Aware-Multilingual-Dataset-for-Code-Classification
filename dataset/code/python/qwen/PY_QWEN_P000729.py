import sys
def solve():
    board = [list(sys.stdin.readline().strip()) for _ in range(9)]
    def rec(idx):
        if idx == 81: return True
        r, c = idx // 9, idx % 9
        if board[r][c] != '.': return rec(idx + 1)
        for i in range(1, 10):
            ch = str(i)
            if ch in board[r] or ch in [board[x][c] for x in range(9)] or ch in [board[r//3*3+x//3][c//3*3+x%3] for x in range(9)]: continue
            board[r][c] = ch
            if rec(idx + 1): return True
            board[r][c] = '.'
        return False
    rec(0)
    for row in board: print("".join(row))
solve()
