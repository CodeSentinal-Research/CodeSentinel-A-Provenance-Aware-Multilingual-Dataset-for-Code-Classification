from typing import List

class Solution:
    def minSwaps(self, data: List[int]) -> int:
        total_ones = sum(data)
        if total_ones <= 1:
            return 0

        cur_ones = sum(data[:total_ones])
        max_ones = cur_ones

        for i in range(total_ones, len(data)):
            cur_ones += data[i] - data[i - total_ones]
            max_ones = max(max_ones, cur_ones)

        return total_ones - max_ones