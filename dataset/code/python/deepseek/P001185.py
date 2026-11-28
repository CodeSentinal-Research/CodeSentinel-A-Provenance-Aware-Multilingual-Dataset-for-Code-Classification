def delete_and_earn(N, nums):
    from collections import Counter
    count = Counter(nums)
    nums = sorted(list(set(nums)))
    dp = [0] * (N + 1)
    for i in range(len(nums)):
        if i > 1:
            dp[i] = max(dp[i-1], dp[i-2] + nums[i] * count[nums[i]])
        else:
            dp[i] = max(dp[i-1], nums[i] * count[nums[i]])
    return dp[-1]

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(delete_and_earn(N, nums))

main()