# problem title : 0/1 Knapsack
# Solve the stated task using standard input and standard output.
from typing import List

def knapsack_01(w: int, weights: List[int], values: List[int]) -> int:
    dp = [0] * (w + 1)
    for wt, val in zip(weights, values):
        for j in range(w, wt - 1, -1):
            dp[j] = max(dp[j], dp[j - wt] + val)
    return dp[w]

if __name__ == '__main__':
    n, w = map(int, input().split())
    values = list(map(int, input().split()))
    weights = list(map(int, input().split()))
    print(knapsack_01(w, weights, values))
