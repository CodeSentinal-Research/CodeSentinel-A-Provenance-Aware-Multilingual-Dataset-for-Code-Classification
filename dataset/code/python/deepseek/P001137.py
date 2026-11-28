def coin_change():
    N = int(input().strip())
    coins = list(map(int, input().strip().split()))
    amount = int(input().strip())

    if N > amount:
        print(-1)
    else:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] = min(dp[i], dp[i - coin] + 1)

        print(dp[amount] if dp[amount] != float('inf') else -1)

if __name__ == "__main__":
    coin_change()