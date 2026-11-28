# problem title : Longest Common Substring Between Two Strings
# Solve the stated task using standard input and standard output.
def longest_common_substring(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    max_len = 0

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                max_len = max(max_len, dp[i][j])

    return max_len

if __name__ == '__main__':
    s1 = input().strip()
    s2 = input().strip()
    print(longest_common_substring(s1, s2))
