Here is the Python code for the given problem:

def shortest_common_supersequence(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    dp = [[0 for _ in range(len2+1)] for _ in range(len1+1)]

    for i in range(len1+1):
        for j in range(len2+1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[len1][len2]

def main():
    str1 = input()
    str2 = input()
    print(shortest_common_supersequence(str1, str2))

if __name__ == "__main__":
    main()

This program uses a dynamic programming approach to solve the problem. The `dp` table `dp[i][j]` represents the length of the shortest common supersequence for the first `i` characters of `str1` and the first `j` characters of `str2`.

The base cases are `dp[0][j] = j` and `dp[i][0] = i`, where `i` and `j` are the lengths of the two strings.

The main case is when the characters at the current positions in both strings are the same. In this case, the length of the shortest common supersequence is one more than the lengths of the remaining substrings.

If the characters are different, the length of the shortest common supersequence is the maximum of the lengths of the two remaining substrings.