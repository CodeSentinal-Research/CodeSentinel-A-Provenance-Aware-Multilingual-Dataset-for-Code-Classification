import sys
def rat_in_maze(grid, n):
    if grid[0][0] == 0 or grid[n-1][n-1] == 0: return []
    res = []
    vis = [[False]*n for _ in range(n)]
    moves = [('D', 1, 0), ('L', 0, -1), ('R', 0, 1), ('U', -1, 0)]
    def backtrack(r, c, path):
        if r == n - 1 and c == n - 1:
            res.append(path)
            return
        vis[r][c] = True
        for move, dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 1 and not vis[nr][nc]:
                backtrack(nr, nc, path + move)
        vis[r][c] = False
    backtrack(0, 0, "")
    return sorted(res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        grid = []
        idx = 1
        for _ in range(n):
            grid.append(list(map(int, tokens[idx:idx+n])))
            idx += n
        paths = rat_in_maze(grid, n)
        for p in paths:
            print(p)
if __name__ == '__main__':
    main()