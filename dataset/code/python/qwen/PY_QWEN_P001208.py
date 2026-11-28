import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    piles = list(map(int, input_data[1:1+n]))
    
    suffix_sum = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suffix_sum[i] = suffix_sum[i+1] + piles[i]
        
    # dp[i][m] = max stones Alice can get starting from index i with parameter m
    # Using memoization
    from functools import lru_cache
    
    @lru_cache(None)
    def dp(i, m):
        if i >= n:
            return 0
        if i + 2 * m >= n:
            return suffix_sum[i]
            
        min_opponent = float('inf')
        for x in range(1, 2 * m + 1):
            min_opponent = min(min_opponent, dp(i + x, max(m, x)))
            
        return suffix_sum[i] - min_opponent
        
    print(dp(0, 1))

if __name__ == "__main__":
    solve()

