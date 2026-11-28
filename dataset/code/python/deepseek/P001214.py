Here is the Python code:

def strange_printer(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    min_step = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 1
        min_step[i][i] = i
    for length in range(1, n):
        for i in range(n - length):
            j = i + length
            dp[i][j] = dp[i+1][j] + 1
            min_step[i][j] = min_step[i+1][j] + 1
            for k in range(i+1, j+1):
                if s[i] == s[k]:
                    if dp[i][j] > dp[i][k-1] + dp[k+1][j] + 1:
                        dp[i][j] = dp[i][k-1] + dp[k+1][j] + 1
                        min_step[i][j] = min_step[i][k-1] + min_step[k+1][j] + 1
                else:
                    if min_step[i][j] > min_step[i][k-1] + min_step[k+1][j] + 1:
                        min_step[i][j] = min_step[i][k-1] + min_step[k+1][j] + 1
    return dp[0][n-1]

def main():
    s = input().strip()
    print(strange_printer(s))

if __name__ == "__main__":
    main()

This code implements a dynamic programming approach to solve the problem. It first calculates the minimum steps needed to print the string. Then it uses these values to calculate the minimum steps needed to print the entire string.

The `strange_printer` function returns the minimum number of turns needed to print the given string.

The `main` function reads the input string, calls the `strange_printer` function with the input string, and prints the returned value.

Please note that this solution assumes that the printer can print a character again once it has been printed. If this assumption is not true, the solution will need to be adjusted accordingly.