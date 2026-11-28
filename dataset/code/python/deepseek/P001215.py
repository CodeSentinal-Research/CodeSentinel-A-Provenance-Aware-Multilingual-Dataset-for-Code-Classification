def max_points(colors):
    n = len(colors)
    dp = [[0]*n for _ in range(n)]
    sums = [[0]*n for _ in range(n)]
    for i in range(n):
        sums[i][i] = colors[i]
        for j in range(i+1, n):
            sums[i][j] = sums[i][j-1] + colors[j]

    for length in range(2, n+1):
        for i in range(n-length+1):
            j = i + length - 1
            dp[i][j] = sums[i+1][j] - sums[i][j] + max(dp[i+1][j], dp[i][j-1])
            if length % 2 == 0:
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + max(colors[i], colors[i+1:j]) * (length // 2))

    return dp[0][n-1]

def main():
    N = int(input().strip())
    colors = list(map(int, input().strip().split()))
    print(max_points(colors))

if __name__ == '__main__':
    main()