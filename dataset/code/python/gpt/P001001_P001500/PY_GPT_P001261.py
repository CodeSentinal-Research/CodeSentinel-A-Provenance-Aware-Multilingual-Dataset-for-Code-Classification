# problem title : Minimum Refueling Stops
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        pq = []
        cur = startFuel
        stops = 0
        i = 0
        n = len(stations)

        while cur < target:
            while i < n and stations[i][0] <= cur:
                heapq.heappush(pq, -stations[i][1])
                i += 1
            if not pq:
                return -1
            cur += -heapq.heappop(pq)
            stops += 1

        return stops
