class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        ans = 0
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            curr = (mid * (mid + 1)) // 2
            if curr <= n:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        return ans