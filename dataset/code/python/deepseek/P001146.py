Here is the Python code with the main function and input handling.

def lcs(X, Y):
    m = len(X)
    n = len(Y)

    dp = [[0 for i in range(n+1)] for i in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif X[i-1] == Y[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]


def main():
    X = input().strip()
    Y = input().strip()

    print(lcs(X, Y))


if __name__ == "__main__":
    main()

This code takes two strings as input and uses a 2D array dp[][] to store the longest common subsequence till each point in X[] and Y[]. It then returns the last element of dp[][]. The main function is where the input handling and output is done.