import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    maze = [list(map(int, d[1+i*n:1+(i+1)*n])) for i in range(n)]
    res = []
    def rec(r, c, path, vis):
        if r == n - 1 and c == n - 1:
            res.append(path)
            return
        for dr, dc, d in [(1,0,'D'),(-1,0,'U'),(0,1,'R'),(0,-1,'L')]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and maze[nr][nc] == 1 and (nr, nc) not in vis:
                vis.add((nr, nc))
                rec(nr, nc, path + d, vis)
                vis.remove((nr, nc))
    if maze[0][0] == 1:
        rec(0, 0, "", {(0, 0)})
    for x in sorted(res): print(x)
solve()
