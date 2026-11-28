Here is the Python code for the problem. This code uses dynamic programming to solve the problem. The main idea is to use a dp table to store the length of the longest increasing subsequence ending at each position. The time complexity is O(n^2), where n is the length of the input array.

def solve(n, arr):
    dp = [1] * n
    for i in range(1, n):
        for j in range(i):
            if arr[i] > arr[j] and dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
    max_len = max(dp)
    count = sum(x == max_len for x in dp)
    return count

n = int(input().strip())
arr = list(map(int, input().strip().split()))
print(solve(n, arr))

This code first reads the length of the array and the array itself. Then it calls the solve function to find the number of longest increasing subsequences. The solve function initializes a dp table with ones and then iterates over the array, updating the dp table whenever it finds a longer increasing subsequence ending at the current position. Finally, it finds the maximum length of the longest increasing subsequence and counts the number of subsequences of this length. The result is printed to the console.