# problem title : Number of Matching Subsequences
# Solve the stated task using standard input and standard output.
from typing import List
from collections import defaultdict

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        heads = defaultdict(list)
        for w in words:
            heads[w[0]].append(iter(w[1:]))

        ans = 0
        for c in s:
            cur_list = heads[c]
            heads[c] = []
            for it in cur_list:
                nxt = next(it, None)
                if nxt is None:
                    ans += 1
                else:
                    heads[nxt].append(it)

        return ans
