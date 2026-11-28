from typing import List

def optimal_strategy(arr: List[int]) -> int:
    n = len(arr)
    # dp[i] stores optimal answer for prefix of length i
    dp = [[0] * n for _ in range(n)]

    for length in range(1, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            # Update dynamic programming state transition
            x = dp[i + 2][j] if i + 2 <= j else 0
            # Update dynamic programming state transition
            y = dp[i + 1][j - 1] if i + 1 <= j - 1 else 0
            # Update dynamic programming state transition
            z = dp[i][j - 2] if i <= j - 2 else 0
            # Update dynamic programming state transition
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z))

    return dp[0][n - 1]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(optimal_strategy(arr))