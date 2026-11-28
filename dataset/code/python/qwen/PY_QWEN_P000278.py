s = input().strip()
n = len(s)
if n == 0:
    print("")
else:
    dp = [[False] * n for _ in range(n)]
    start, max_len = 0, 1
    for i in range(n):
        dp[i][i] = True
    for i in range(n - 1):
        if s[i] == s[i+1]:
            dp[i][i+1] = True
            start = i
            max_len = 2
    for k in range(3, n + 1):
        for i in range(n - k + 1):
            j = i + k - 1
            if dp[i+1][j-1] and s[i] == s[j]:
                dp[i][j] = True
                if k > max_len:
                    max_len = k
                    start = i
    print(s[start:start+max_len])
