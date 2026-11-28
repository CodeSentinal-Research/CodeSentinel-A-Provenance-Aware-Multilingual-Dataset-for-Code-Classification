import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    nums = list(map(int, d[1:n+1]))
    dp = [0] * n
    for i in range(n-1, -1, -1):
        dp[i] = nums[i]
        for j in range(i+1, n):
            dp[j] = max(nums[i] - dp[j], nums[j] - dp[j-1])
    print("true" if dp[n-1] >= 0 else "false")
solve()
