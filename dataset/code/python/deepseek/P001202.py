def largestDivisibleSubset(nums):
    if not nums:
        return []

    nums.sort()
    dp, idx = [1]*len(nums), [0]*len(nums)
    max_idx = 0

    for i in range(len(nums)):
        for j in range(i):
            if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                if dp[i] > max_idx:
                    max_idx = dp[i]
                    idx[i] = j

    i = max_idx
    result = []

    while i > 0:
        result.append(nums[i])
        i = idx[i]

    return result

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))[:N]
    print(largestDivisibleSubset(nums))

if __name__ == "__main__":
    main()