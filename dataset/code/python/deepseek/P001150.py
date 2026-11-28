Here is the Python code for Longest Palindromic Subsequence.

def longest_palindromic_subsequence(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]

    for i in range(n - 1, -1, -1):
        dp[i][i] = 1
        for j in range(i + 1, n):
            if s[i] == s[j]:
                dp[i][j] = 2 + dp[i + 1][j - 1]
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

    return dp[0][n - 1]

s = input()
print(longest_palindromic_subsequence(s))
This code uses dynamic programming to solve the problem. The main idea is to use a 2D array dp where dp[i][j] represents the length of the longest palindromic subsequence of the substring s[i..j]. The base case is dp[i][i] = 1, where i is the index of the starting and ending character of the string. Then for every substring (i, j), if the starting character and ending character of the substring match, then dp[i][j] is 2 + dp[i + 1][j - 1]. If they don't match, then dp[i][j] is the maximum of dp[i + 1][j] and dp[i][j - 1].

Please note that the time complexity of this solution is O(n^2) due to the 2D dynamic programming table. The space complexity is also O(n^2).