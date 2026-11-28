Here is the Python code for the Edit Distance problem:

def edit_distance(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

    return dp[m][n]

if __name__ == "__main__":
    s1 = input("Enter the first string: ")
    s2 = input("Enter the second string: ")
    print("Edit distance:", edit_distance(s1, s2))

In this code, we use a dynamic programming approach to solve the problem. We create a matrix `dp` where `dp[i][j]` represents the minimum number of operations required to convert `s1[0:i]` into `s2[0:j]`. The operations are insert, delete, and replace.

The base cases are `dp[0][j] = j` and `dp[i][0] = i`, which represent the operations needed to convert an empty string into another string.

For the remaining cases, we check if the characters at current positions in both strings are same. If they are same, the minimum operations are same as before. Otherwise, we do a replacement and take minimum of the three operations.