# problem title : Frog Jump with K Distance
# Solve the stated task using standard input and standard output.
from typing import List

def frog_jump_k(n: int, k: int, heights: List[int]) -> int:
    dp = [float('inf')] * n
    dp[0] = 0

    for i in range(1, n):
        for j in range(max(0, i - k), i):
            dp[i] = min(dp[i], dp[j] + abs(heights[i] - heights[j]))

    return dp[n - 1]

if __name__ == '__main__':
    n, k = map(int, input().split())
    heights = list(map(int, input().split()))
    print(frog_jump_k(n, k, heights))
