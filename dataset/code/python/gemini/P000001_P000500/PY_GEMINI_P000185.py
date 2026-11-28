from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_map = {0: -1}
        cur_sum = 0
        max_len = 0

        for i, x in enumerate(nums):
            cur_sum += (1 if x == 1 else -1)
            if cur_sum in prefix_map:
                max_len = max(max_len, i - prefix_map[cur_sum])
            else:
                prefix_map[cur_sum] = i

        return max_len