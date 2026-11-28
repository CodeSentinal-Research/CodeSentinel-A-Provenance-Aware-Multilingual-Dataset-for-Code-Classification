def max_square_submatrix(N, M, K, matrix):
    dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            dp[i][j] = 1 if matrix[i-1][j-1] <= K else 0
            if dp[i][j]:
                for s in range(2, min(N - i + 1, M - j + 1) + 1):
                    dp[i][j] = min(dp[i][j], dp[i-s][j] + dp[i-s][j-1] + dp[i-s][j-2])
    
    return dp[N][M]

def main():
    N, M, K = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(N)]
    print(max_square_submatrix(N, M, K, matrix))

if __name__ == "__main__":
    main()