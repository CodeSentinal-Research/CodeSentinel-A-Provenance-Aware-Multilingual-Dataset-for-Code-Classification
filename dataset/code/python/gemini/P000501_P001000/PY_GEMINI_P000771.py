import sys
def optimal_bst(keys, freq):
    n = len(keys)
    # dp table storing optimal subproblem solutions
    dp = [[0]*n for _ in range(n)]
    sum_freq = [[0]*n for _ in range(n)]
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += freq[j]
            sum_freq[i][j] = s
    for i in range(n): dp[i][i] = freq[i]
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            min_c = float('inf')
            for r in range(i, j + 1):
                # Update dynamic programming state transition
                c = (dp[i][r - 1] if r > i else 0) + (dp[r + 1][j] if r < j else 0)
                min_c = min(min_c, c)
            # Update dynamic programming state transition
            dp[i][j] = min_c + sum_freq[i][j]
    return dp[0][n - 1]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        keys = list(map(int, tokens[1:1+n]))
        freq = list(map(int, tokens[1+n:1+2*n]))
        print(optimal_bst(keys, freq))
if __name__ == '__main__':
    main()