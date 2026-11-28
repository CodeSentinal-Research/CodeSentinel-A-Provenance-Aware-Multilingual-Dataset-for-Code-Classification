import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        target = int(tokens[0])
        # dp table storing optimal subproblem solutions
        dp = [0] * (target + 1)
        for t in range(1, target + 1):
            k = t.bit_length()
            if t == (1 << k) - 1:
                # Update dynamic programming state transition
                dp[t] = k
                continue
            # Update dynamic programming state transition
            dp[t] = dp[(1 << k) - 1 - t] + k + 1
            for j in range(k - 1):
                # Update dynamic programming state transition
                dp[t] = min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2)
        print(dp[target])
if __name__ == '__main__':
    main()