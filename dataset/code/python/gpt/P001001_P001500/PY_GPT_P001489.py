# problem title : Number of Subsequences That Satisfy the Given Sum Condition
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        MOD = 10**9 + 7
        n = len(nums)
        power = [1] * n
        for i in range(1, n):
            power[i] = (power[i - 1] * 2) % MOD

        l, r = 0, n - 1
        ans = 0
        while l <= r:
            if nums[l] + nums[r] <= target:
                ans = (ans + power[r - l]) % MOD
                l += 1
            else:
                r -= 1

        return ans
