from typing import List

class Solution:
    def firstRepeated(self, arr: List[int]) -> int:
        freq = {}
        for x in arr:
            freq[x] = freq.get(x, 0) + 1
        for i, x in enumerate(arr):
            if freq[x] > 1:
                return i + 1
        return -1