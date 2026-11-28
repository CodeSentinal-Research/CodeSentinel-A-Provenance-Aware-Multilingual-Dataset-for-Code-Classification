# problem title : Minimum Initial Energy to Finish Tasks
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)
        cur_energy = 0
        req_energy = 0

        for actual, minimum in tasks:
            if cur_energy < minimum:
                req_energy += minimum - cur_energy
                cur_energy = minimum
            cur_energy -= actual

        return req_energy
