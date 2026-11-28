# problem title : Maximum Value at a Given Index in a Bounded Array
# Solve the stated task using standard input and standard output.
class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def calc_sum(count: int, val: int) -> int:
            if val >= count:
                return (val + val - count + 1) * count // 2
            else:
                return (val + 1) * val // 2 + (count - val)

        left_count = index
        right_count = n - 1 - index
        low, high = 1, maxSum
        ans = 1
        while low <= high:
            mid = low + (high - low) // 2
            total = mid + calc_sum(left_count, mid - 1) + calc_sum(right_count, mid - 1)
            if total <= maxSum:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        return ans
