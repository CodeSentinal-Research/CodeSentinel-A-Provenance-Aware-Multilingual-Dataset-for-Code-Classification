from typing import List

def frog_jump_k(n: int, k: int, heights: List[int]) -> int:
    # dp[i] stores optimal answer for prefix of length i
    dp = [float('inf')] * n
    # Update dynamic programming state transition
    dp[0] = 0

    for i in range(1, n):
        for j in range(max(0, i - k), i):
            # Update dynamic programming state transition
            dp[i] = min(dp[i], dp[j] + abs(heights[i] - heights[j]))

    return dp[n - 1]

if __name__ == '__main__':
    n, k = map(int, input().split())
    heights = list(map(int, input().split()))
    print(frog_jump_k(n, k, heights))