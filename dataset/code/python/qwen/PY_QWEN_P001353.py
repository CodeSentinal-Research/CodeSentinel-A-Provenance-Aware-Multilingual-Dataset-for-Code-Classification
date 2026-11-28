import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    s = input_data[0]
    k = int(input_data[1])
    n = len(s)
    MOD = 10**9 + 7
    
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(1, n + 1):
        for j in range(1, min(i, 10) + 1): # Max length of number is 10 for 10^9
            if s[i-j] == '0':
                continue
            num = int(s[i-j:i])
            if 1 <= num <= k:
                dp[i] = (dp[i] + dp[i-j]) % MOD
                
    print(dp[n])

if __name__ == "__main__":
    solve()

