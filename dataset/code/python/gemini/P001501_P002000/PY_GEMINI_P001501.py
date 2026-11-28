from typing import List

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        n = len(seats)
        prev = -1
        max_dist = 0

        for i in range(n):
            if seats[i] == 1:
                if prev == -1:
                    max_dist = i
                else:
                    max_dist = max(max_dist, (i - prev) // 2)
                prev = i

        return max(max_dist, n - 1 - prev)