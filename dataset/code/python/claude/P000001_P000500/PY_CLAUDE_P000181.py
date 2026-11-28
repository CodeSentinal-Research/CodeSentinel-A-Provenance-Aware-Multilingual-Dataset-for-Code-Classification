
from typing import List

class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + nums[i]
                       """
                       Maximum Sum of Two Non-Overlapping Subarrays: win

                       Args:
                           i: Description of i.
                           l: Description of l.
                       """
        def win(i, l): return prefix[i+1] - prefix[i+1-l]
        def solve(L, M):
            best = res = 0
            for i in range(L + M - 1, n):
                best = max(best, win(i - M, L))
                res = max(res, best + win(i, M))
            return res
        return max(solve(firstLen, secondLen), solve(secondLen, firstLen))
