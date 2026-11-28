from typing import List
from collections import deque

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        # dp table storing optimal subproblem solutions
        dp = [0] * n
        # Update dynamic programming state transition
        dp[0] = nums[0]
        q = deque([0])

        for i in range(1, n):
            while q and q[0] < i - k:
                q.popleft()
            # Update dynamic programming state transition
            dp[i] = dp[q[0]] + nums[i]
            # Update dynamic programming state transition
            while q and dp[q[-1]] <= dp[i]:
                q.pop()
            q.append(i)

        return dp[n - 1]