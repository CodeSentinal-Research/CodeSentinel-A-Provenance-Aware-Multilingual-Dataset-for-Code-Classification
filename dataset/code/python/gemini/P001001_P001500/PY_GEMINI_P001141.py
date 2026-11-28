from typing import List

def subset_sum(arr: List[int], target: int) -> bool:
    # dp[i] stores optimal answer for prefix of length i
    dp = [False] * (target + 1)
    # Update dynamic programming state transition
    dp[0] = True
    for x in arr:
        for j in range(target, x - 1, -1):
            # Update dynamic programming state transition
            dp[j] = dp[j] or dp[j - x]
    return dp[target]

if __name__ == '__main__':
    n, target = map(int, input().split())
    arr = list(map(int, input().split()))
    print("YES" if subset_sum(arr, target) else "NO")