def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    for num in nums:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]
    return dp[target]

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))[:N]
    print('YES' if canPartition(nums) else 'NO')

if __name__ == "__main__":
    main()