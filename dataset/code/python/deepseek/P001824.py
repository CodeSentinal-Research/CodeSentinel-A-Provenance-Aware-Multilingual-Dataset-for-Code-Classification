def solve(seq):
    n = len(seq)
    dp = [0] * (n+1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = 0
        for j in range(i):
            dp[i] += dp[j] * dp[i-j-1]
    return dp[n]

def main():
    n = int(input().strip())
    seq = list(map(int, input().strip().split()))
    rule = int(input().strip())
    if rule == 0:
        print(solve(seq))
    else:
        print("The rule is not valid.")

if __name__ == '__main__':
    main()