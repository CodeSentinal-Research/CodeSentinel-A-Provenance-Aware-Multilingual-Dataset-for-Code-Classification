
from typing import List

class Solution:
    def segregate01(self, nums: List[int]) -> List[int]:
        zeros = nums.count(0)
        return [0]*zeros + [1]*(len(nums)-zeros)
