Here is the Python code that uses dynamic programming to solve the problem:

def match_pattern(text, pattern):
    m, n = len(text), len(pattern)
    dp = [[False] * (n + 1) for _ in range(m + 1)]
    dp[0][0] = True
    for i in range(1, m + 1):
        dp[i][0] = False
    for j in range(1, n + 1):
        dp[0][j] = dp[0][j - 1] and pattern[j - 1] == '*'
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if pattern[j - 1] == '*':
                dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
            elif pattern[j - 1] == '?' or text[i - 1] == pattern[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = dp[i - 1][j - 1] and pattern[j - 1] != '*'
    return 'YES' if dp[m][n] else 'NO'

if __name__ == '__main__':
    text = input()
    pattern = input()
    print(match_pattern(text, pattern))

This program uses a 2D array `dp` where `dp[i][j]` is `True` if the first `i` characters of `text` match the first `j` characters of `pattern`. It iterates over the `text` and `pattern`, updating `dp` based on whether the current characters in the pattern match or not.

Please note that this solution assumes that the text and pattern are 0-indexed.