import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    amount = int(input_data[idx]); idx += 1
    coins = list(map(int, input_data[idx:idx+n]))
    
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for coin in coins:
        for x in range(coin, amount + 1):
            if dp[x - coin] != float('inf'):
                dp[x] = min(dp[x], dp[x - coin] + 1)
                
    print(dp[amount] if dp[amount] != float('inf') else -1)

if __name__ == "__main__":
    solve()

