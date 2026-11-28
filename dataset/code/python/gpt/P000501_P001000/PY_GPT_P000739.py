# problem title : Count All Paths in a Maze
# Solve the stated task using standard input and standard output.
import sys
def count_paths(grid, n, m):
    if grid[0][0] == 0 or grid[n-1][m-1] == 0: return 0
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 1
    for r in range(n):
        for c in range(m):
            if grid[r][c] == 0: continue
            if r > 0: dp[r][c] += dp[r-1][c]
            if c > 0: dp[r][c] += dp[r][c-1]
    return dp[n-1][m-1]
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
        print(count_paths(grid, n, m))
if __name__ == '__main__':
    main()
