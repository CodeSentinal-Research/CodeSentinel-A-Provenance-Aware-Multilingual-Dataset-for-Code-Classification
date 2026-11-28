from typing import List
from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_count = Counter(p)
        s_count = Counter()
        res = []
        p_len = len(p)

        for i, c in enumerate(s):
            s_count[c] += 1
            if i >= p_len:
                s_count[s[i - p_len]] -= 1
                if s_count[s[i - p_len]] == 0:
                    del s_count[s[i - p_len]]
            if s_count == p_count:
                res.append(i - p_len + 1)

        return res