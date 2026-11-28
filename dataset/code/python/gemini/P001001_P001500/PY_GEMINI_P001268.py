from typing import List
import heapq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        day = 0
        count = 0
        i = 0
        n = len(events)

        while i < n or pq:
            if not pq:
                day = events[i][0]
            while i < n and events[i][0] <= day:
                heapq.heappush(pq, events[i][1])
                i += 1
            heapq.heappop(pq)
            count += 1
            day += 1
            while pq and pq[0] < day:
                heapq.heappop(pq)

        return count