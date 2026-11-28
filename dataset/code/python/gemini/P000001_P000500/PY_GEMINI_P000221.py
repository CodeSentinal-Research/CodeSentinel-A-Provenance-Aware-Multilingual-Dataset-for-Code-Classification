from typing import List

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda p: p[1])
        cur_end = float('-inf')
        chain = 0

        for s, e in pairs:
            if s > cur_end:
                chain += 1
                cur_end = e

        return chain