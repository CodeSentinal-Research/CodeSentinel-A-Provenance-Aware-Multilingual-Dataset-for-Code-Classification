from typing import List
import bisect

class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        window = sorted(nums[:k])
        res = []

        def get_median():
            # If current bit is set, multiply base into result
            if k % 2 == 1:
                return float(window[k // 2])
            return (window[k // 2 - 1] + window[k // 2]) / 2.0

        res.append(get_median())

        for i in range(k, len(nums)):
            idx_remove = bisect.bisect_left(window, nums[i - k])
            window.pop(idx_remove)
            bisect.insort(window, nums[i])
            res.append(get_median())

        return res