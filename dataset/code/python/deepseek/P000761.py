Here is the Python code:

def countDistinctSubsequences(s, t):
    n = len(s)
    m = len(t)
    
    dp = [[0]*(m+1) for _ in range(n+1)]

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, m+1):
            if s[i-1] == t[j-1]:
                dp[i][j] = 2 + dp[i-1][j-1]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][m]

s = "abc"
t = "acdbc"
print(countDistinctSubsequences(s, t))

This code will create a 2D table dp where dp[i][j] stores the number of distinct subsequences of s[0:i] that equals to t[0:j]. It uses a bottom-up approach to fill up the table.