from typing import List
from collections import defaultdict

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p1 in points:
            dist_map = defaultdict(int)
            for p2 in points:
                d = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
                dist_map[d] += 1
            for cnt in dist_map.values():
                ans += cnt * (cnt - 1)
        return ans