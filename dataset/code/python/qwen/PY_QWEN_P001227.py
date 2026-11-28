import sys

def solve():
    n = int(sys.stdin.readline())
    
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 0
    
    for i in range(2, n + 1):
        dp[i] = (i - 1) * (dp[i-1] + dp[i-2])
        
    print(dp[n])

if __name__ == "__main__":
    solve()

