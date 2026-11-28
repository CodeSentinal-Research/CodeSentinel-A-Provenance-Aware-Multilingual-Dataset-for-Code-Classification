# problem title : Smallest Range Covering K Sorted Lists
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = []
        cur_max = float('-inf')
        for i, lst in enumerate(nums):
            heapq.heappush(heap, (lst[0], i, 0))
            cur_max = max(cur_max, lst[0])

        best_range = [heap[0][0], cur_max]
        while True:
            val, r, c = heapq.heappop(heap)
            if c + 1 == len(nums[r]):
                break
            next_val = nums[r][c + 1]
            cur_max = max(cur_max, next_val)
            heapq.heappush(heap, (next_val, r, c + 1))
            if cur_max - heap[0][0] < best_range[1] - best_range[0]:
                best_range = [heap[0][0], cur_max]
        return best_range
