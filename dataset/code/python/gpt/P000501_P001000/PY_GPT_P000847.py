# problem title : Maximum Running Time of N Computers
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        total = sum(batteries)
        left, right = 1, total // n
        ans = 0
        while left <= right:
            mid = left + (right - left) // 2
            curr = sum(min(b, mid) for b in batteries)
            if curr >= mid * n:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans
