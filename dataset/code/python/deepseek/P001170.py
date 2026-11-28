def max_cherries(n):
    grid = []
    for _ in range(n):
        row = list(map(int, input().split()))
        grid.append(row)

    dp = [[-1] * n for _ in range(n)]

    def dfs(x, y):
        if x == n - 1 and y == n - 1:
            return grid[x][y]

        if dp[x][y] != -1:
            return dp[x][y]

        cherries = grid[x][y]
        cherries += max(
            dfs(x + 1, y),
            dfs(x, y + 1)
        )
        dp[x][y] = cherries
        return cherries

    print(dfs(0, 0))

def main():
    n = int(input().strip())
    max_cherries(n)

if __name__ == "__main__":
    main()