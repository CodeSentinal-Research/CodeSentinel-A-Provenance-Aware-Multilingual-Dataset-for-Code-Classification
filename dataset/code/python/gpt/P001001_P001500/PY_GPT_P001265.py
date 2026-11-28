# problem title : Maximum Performance of a Team
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10**9 + 7
        engineers = sorted(zip(efficiency, speed), key=lambda x: x[0], reverse=True)
        speed_sum = 0
        speed_heap = []
        max_perf = 0

        for eff, spd in engineers:
            heapq.heappush(speed_heap, spd)
            speed_sum += spd
            if len(speed_heap) > k:
                speed_sum -= heapq.heappop(speed_heap)
            max_perf = max(max_perf, speed_sum * eff)

        return max_perf % MOD
