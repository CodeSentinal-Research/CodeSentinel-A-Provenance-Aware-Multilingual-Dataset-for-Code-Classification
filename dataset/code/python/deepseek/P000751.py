Here is the Python code for the given problem:

def count_subsequences(nums, target):
    n = len(nums)
    dp = [[0] * (target + 1) for _ in range(n + 1)]
    
    for i in range(n + 1):
        dp[i][0] = 1
    
    for i in range(1, n + 1):
        for j in range(1, target + 1):
            if nums[i - 1] <= j:
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]
    
    return dp[n][target]

def main():
    n = int(input("Enter the length of the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    target = int(input("Enter the target sum: "))
    print(count_subsequences(nums, target))

if __name__ == "__main__":
    main()

This Python code defines a function `count_subsequences` that uses dynamic programming to count all subsequences of an array whose sum equals a target. The function first initializes a 2D array `dp` with the size of `n + 1` by `target + 1`. Then, it fills up the 2D array based on the problem's rules. The last line of the function returns the count of all subsequences whose sum equals `target`.

The `main` function reads the input, calls the `count_subsequences` function with the given inputs, and prints the result.