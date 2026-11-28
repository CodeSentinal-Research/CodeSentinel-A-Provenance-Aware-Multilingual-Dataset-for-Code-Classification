# problem title : Minimum Time to Complete Trips
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        l = 1
        r = min(time) * totalTrips
        ans = r

        while l <= r:
            mid = (l + r) // 2
            trips = sum(mid // t for t in time)
            if trips >= totalTrips:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1

        return ans
