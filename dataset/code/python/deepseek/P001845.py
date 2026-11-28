def solve(m, sequences):
    for sequence in sequences:
        n = sequence[0]
        keys = list(map(int, sequence[1:]))

        keys.sort()

        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]

        print(dp[n])

m = int(input().strip())
sequences = []
for _ in range(m):
    n = int(input().strip())
    sequence = list(map(int, input().strip().split()))
    sequences.append((n, sequence))

solve(m, sequences)