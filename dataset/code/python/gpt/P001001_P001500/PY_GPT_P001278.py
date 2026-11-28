# problem title : Max Chunks to Make Sorted II
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        for x in arr:
            cur_max = x
            while stack and stack[-1] > x:
                cur_max = max(cur_max, stack.pop())
            stack.append(cur_max)
        return len(stack)
