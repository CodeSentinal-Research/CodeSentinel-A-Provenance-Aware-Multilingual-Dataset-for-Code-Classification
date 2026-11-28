# problem title : Minimum Refueling Stops
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        heap = []
        stops = 0
        cur_fuel = startFuel
        i = 0
        n = len(stations)

        while cur_fuel < target:
            while i < n and stations[i][0] <= cur_fuel:
                heapq.heappush(heap, -stations[i][1])
                i += 1
            if not heap:
                return -1
            cur_fuel += -heapq.heappop(heap)
            stops += 1
        return stops
