# problem title : Maximum Number of Weeks for Projects
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        total = sum(milestones)
        max_val = max(milestones)
        rest = total - max_val

        if max_val > rest + 1:
            return 2 * rest + 1
        return total
