Here is the Python code with a main function and input handling:

def find_distinct_subsequences(s, t):
    m, n = len(s), len(t)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = 1
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[m][n]

if __name__ == "__main__":
    s = input()
    t = input()
    print(find_distinct_subsequences(s, t))

This code defines a function `find_distinct_subsequences` that takes two strings `s` and `t` as input. It uses dynamic programming to compute the number of distinct subsequences of `s` that equal `t`. The main function reads the strings `s` and `t` from the standard input, calls `find_distinct_subsequences` with these strings, and prints the result.