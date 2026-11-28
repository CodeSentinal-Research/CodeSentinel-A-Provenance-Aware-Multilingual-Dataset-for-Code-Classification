Sure, here is a Python solution for the problem. The solution uses Dynamic Programming.

def longest_common_subsequence(s1, s2):
    len1 = len(s1)
    len2 = len(s2)

    dp = [[0 for _ in range(len2+1)] for _ in range(len1+1)]

    for i in range(len1+1):
        for j in range(len2+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[len1][len2]

if __name__ == '__main__':
    s1 = input('Enter the first string: ')
    s2 = input('Enter the second string: ')
    print('Length of Longest Common Subsequence: ', longest_common_subsequence(s1, s2))

This program first initializes a 2D array (dp) with dimensions equal to the lengths of the two strings plus 1. Then it fills this array in a bottom-up manner. It does this by checking if the current characters in the strings are equal, if they are, it adds 1 to the previous character in the longest common subsequence, otherwise it takes the maximum of the two previous characters. Finally, it returns the last value in the dp[][].

In the main function, it takes two strings as input and prints out the length of the longest common subsequence of these two strings.