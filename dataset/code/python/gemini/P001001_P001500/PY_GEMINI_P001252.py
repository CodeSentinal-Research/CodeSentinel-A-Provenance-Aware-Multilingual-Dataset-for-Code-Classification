from typing import List

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        cur = -float('inf')
        ans = 0
        for x, y in pairs:
            if cur < x:
                cur = y
                ans += 1
        return ans