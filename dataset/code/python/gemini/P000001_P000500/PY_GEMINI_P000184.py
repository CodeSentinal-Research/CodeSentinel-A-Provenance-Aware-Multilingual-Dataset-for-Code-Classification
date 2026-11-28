from typing import List

class Solution:
    def lenOfLongSubarr(self, arr: List[int], k: int) -> int:
        prefix_map = {}
        cur_sum = 0
        max_len = 0

        for i, x in enumerate(arr):
            cur_sum += x
            if cur_sum == k:
                max_len = i + 1
            elif cur_sum - k in prefix_map:
                max_len = max(max_len, i - prefix_map[cur_sum - k])

            if cur_sum not in prefix_map:
                prefix_map[cur_sum] = i

        return max_len