import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    coins = list(map(int, input_data[1:1+n]))
    
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = coins[i]
        
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = max(coins[i] + min(dp[i+2][j] if i+2 <= j else 0, dp[i+1][j-1] if i+1 <= j-1 else 0),
                           coins[j] + min(dp[i+1][j-1] if i+1 <= j-1 else 0, dp[i][j-2] if i <= j-2 else 0))
                           
    print(dp[0][n-1])

if __name__ == "__main__":
    solve()

