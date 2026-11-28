import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    N, M = int(d[0]), int(d[1])
    grid = [list(map(int, d[2+i*M:2+(i+1)*M])) for i in range(N)]
    res = []
    def rec(r, c, path, vis):
        if r == N - 1 and c == M - 1:
            res.append(path)
            return
        for dr, dc, d in [(1,0,'D'),(-1,0,'U'),(0,1,'R'),(0,-1,'L')]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M and grid[nr][nc] == 1 and (nr, nc) not in vis:
                vis.add((nr, nc))
                rec(nr, nc, path + d, vis)
                vis.remove((nr, nc))
    if grid[0][0] == 1:
        rec(0, 0, "", {(0, 0)})
    for x in sorted(res): print(x)
solve()
