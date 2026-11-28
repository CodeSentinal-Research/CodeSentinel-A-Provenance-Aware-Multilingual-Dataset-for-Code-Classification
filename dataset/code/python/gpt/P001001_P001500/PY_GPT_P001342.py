# problem title : Count Increasing Subsequences of Length K
# Solve the stated task using standard input and standard output.
from typing import List

def count_increasing_subsequences(arr: List[int], k: int) -> int:
    MOD = 10**9 + 7
    n = len(arr)
    dp = [[0] * (k + 1) for _ in range(n)]

    for i in range(n):
        dp[i][1] = 1

    for length in range(2, k + 1):
        for i in range(n):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i][length] = (dp[i][length] + dp[j][length - 1]) % MOD

    return sum(dp[i][k] for i in range(n)) % MOD

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_increasing_subsequences(arr, k))
