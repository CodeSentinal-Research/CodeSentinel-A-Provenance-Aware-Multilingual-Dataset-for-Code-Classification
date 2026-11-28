from typing import List

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        """Sorts the input array into ordered sequence."""
        stack = []
        for x in arr:
            cur_max = x
            # Maintain monotonic stack property by popping smaller elements
            while stack and stack[-1] > x:
                cur_max = max(cur_max, stack.pop())
            stack.append(cur_max)
        return len(stack)