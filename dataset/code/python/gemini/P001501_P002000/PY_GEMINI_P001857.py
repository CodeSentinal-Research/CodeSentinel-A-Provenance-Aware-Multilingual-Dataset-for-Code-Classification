from collections import deque
from typing import List

class Solution:
    def canRepresentBSTLevelOrder(self, levelOrder: List[int]) -> bool:
        if not levelOrder:
            return True
        dq = deque([(float('-inf'), float('inf'))])
        idx = 0

        while dq and idx < len(levelOrder):
            low, high = dq.popleft()
            val = levelOrder[idx]
            if low < val < high:
                idx += 1
                dq.append((low, val))
                dq.append((val, high))

        return idx == len(levelOrder)