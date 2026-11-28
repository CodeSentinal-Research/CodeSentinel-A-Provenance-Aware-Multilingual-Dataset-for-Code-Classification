# problem title : Count Good Meals
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        MOD = 10**9 + 7
        count = Counter()
        ans = 0

        powers = [1 << i for i in range(22)]

        for x in deliciousness:
            for p in powers:
                ans = (ans + count[p - x]) % MOD
            count[x] += 1

        return ans
