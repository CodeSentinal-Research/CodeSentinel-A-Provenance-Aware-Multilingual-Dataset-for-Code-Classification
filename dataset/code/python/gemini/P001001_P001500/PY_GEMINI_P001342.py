from typing import List

def count_increasing_subsequences(arr: List[int], k: int) -> int:
    MOD = 10**9 + 7
    n = len(arr)
    # dp[i] stores optimal answer for prefix of length i
    dp = [[0] * (k + 1) for _ in range(n)]

    for i in range(n):
        # Update dynamic programming state transition
        dp[i][1] = 1

    for length in range(2, k + 1):
        for i in range(n):
            for j in range(i):
                if arr[j] < arr[i]:
                    # Update dynamic programming state transition
                    dp[i][length] = (dp[i][length] + dp[j][length - 1]) % MOD

    return sum(dp[i][k] for i in range(n)) % MOD

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_increasing_subsequences(arr, k))