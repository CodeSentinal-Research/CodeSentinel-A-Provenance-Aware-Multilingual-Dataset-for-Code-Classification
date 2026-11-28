def minDifferencePartition(N, nums):
    def dp(n, nums, left, right):
        if n == 0:
            return 0
        if left + right == n:
            return 0
        if dp.memo[n][left] != -1 and dp.memo[n][right] != -1:
            return dp.memo[n][left]
        if left > right:
            dp.memo[n][left] = dp(n - 1, nums, left + 1, right) + abs(nums[left] - nums[right])
        else:
            dp.memo[n][left] = min(dp(n - 1, nums, left + 1, right), dp(n - 1, nums, left, right - 1))
        return dp.memo[n][left]
    
    dp.memo = [[-1] * N for _ in range(N)]
    left, right, min_diff = 0, sum(nums) - left, float('inf')
    for right in range(n):
        min_diff = min(min_diff, dp(n - 1, nums, left, right))
    return min_diff

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(minDifferencePartition(N, nums))

if __name__ == "__main__":
    main()