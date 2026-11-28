Sure, here's a Python solution that uses the concept of dynamic programming to solve the problem. 

def max_sum_without_adjacent(nums):
    if not nums:
        return 0

    if len(nums) <= 1:
        return max(nums)

    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    for i in range(2, len(nums)):
        dp[i] = max(dp[i-1], dp[i-2] + nums[i])

    return dp[-1]

def main():
    nums = [int(num) for num in input().split()]
    N = nums[0]
    nums = nums[1:]

    print(max_sum_without_adjacent(nums))

if __name__ == "__main__":
    main()

This code reads the number of nodes (`N`), and the node values from the input. The `max_sum_without_adjacent` function calculates the maximum sum without selecting both a node and its direct child. The `main` function handles the input and output.

Please note that you need to provide the node values as input in the format `N num1 num2 ... numN`, where `N` is the number of nodes, `num1`, `num2`, ..., `numN` are the values of the nodes.