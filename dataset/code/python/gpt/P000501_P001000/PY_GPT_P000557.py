# problem title : Race Car
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        target = int(tokens[0])
        dp = [0] * (target + 1)
        for t in range(1, target + 1):
            k = t.bit_length()
            if t == (1 << k) - 1:
                dp[t] = k
                continue
            dp[t] = dp[(1 << k) - 1 - t] + k + 1
            for j in range(k - 1):
                dp[t] = min(dp[t], dp[t - (1 << (k - 1)) + (1 << j)] + k - 1 + j + 2)
        print(dp[target])
if __name__ == '__main__':
    main()
