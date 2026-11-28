# problem title : Shortest Common Supersequence Length
# Solve the stated task using standard input and standard output.
def shortest_common_supersequence_len(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    lcs = dp[m][n]
    return m + n - lcs

if __name__ == '__main__':
    s1 = input().strip()
    s2 = input().strip()
    print(shortest_common_supersequence_len(s1, s2))
