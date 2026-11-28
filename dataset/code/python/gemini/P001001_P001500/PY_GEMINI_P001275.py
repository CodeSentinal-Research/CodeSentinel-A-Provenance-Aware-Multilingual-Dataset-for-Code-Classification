from typing import List
import heapq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        workers = sorted(zip(quality, wage), key=lambda x: x[1] / x[0])
        pq = []
        qual_sum = 0
        min_cost = float('inf')

        for q, w in workers:
            ratio = w / q
            heapq.heappush(pq, -q)
            qual_sum += q
            if len(pq) > k:
                qual_sum += heapq.heappop(pq)
            if len(pq) == k:
                min_cost = min(min_cost, qual_sum * ratio)

        return min_cost