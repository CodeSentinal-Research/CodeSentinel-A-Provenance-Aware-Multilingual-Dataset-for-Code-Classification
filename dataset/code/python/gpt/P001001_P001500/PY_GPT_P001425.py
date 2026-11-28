# problem title : Destination City
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        starts = {p[0] for p in paths}
        for p in paths:
            if p[1] not in starts:
                return p[1]
        return ""
