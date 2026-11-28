import sys

def solve():
    n = int(sys.stdin.readline())
    
    # Catalan Number C_n = (2n)! / ((n+1)! * n!)
    # Or DP: C_0 = 1, C_n = sum(C_i * C_{n-1-i})
    
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(1, n + 1):
        for j in range(i):
            dp[i] += dp[j] * dp[i - 1 - j]
            
    print(dp[n])

if __name__ == "__main__":
    solve()

