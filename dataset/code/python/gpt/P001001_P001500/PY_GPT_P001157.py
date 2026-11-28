# problem title : Rod Cutting
# Solve the stated task using standard input and standard output.
from typing import List

def rod_cutting(prices: List[int], n: int) -> int:
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        max_val = 0
        for j in range(i):
            max_val = max(max_val, prices[j] + dp[i - j - 1])
        dp[i] = max_val
    return dp[n]

if __name__ == '__main__':
    n = int(input())
    prices = list(map(int, input().split()))
    print(rod_cutting(prices, n))
