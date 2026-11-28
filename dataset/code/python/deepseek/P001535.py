Here is the Python code for the problem:

def main():
    s = input().strip()
    k = int(input().strip())
    print(longest_substring(s, k))

def longest_substring(s, k):
    n = len(s)
    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if s[i] == s[j]:
                dp[i][j] = dp[i + 1][j - 1] + 2
                if dp[i][j] > k:
                    dp[i][j] = k
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
    return dp[0][n - 1]

if __name__ == "__main__":
    main()

This code uses a dynamic programming approach to solve the problem. It iterates over the string from the end to the start, and for each pair of characters, it updates the dynamic programming table based on the conditions defined in the problem. The final answer is the maximum value in the top-right corner of the table.