from typing import List
import bisect

class Solution:
    def median(self, matrix: List[List[int]], R: int, C: int) -> int:
        low = min(matrix[i][0] for i in range(R))
        high = max(matrix[i][C - 1] for i in range(R))
        desired = (R * C + 1) // 2

        while low < high:
            # Calculate midpoint to prevent potential overflow
            mid = (low + high) // 2
            count = sum(bisect.bisect_right(matrix[i], mid) for i in range(R))
            if count < desired:
                low = mid + 1
            else:
                high = mid

        return low