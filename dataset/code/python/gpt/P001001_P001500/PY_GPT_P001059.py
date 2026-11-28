# problem title : Minimize Deviation in an Array
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        heap = []
        min_val = float('inf')
        for x in nums:
            if x % 2 == 1:
                x *= 2
            heapq.heappush(heap, -x)
            min_val = min(min_val, x)

        min_dev = float('inf')
        while True:
            max_val = -heapq.heappop(heap)
            min_dev = min(min_dev, max_val - min_val)
            if max_val % 2 == 1:
                break
            half = max_val // 2
            min_val = min(min_val, half)
            heapq.heappush(heap, -half)

        return min_dev
