Here is the Python code:

def find_max_sum():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))

    dp = [0] * n
    dp[0] = nums[0]

    for i in range(1, n):
        dp[i] = nums[i]
        for j in range(i):
            if nums[i] > nums[j] and dp[i] < dp[j] + nums[i]:
                dp[i] = dp[j] + nums[i]

    print(max(dp))

find_max_sum()

In this code, we initialize a list `dp` with size `n` and fill it with zeros. Then we iterate over the list `nums`. For each number, we check all the previous numbers. If the current number is greater than the previous numbers, and the sum of the current number and the sum of the previous numbers is greater than the current sum, we update the current sum. At the end of the iteration, we print the maximum sum from the list `dp`.