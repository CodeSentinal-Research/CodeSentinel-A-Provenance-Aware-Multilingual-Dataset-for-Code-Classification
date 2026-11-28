# problem title : Rearrange Array to Maximize Prefix Score
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        prefix = 0
        score = 0
        for x in nums:
            prefix += x
            if prefix > 0:
                score += 1
            else:
                break
        return score
