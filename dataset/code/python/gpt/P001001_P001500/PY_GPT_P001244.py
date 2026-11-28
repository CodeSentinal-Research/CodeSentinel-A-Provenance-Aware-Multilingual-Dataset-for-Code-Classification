# problem title : Reorganize String
# Solve the stated task using standard input and standard output.
from collections import Counter
import heapq

class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        max_heap = [(-val, c) for c, val in count.items()]
        heapq.heapify(max_heap)

        prev_cnt, prev_char = 0, ""
        res = []

        while max_heap:
            cnt, c = heapq.heappop(max_heap)
            res.append(c)
            if prev_cnt < 0:
                heapq.heappush(max_heap, (prev_cnt, prev_char))
            prev_cnt = cnt + 1
            prev_char = c

        ans = "".join(res)
        return ans if len(ans) == len(s) else ""
