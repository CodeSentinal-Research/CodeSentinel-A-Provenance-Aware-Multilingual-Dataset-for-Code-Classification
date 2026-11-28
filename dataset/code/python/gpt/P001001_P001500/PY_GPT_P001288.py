# problem title : Maximum Equal Sum After K Negations
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        for _ in range(k):
            heapq.heappush(nums, -heapq.heappop(nums))
        return sum(nums)
