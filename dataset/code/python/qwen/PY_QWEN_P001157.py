import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    prices = list(map(int, input_data[1:1+n]))
    
    dp = [0] * (n + 1)
    
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            dp[i] = max(dp[i], prices[j-1] + dp[i-j])
            
    print(dp[n])

if __name__ == "__main__":
    solve()

