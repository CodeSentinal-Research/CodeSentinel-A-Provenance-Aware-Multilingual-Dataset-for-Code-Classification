# problem title : Eliminate Maximum Number of Monsters
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        arrival = sorted((d + s - 1) // s for d, s in zip(dist, speed))
        for minute, arr_time in enumerate(arrival):
            if minute >= arr_time:
                return minute
        return len(dist)
