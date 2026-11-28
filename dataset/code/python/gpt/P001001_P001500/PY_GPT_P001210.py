# problem title : Optimal Strategy for a Game
# Solve the stated task using standard input and standard output.
from typing import List

def optimal_strategy(arr: List[int]) -> int:
    n = len(arr)
    dp = [[0] * n for _ in range(n)]

    for length in range(1, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            x = dp[i + 2][j] if i + 2 <= j else 0
            y = dp[i + 1][j - 1] if i + 1 <= j - 1 else 0
            z = dp[i][j - 2] if i <= j - 2 else 0
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z))

    return dp[0][n - 1]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(optimal_strategy(arr))
