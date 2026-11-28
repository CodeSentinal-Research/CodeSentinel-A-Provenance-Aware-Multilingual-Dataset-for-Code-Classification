# problem title : First Bad Version
# Solve the stated task using standard input and standard output.
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n
        ans = n
        while left <= right:
            mid = left + (right - left) // 2
            if isBadVersion(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
