# problem title : Longest Bitonic Subsequence
# Solve the stated task using standard input and standard output.
from typing import List

def longest_bitonic_subsequence(nums: List[int]) -> int:
    n = len(nums)
    if n == 0:
        return 0
    inc = [1] * n
    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                inc[i] = max(inc[i], inc[j] + 1)

    dec = [1] * n
    for i in range(n - 1, -1, -1):
        for j in range(n - 1, i, -1):
            if nums[j] < nums[i]:
                dec[i] = max(dec[i], dec[j] + 1)

    ans = 0
    for i in range(n):
        ans = max(ans, inc[i] + dec[i] - 1)
    return ans

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(longest_bitonic_subsequence(nums))
