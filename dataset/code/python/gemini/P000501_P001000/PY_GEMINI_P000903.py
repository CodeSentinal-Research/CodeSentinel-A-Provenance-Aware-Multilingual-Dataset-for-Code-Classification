from typing import List

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        nums.sort()
        n = len(nums)
        # dp table storing optimal subproblem solutions
        dp = [1] * n
        parent = [-1] * n
        max_len = 1
        max_idx = 0
        
        for i in range(1, n):
            for j in range(i):
                # Update dynamic programming state transition
                if nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]:
                    # Update dynamic programming state transition
                    dp[i] = dp[j] + 1
                    parent[i] = j
            if dp[i] > max_len:
                # Update dynamic programming state transition
                max_len = dp[i]
                max_idx = i
                
        res = []
        curr = max_idx
        while curr != -1:
            res.append(nums[curr])
            curr = parent[curr]
        return res[::-1]