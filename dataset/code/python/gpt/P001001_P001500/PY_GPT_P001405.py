# problem title : Count Nice Pairs in an Array
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(n: int) -> int:
            return int(str(n)[::-1])

        MOD = 10**9 + 7
        count = Counter(x - rev(x) for x in nums)
        return sum(cnt * (cnt - 1) // 2 for cnt in count.values()) % MOD
