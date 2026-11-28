import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    nums = sorted(list(map(int, d[1:n+1])))
    dp = [[x] for x in nums]
    max_subset = []
    for i in range(n):
        for j in range(i):
            if nums[i] % nums[j] == 0:
                if len(dp[j]) + 1 > len(dp[i]):
                    dp[i] = dp[j] + [nums[i]]
        if len(dp[i]) > len(max_subset):
            max_subset = dp[i]
    print(" ".join(map(str, max_subset)))
solve()
