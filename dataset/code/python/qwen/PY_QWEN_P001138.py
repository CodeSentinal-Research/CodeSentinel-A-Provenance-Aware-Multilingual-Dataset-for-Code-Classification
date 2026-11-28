import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    amount = int(input_data[idx]); idx += 1
    coins = list(map(int, input_data[idx:idx+n]))
    
    dp = [0] * (amount + 1)
    dp[0] = 1
    
    for coin in coins:
        for x in range(coin, amount + 1):
            dp[x] += dp[x - coin]
            
    print(dp[amount])

if __name__ == "__main__":
    solve()

