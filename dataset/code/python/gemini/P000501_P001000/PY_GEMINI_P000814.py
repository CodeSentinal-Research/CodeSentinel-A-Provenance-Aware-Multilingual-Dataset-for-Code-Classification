# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n
        ans = n
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            if isBadVersion(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans