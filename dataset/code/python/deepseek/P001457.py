Here is a Python solution using dynamic programming:

def find_common_substring(s1, s2):
    m, n = len(s1), len(s2)
    dp = [[0] * (n+1) for _ in range(m+1)]
    max_length, max_end = 0, 0
    for i in range(1, m+1):
        for j in range(1, n+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
                if dp[i][j] > max_length:
                    max_length = dp[i][j]
                    max_end = i
            else:
                dp[i][j] = 0
    return max_length

def main():
    s1 = input()
    s2 = input()
    print(find_common_substring(s1, s2))

if __name__ == "__main__":
    main()

In this code, we use a 2D dynamic programming table `dp` to store the length of the longest common substring ending at the current position in both strings. We iterate through each character in both strings, and if the characters are the same, we update the table by adding 1 to the previous cell, otherwise, we set it to 0. The longest common substring is the maximum value in the table, and its length is the `max_length` variable.