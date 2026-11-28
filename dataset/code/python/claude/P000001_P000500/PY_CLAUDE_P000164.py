
from typing import List

class Solution:
    def countTriplets(self, nums: List[int], target: int) -> int:
        nums.sort()
        count = 0
        n = len(nums)
        for i in range(n-2):
            l, r = i+1, n-1
            while l < r:
                s = nums[i]+nums[l]+nums[r]
                if s == target:
                    if nums[l] == nums[r]:
                        m = r-l+1
                        count += m*(m-1)//2
                        break
                    lc = rc = 1
                    while l+lc < r and nums[l+lc] == nums[l]: lc += 1
                    while r-rc > l and nums[r-rc] == nums[r]: rc += 1
                    count += lc*rc
                    l += lc; r -= rc
                elif s < target: l += 1
                else: r -= 1
        return count
