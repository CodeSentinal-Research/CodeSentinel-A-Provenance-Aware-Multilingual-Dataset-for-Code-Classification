def get_paths(grid, target):
    N = len(grid)
    M = len(grid[0])

    dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
    dp[N][M] = 1 if grid[N - 1][M - 1] == target else 0

    for i in range(N - 1, -1, -1):
        for j in range(M - 1, -1, -1):
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1]

    return dp[0][0]


def main():
    N, M, Target = map(int, input().split())
    grid = [[int(cell) for cell in input().split()] for _ in range(N)]
    print(get_paths(grid, Target))


if __name__ == "__main__":
    main()