import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    nums = list(map(int, input_data[1:1+n]))
    
    # dp[i][j] = max score difference current player can achieve over opponent for subarray i..j
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = nums[i]
        
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
            
    print("YES" if dp[0][n-1] >= 0 else "NO")

if __name__ == "__main__":
    solve()

