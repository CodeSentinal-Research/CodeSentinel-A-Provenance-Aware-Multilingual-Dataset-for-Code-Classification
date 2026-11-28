Sure, here is a Python code snippet that solves the Subset Sum Problem:

def subset_sum(arr, n, sum):
    dp = [[False for i in range(sum + 1)] for i in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = True
    for i in range(1, sum + 1):
        dp[0][i] = False
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            if j >= arr[i - 1]:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][sum]

def main():
    n, s = map(int, input().split())
    arr = list(map(int, input().split()))
    if subset_sum(arr, n, s):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()

In this code, we first define a function `subset_sum` that computes the subset sum problem. This function uses a dynamic programming approach to solve the problem. The `dp` table is a 2D array where `dp[i][j]` is True if there exists a subset whose sum is j, and False otherwise.

Then in the `main` function, we read the size of the array `n` and the target sum `s`, and the array itself. We call the `subset_sum` function with these parameters and print 'YES' if the function returns True, otherwise we print 'NO'.