from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        points.sort(key=lambda x: x[1])
        arrows = 1
        last_end = points[0][1]

        for s, e in points[1:]:
            if s > last_end:
                arrows += 1
                last_end = e

        return arrows