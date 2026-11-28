from typing import List

class Solution:
    def firstNonRepeating(self, arr: List[int]) -> int:
        freq = {}
        for x in arr:
            freq[x] = freq.get(x, 0) + 1
        for x in arr:
            if freq[x] == 1:
                return x
        return 0