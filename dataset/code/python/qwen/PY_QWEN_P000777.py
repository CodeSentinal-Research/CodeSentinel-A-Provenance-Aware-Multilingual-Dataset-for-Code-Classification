import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N = int(d[0])
    grid = [list(d[1+i*N:1+(i+1)*N]) for i in range(N)]
    W = int(d[1+N*N])
    words = d[2+N*N:2+N*N+W]
    def rec(idx):
        if idx == W: return True
        for i in range(N):
            for j in range(N):
                if grid[i][j] == '.':
                    can_h = j + len(words[idx]) <= N and all(grid[i][j+k] in ['.', words[idx][k]] for k in range(len(words[idx])))
                    if can_h:
                        for k in range(len(words[idx])): grid[i][j+k] = words[idx][k]
                        if rec(idx + 1): return True
                        for k in range(len(words[idx])): grid[i][j+k] = '.'
                    can_v = i + len(words[idx]) <= N and all(grid[i+k][j] in ['.', words[idx][k]] for k in range(len(words[idx])))
                    if can_v:
                        for k in range(len(words[idx])): grid[i+k][j] = words[idx][k]
                        if rec(idx + 1): return True
                        for k in range(len(words[idx])): grid[i+k][j] = '.'
        return False
    rec(0)
    for row in grid: print("".join(row))
solve()
