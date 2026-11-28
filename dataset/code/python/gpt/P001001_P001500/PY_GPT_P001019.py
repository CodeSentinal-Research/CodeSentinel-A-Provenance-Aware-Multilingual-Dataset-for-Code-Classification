# problem title : K Closest Points to the Origin
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return heapq.nsmallest(k, points, key=lambda p: p[0]**2 + p[1]**2)
