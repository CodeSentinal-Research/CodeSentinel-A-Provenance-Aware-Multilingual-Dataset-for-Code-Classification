def min_window_subsequence(s, t):
    dp = [[0] * (len(s) + 1) for _ in range(len(t) + 1)]

    for i in range(len(s) + 1):
        dp[0][i] = 0
    for j in range(len(t) + 1):
        dp[j][0] = 0

    for i in range(1, len(s) + 1):
        for j in range(1, len(t) + 1):
            if s[i - 1] == t[j - 1]:
                dp[j][i] = dp[j - 1][i - 1] + 1
            else:
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i])

    i, j = len(t), len(s)
    while i > 0 and j > 0:
        if s[j - 1] == t[i - 1]:
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

    if dp[len(t)][len(s)] == 0:
        return ''

    return s[j:min(len(s), j + dp[len(t)][len(s)])

def main():
    s = input().strip()
    t = input().strip()
    print(min_window_subsequence(s, t))

if __name__ == "__main__":
    main()