import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    heights = list(map(int, input_data[1:1+n]))
    
    dp = [0] * n
    for i in range(1, n):
        dp[i] = dp[i-1] + abs(heights[i] - heights[i-1])
        if i > 1:
            dp[i] = min(dp[i], dp[i-2] + abs(heights[i] - heights[i-2]))
            
    print(dp[n-1])

if __name__ == "__main__":
    solve()

