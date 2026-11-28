



from typing import List

class Solution:
    def findDuplicateInNPlusOne(self, nums: List[int]) -> int:
        duplicate = -1
        for i in range(len(nums)):
            idx = abs(nums[i])
            if nums[idx] < 0:
                duplicate = idx
                break
            nums[idx] = -nums[idx]

        for i in range(len(nums)):
            if nums[i] < 0:
                nums[i] = -nums[i]
        return duplicate
