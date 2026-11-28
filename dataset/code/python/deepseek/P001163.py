Here's the Python code for the problem:

def isInterleave(A, B, C):
    m, n = len(A), len(B)
    dp = [[False]*(n+1) for _ in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 and j == 0:
                dp[i][j] = True
            elif i == 0:
                dp[i][j] = dp[i][j-1] and B[j-1] == C[j-1]
            elif j == 0:
                dp[i][j] = dp[i-1][j] and A[i-1] == C[i-1]
            else:
                dp[i][j] = (dp[i-1][j] and A[i-1] == C[i+j-1]) or (dp[i][j-1] and B[j-1] == C[i+j-1])
    return dp[m][n]

def main():
    A = input().strip()
    B = input().strip()
    C = input().strip()
    print("YES" if isInterleave(A, B, C) else "NO")

if __name__ == "__main__":
    main()

This code uses a dynamic programming approach to solve the problem. It first creates a 2D boolean array dp, where dp[i][j] is True if the first i characters of string A and the first j characters of string B can be interleaved to form the first i + j characters of string C.

Then, for each character in A and B, it updates dp[i][j] based on whether the last character of A and B can be interleaved to form the current character in C.

Finally, it checks if the last character of A and B can be interleaved to form the last character in C, and prints "YES" if it can, or "NO" otherwise.