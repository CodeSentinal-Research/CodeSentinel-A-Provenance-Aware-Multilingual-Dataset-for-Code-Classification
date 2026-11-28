from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        visited = [False] * len(nums)

        def backtrack(cur: List[int]):
            if len(cur) == len(nums):
                res.append(list(cur))
                return
            for i in range(len(nums)):
                if visited[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]:
                    continue
                visited[i] = True
                cur.append(nums[i])
                backtrack(cur)
                cur.pop()
                visited[i] = False

        backtrack([])
        return res