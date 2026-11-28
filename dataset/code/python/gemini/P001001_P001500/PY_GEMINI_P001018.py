from collections import Counter
import heapq

class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        max_freq = max(count.values())
        if max_freq > (len(s) + 1) // 2:
            return ""

        heap = [(-freq, ch) for ch, freq in count.items()]
        heapq.heapify(heap)

        res = []
        prev_freq, prev_ch = 0, ""
        while heap:
            freq, ch = heapq.heappop(heap)
            res.append(ch)
            if prev_freq < 0:
                heapq.heappush(heap, (prev_freq, prev_ch))
            prev_freq, prev_ch = freq + 1, ch

        return "".join(res)