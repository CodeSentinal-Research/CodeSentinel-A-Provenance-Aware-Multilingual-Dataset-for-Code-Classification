Here is the Python code for the problem:

def min_delete_sum(A, B):
    m, n = len(A), len(B)
    dp = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif A[i-1] == B[j-1]:
                dp[i][j] = dp[i-1][j-1] + ord(A[i-1])
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    ans = dp[m][n]
    idx = m
    j = n
    while idx > 0 and j > 0:
        if A[idx-1] != B[j-1]:
            if dp[idx][j] >= dp[idx-1][j]:
                ans += ord(A[idx-1])
                idx -= 1
            else:
                ans += ord(B[j-1])
                j -= 1
        else:
            idx -= 1
            j -= 1

    while idx > 0:
        ans += ord(A[idx-1])
        idx -= 1

    while j > 0:
        ans += ord(B[j-1])
        j -= 1

    return ans


def main():
    A = input().strip()
    B = input().strip()
    print(min_delete_sum(A, B))


if __name__ == "__main__":
    main()

In this code, we use a dynamic programming (DP) approach to solve the problem. We create a 2D DP table where `dp[i][j]` represents the minimum delete sum for the strings `A[0...i]` and `B[0...j]`.

We initialize the DP table with zeros and fill it up in a bottom-up manner. The minimum delete sum for two strings of lengths `i` and `j` is either the delete sum of the two strings without considering characters (`A[0...i]` and `B[0...j]`), or the delete sum of the two strings with one character removed from `A[0...i]` and `B[0...j]`.

Finally, we trace back from the DP table to find the characters that need to be deleted. We first check if the characters at the current indices in both strings are the same, if they are, we add their ASCII value to the sum and move to the next characters in both strings. If they are not the same, we add the ASCII value of the greater string's character to the sum and move to the next character in that string.

This process is repeated until we have processed all characters in both strings. Finally, we return the sum of ASCII values of the remaining characters in either string.