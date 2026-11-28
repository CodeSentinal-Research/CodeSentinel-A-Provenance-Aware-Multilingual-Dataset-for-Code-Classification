Here is a Python solution using dynamic programming. The main idea is to keep track of the minimum sum of falling path at each cell.

def min_falling_path(matrix):
    n = len(matrix)
    dp = [[float('inf')] * n for _ in range(n)]
    dp[0] = matrix[0]

    for i in range(1, n):
        for j in range(n):
            for k in range(n):
                dp[i][j] = min(dp[i][j], dp[i-1][k] + matrix[i][j])
            dp[i][j] = min(dp[i][j], dp[i-1][(j-1)%n] + matrix[i][j])
            dp[i][j] = min(dp[i][j], dp[i-1][(j+1)%n] + matrix[i][j])

    return min(dp[-1])


def main():
    N = int(input().strip())
    matrix = []
    for _ in range(N):
        row = list(map(int, input().strip().split()))
        matrix.append(row)

    print(min_falling_path(matrix))


if __name__ == "__main__":
    main()

In this code, we first initialize a 2D list `dp` with `float('inf')` as its initial values. `dp[i][j]` will store the minimum sum of falling path starting at cell `(0, j)` and ending at cell `(i, j)`.

Then, for each cell `(i, j)` in the range 0 to N-1, we update `dp[i][j]` by taking the minimum of `dp[i][j]`, `dp[i-1][k] + matrix[i][j]`, where `k` ranges from 0 to N-1, and `dp[i-1][(j-1)%n] + matrix[i][j]`, `dp[i-1][(j+1)%n] + matrix[i][j]`.

Finally, we return the minimum sum of all falling paths from the bottom row of `dp`.