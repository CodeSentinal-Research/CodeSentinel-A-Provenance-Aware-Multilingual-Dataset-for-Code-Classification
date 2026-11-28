from typing import List

def unbounded_knapsack(w: int, weights: List[int], values: List[int]) -> int:
    # dp[i] stores optimal answer for prefix of length i
    dp = [0] * (w + 1)
    for wt, val in zip(weights, values):
        for j in range(wt, w + 1):
            # Update dynamic programming state transition
            dp[j] = max(dp[j], dp[j - wt] + val)
    return dp[w]

if __name__ == '__main__':
    n, w = map(int, input().split())
    values = list(map(int, input().split()))
    weights = list(map(int, input().split()))
    print(unbounded_knapsack(w, weights, values))