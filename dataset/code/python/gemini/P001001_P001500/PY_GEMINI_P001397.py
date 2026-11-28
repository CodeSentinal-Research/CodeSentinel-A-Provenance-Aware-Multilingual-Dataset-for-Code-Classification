from typing import List
from collections import defaultdict

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        gap_count = defaultdict(int)
        for row in wall:
            edge = 0
            for brick in row[:-1]:
                edge += brick
                gap_count[edge] += 1
        return len(wall) - max(gap_count.values(), default=0)