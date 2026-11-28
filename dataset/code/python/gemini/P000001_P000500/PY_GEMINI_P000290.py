from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ns, np = len(s), len(p)
        if ns < np:
            return []

        p_count = [0] * 26
        s_count = [0] * 26
        for c in p:
            p_count[ord(c) - ord('a')] += 1

        res = []
        for i in range(ns):
            s_count[ord(s[i]) - ord('a')] += 1
            if i >= np:
                s_count[ord(s[i - np]) - ord('a')] -= 1
            if p_count == s_count:
                res.append(i - np + 1)

        return res