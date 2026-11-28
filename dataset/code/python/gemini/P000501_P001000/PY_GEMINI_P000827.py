from typing import List
import bisect

class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        max_r = 0
        for h in houses:
            idx = bisect.bisect_left(heaters, h)
            dist = float('inf')
            if idx < len(heaters):
                dist = min(dist, heaters[idx] - h)
            if idx > 0:
                dist = min(dist, h - heaters[idx - 1])
            max_r = max(max_r, dist)
        return max_r