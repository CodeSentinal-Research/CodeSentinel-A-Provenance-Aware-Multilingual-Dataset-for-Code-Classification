import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    heights = list(map(int, input_data[idx:idx+n]))
    
    dp = [float('inf')] * n
    dp[0] = 0
    
    for i in range(1, n):
        for j in range(1, min(i, k) + 1):
            dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]))
            
    print(dp[n-1])

if __name__ == "__main__":
    solve()

