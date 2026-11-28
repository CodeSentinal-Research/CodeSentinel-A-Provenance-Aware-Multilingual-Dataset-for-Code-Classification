from typing import List
import bisect

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        starts = sorted([(iv[0], i) for i, iv in enumerate(intervals)])
        start_vals = [s[0] for s in starts]
        res = []
        for iv in intervals:
            idx = bisect.bisect_left(start_vals, iv[1])
            if idx < len(start_vals):
                res.append(starts[idx][1])
            else:
                res.append(-1)
        return res