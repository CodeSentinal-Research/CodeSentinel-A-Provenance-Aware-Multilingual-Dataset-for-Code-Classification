import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    keys = list(map(int, input_data[idx:idx+n])); idx += n
    freqs = list(map(int, input_data[idx:idx+n]))
    
    # Optimal BST DP
    # dp[i][j] = min cost for keys i..j
    dp = [[0]*n for _ in range(n)]
    
    for length in range(1, n+1):
        for i in range(n-length+1):
            j = i + length - 1
            dp[i][j] = float('inf')
            sum_freq = sum(freqs[i:j+1])
            for r in range(i, j+1):
                cost = (dp[i][r-1] if r > i else 0) + (dp[r+1][j] if r < j else 0) + sum_freq
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    
    print(dp[0][n-1])

solve()

