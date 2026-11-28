Here is the Python code:

def edit_distance(str1, str2):
    m = len(str1)
    n = len(str2)

    dp = [[0 for x in range(n + 1)] for x in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

    print(dp[m][n])


if __name__ == "__main__":
    str1 = input("Enter the first string: ")
    str2 = input("Enter the second string: ")
    edit_distance(str1, str2)

This code will print the minimum edit distance between the two strings. The edit distance is the number of operations (insertions, deletions, and substitutions) required to change one string into the other. The function `edit_distance` calculates the edit distance using dynamic programming. The `if __name__ == "__main__"` block is used for input handling. It reads the two strings from the user and calls the `edit_distance` function.