Here is the Python code that can solve the problem:

def canPartitionKSubsets(nums, k):
    n = len(nums)
    total = sum(nums)
    if total % k != 0:
        return False
    target = total // k
    used = [False] * n
    memo = {}
    def dfs(index, k, curr_sum, curr):
        if k == 0:
            return True
        if (index, k, curr_sum) in memo:
            return memo[(index, k, curr_sum)]
        for i in range(index, n):
            if used[i] or (curr_sum + nums[i]) > target:
                continue
            used[i] = True
            if dfs(i + 1, k - (curr + 1), curr_sum + nums[i], curr + 1):
                return True
            used[i] = False
        return False
    return dfs(0, k, 0, 0)

This code uses a depth-first search (DFS) strategy to check all possible subsets. For each subset, it uses a memoization table to avoid redundant computations. The function `canPartitionKSubsets` is the main function that calls `dfs`.

The input handling part can be done as follows:

def main():
    nums = list(map(int, input("Enter the numbers separated by space: ").strip().split()))
    k = int(input("Enter the number of subsets: "))
    print(canPartitionKSubsets(nums, k))

if __name__ == "__main__":
    main()

This code will take the user input for the numbers and the number of subsets, and print the result of the `canPartitionKSubsets` function.