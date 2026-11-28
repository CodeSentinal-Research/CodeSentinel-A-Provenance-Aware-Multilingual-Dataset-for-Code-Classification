import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    prices = list(map(int, input_data[idx:idx+n]))
    
    if k >= n // 2:
        profit = 0
        for i in range(1, n):
            if prices[i] > prices[i-1]:
                profit += prices[i] - prices[i-1]
        print(profit)
        return
        
    dp = [[0] * (k + 1) for _ in range(n)]
    
    for j in range(1, k + 1):
        max_buy = -prices[0]
        for i in range(1, n):
            dp[i][j] = max(dp[i-1][j], max_buy + prices[i])
            max_buy = max(max_buy, dp[i-1][j-1] - prices[i])
            
    print(dp[n-1][k])

if __name__ == "__main__":
    solve()

