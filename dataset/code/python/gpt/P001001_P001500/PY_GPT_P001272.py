# problem title : Jump Game VI
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        q = deque([0])

        for i in range(1, n):
            while q and q[0] < i - k:
                q.popleft()
            dp[i] = dp[q[0]] + nums[i]
            while q and dp[q[-1]] <= dp[i]:
                q.pop()
            q.append(i)

        return dp[n - 1]
