import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = 1
        
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1] if length > 2 else 1
            else:
                dp[i][j] = float('inf')
                
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j])
                
    print(dp[0][n-1])

if __name__ == "__main__":
    solve()

