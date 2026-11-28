import sys
def flood_fill_paths(grid, n, m):
    if grid[0][0] == 0 or grid[n-1][m-1] == 0: return []
    res = []
    vis = [[False]*m for _ in range(n)]
    moves = [('D', 1, 0), ('L', 0, -1), ('R', 0, 1), ('U', -1, 0)]
    def backtrack(r, c, path):
        if r == n - 1 and c == m - 1:
            res.append(path)
            return
        vis[r][c] = True
        for move, dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 1 and not vis[nr][nc]:
                backtrack(nr, nc, path + move)
        vis[r][c] = False
    backtrack(0, 0, "")
    return sorted(res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        m = int(tokens[1])
        grid = []
        idx = 2
        for _ in range(n):
            grid.append(list(map(int, tokens[idx:idx+m])))
            idx += m
        for p in flood_fill_paths(grid, n, m):
            print(p)
if __name__ == '__main__':
    main()