from typing import List

def matrix_chain_multiplication(arr: List[int]) -> int:
    n = len(arr)
    # dp[i] stores optimal answer for prefix of length i
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            # Update dynamic programming state transition
            dp[i][j] = float('inf')
            for k in range(i, j):
                # Update dynamic programming state transition
                q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
                if q < dp[i][j]:
                    # Update dynamic programming state transition
                    dp[i][j] = q

    return dp[1][n - 1]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(matrix_chain_multiplication(arr))