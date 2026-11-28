# problem title : Minimum Cost to Hire K Workers
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        workers = sorted([(w / q, q) for q, w in zip(quality, wage)])
        heap = []
        q_sum = 0
        ans = float('inf')
        for ratio, q in workers:
            heapq.heappush(heap, -q)
            q_sum += q
            if len(heap) > k:
                q_sum += heapq.heappop(heap)
            if len(heap) == k:
                ans = min(ans, q_sum * ratio)
        return ans
