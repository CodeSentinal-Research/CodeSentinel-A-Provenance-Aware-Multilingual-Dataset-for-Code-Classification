from typing import List

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        n = len(words)
        sets = [set(w) for w in words]
        for i in range(n):
            for j in range(i + 1, n):
                if sets[i] == sets[j]:
                    ans += 1
        return ans