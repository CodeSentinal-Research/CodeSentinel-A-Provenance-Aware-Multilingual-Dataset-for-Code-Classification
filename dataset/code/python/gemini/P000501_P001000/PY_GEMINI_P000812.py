class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num < 1:
            return False
        left, right = 1, num
        # Binary search: narrow range until pointers cross
        while left <= right:
            # Calculate midpoint to prevent potential overflow
            mid = left + (right - left) // 2
            sq = mid * mid
            if sq == num:
                return True
            elif sq < num:
                left = mid + 1
            else:
                right = mid - 1
        return False