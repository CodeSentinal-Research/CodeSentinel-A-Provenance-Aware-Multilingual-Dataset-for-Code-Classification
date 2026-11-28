# problem title : Max Chunks to Make Sorted
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        cur_max = 0
        chunks = 0
        for i, x in enumerate(arr):
            cur_max = max(cur_max, x)
            if cur_max == i:
                chunks += 1
        return chunks
