# problem title : Matrix Chain Multiplication
# Solve the stated task using standard input and standard output.
from typing import List

def matrix_chain_multiplication(arr: List[int]) -> int:
    n = len(arr)
    dp = [[0] * n for _ in range(n)]

    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
                if q < dp[i][j]:
                    dp[i][j] = q

    return dp[1][n - 1]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(matrix_chain_multiplication(arr))
