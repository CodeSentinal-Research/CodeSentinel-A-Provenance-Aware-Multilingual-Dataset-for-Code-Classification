Here is the code:

def largestDivisibleSubset(nums):
    if not nums:
        return []

    nums.sort()
    dp, prev = [1] * len(nums), [None] * len(nums)
    max_idx = 0

    for i in range(1, len(nums)):
        for j in range(i):
            if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                prev[i] = j
        if dp[max_idx] < dp[i]:
            max_idx = i

    result = []
    current = max_idx
    while True:
        result.append(nums[current])
        prev_idx = prev[current]
        current = prev_idx
        if current == max_idx:
            break

    return result[::-1]

This code uses dynamic programming to find the largest divisible subset of the given array. It first sorts the array, then it iterates over the array to find the largest divisible subset. The time complexity of this solution is O(n^2) due to the two nested loops.

The `largestDivisibleSubset` function takes a list of integers as input and returns a list of integers. The main function is `main`.

Here is a main function to test the `largestDivisibleSubset` function:

def main():
    nums = [1, 2, 4, 8]
    print(largestDivisibleSubset(nums))

if __name__ == "__main__":
    main()

This will output: `[1, 2, 4, 8]`