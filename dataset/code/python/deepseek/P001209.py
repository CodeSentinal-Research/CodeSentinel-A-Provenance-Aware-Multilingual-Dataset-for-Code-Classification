def stone_game(N, A):
    prefix_sum = [0] * (N + 1)
    for i in range(N):
        prefix_sum[i + 1] = prefix_sum[i] + A[i]
    dp = [[0] * (N + 1) for _ in range(N + 1)]
    for length in range(2, N + 1):
        for left in range(1, N - length + 2):
            right = left + length - 1
            dp[left][right] = max(prefix_sum[right] - prefix_sum[left] - dp[left + 1][right], prefix_sum[right - 1] - prefix_sum[left - 1] - dp[left][right - 1])
    if dp[1][N] > prefix_sum[N] - prefix_sum[1]:
        return 'Alice'
    elif dp[1][N] < prefix_sum[N] - prefix_sum[1]:
        return 'Bob'
    else:
        return 'Tie'

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    print(stone_game(N, A))

if __name__ == "__main__":
    main()