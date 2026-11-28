from typing import List

MOD = 10**9 + 7

def eval_linear_recurrence(coeffs: List[int], init: List[int], n: int) -> int:
    k = len(coeffs)
    if n < k:
        return init[n] % MOD
    dp = list(init)
    for i in range(k, n + 1):
        val = sum(coeffs[j] * dp[i - 1 - j] for j in range(k)) % MOD
        dp.append(val)
    return dp[n]

if __name__ == '__main__':
    k, n = map(int, input().split())
    coeffs = list(map(int, input().split()))
    init = list(map(int, input().split()))
    print(eval_linear_recurrence(coeffs, init, n))