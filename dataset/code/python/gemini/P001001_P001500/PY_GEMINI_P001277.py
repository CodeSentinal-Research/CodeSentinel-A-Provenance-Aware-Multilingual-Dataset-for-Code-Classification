from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        """Sorts the input array into ordered sequence."""
        cur_max = 0
        chunks = 0
        for i, x in enumerate(arr):
            cur_max = max(cur_max, x)
            if cur_max == i:
                chunks += 1
        return chunks