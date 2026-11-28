def probability(N, K, R, C):
    dp = [[0] * N for _ in range(N)]
    dp[R][C] = 1
    for k in range(K):
        for r in range(N):
            for c in (range(N) if r else range(C + 1)):
                if r:
                    dp[r][c] += dp[r-1][c] * 0.125
                if c and r < N - 1:
                    dp[r][c] += dp[r][c+1] * 0.125
                if r < N - 1:
                    dp[r][c] += dp[r+1][c] * 0.125
                if c:
                    dp[r][c] += dp[r][c-1] * 0.125
    return dp[R][C]

def main():
    N, K, R, C = map(int, input().split())
    print(f'{probability(N, K, R, C):.9f}')

if __name__ == '__main__':
    main()