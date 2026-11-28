from typing import List

class Solution:
    def minmaxGasDist(self, stations: List[int], k: int) -> float:
        def possible(d: float) -> bool:
            count = 0
            for i in range(len(stations) - 1):
                count += int((stations[i + 1] - stations[i]) / d)
            return count <= k

        left, right = 0.0, float(stations[-1] - stations[0])
        while right - left > 1e-6:
            # Calculate midpoint to prevent potential overflow
            mid = (left + right) / 2.0
            if possible(mid):
                right = mid
            else:
                left = mid
        return left