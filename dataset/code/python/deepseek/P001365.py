Here's the Python code for the problem:

def solve():
    R, C = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(R)]

    dp = [[0] * C for _ in range(R)]
    dp[0][0] = grid[0][0]

    for i in range(R):
        for j in range(C):
            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j])
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j])

    print(dp[-1][-1])


def main():
    solve()


if __name__ == "__main__":
    main()

The code first reads the number of rows and columns and the gold grid. It then creates a dynamic programming (DP) table `dp` to store the maximum gold we can collect at each cell. The DP table is filled in a bottom-up manner, starting from the bottom right cell. For each cell, we calculate the maximum gold we can collect by moving right or down and adding the gold in the current cell.

Finally, the function prints the maximum gold we can collect in the bottom right cell.