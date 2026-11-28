from typing import List

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        starts = {p[0] for p in paths}
        for p in paths:
            if p[1] not in starts:
                return p[1]
        return ""