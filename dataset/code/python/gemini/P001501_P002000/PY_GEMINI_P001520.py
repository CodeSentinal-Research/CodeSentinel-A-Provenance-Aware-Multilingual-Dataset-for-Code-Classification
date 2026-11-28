from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        """Sorts the input array into ordered sequence."""
        max_seen = 0
        chunks = 0
        for i, x in enumerate(arr):
            max_seen = max(max_seen, x)
            if max_seen == i:
                chunks += 1
        return chunks