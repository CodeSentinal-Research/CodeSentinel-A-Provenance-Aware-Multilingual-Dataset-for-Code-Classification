def solve():
    N, Difference = map(int, input().split())
    arr = list(map(int, input().split()))

    dp = [1] * N
    for i in range(N):
        for j in range(i):
            if arr[i] - arr[j] == Difference:
                dp[i] = max(dp[i], dp[j] + 1)

    print(max(dp))


if __name__ == "__main__":
    solve()