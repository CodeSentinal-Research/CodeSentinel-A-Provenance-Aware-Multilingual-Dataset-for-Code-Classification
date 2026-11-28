def maxValue(coins):
    N = len(coins)
    if N == 1:
        return coins[0]

    dp = [0] * N
    dp2 = [0] * N
    dp[0] = coins[0]
    dp2[0] = coins[0]

    for i in range(1, N):
        dp[i] = max(dp[i-1], coins[i] + dp2[i-1])
        dp2[i] = max(dp2[i-1], coins[i] + dp[i-1])

    return max(dp[-1], dp2[-1])

def main():
    N = int(input().strip())
    coins = list(map(int, input().strip().split()))
    print(maxValue(coins))

if __name__ == "__main__":
    main()