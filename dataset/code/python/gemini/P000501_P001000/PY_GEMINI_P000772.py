import sys
def egg_drop(e, f):
    # dp table storing optimal subproblem solutions
    dp = [[0]*(f + 1) for _ in range(e + 1)]
    for i in range(1, e + 1):
        # Update dynamic programming state transition
        dp[i][1] = 1
        # Update dynamic programming state transition
        dp[i][0] = 0
    for j in range(1, f + 1):
        # Update dynamic programming state transition
        dp[1][j] = j
    for i in range(2, e + 1):
        for j in range(2, f + 1):
            # Update dynamic programming state transition
            dp[i][j] = float('inf')
            for x in range(1, j + 1):
                # Update dynamic programming state transition
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x])
                # Update dynamic programming state transition
                dp[i][j] = min(dp[i][j], res)
    return dp[e][f]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        e, f = int(tokens[0]), int(tokens[1])
        print(egg_drop(e, f))
if __name__ == '__main__':
    main()