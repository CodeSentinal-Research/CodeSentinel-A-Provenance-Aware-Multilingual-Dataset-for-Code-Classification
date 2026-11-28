import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    board = [list(d[2+i*M:2+(i+1)*M]) for i in range(N)]
    word = d[2+N*M]
    def rec(r, c, idx, vis):
        if idx == len(word): return True
        if r < 0 or r >= N or c < 0 or c >= M or board[r][c] != word[idx] or (r, c) in vis: return False
        vis.add((r, c))
        if rec(r+1, c, idx+1, vis) or rec(r-1, c, idx+1, vis) or rec(r, c+1, idx+1, vis) or rec(r, c-1, idx+1, vis): return True
        vis.remove((r, c))
        return False
    for i in range(N):
        for j in range(M):
            if rec(i, j, 0, set()): print("true"); return
    print("false")
solve()
