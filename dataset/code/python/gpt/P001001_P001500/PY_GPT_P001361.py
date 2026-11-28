# problem title : Stickers to Spell Word
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        sticker_counts = [Counter(s) for s in stickers]
        memo = {"": 0}

        def dfs(t: str) -> int:
            if t in memo:
                return memo[t]

            t_count = Counter(t)
            res = float('inf')

            for s_count in sticker_counts:
                if t[0] not in s_count:
                    continue
                rem = []
                for c, count in t_count.items():
                    if count > s_count[c]:
                        rem.append(c * (count - s_count[c]))
                next_t = "".join(rem)
                res = min(res, 1 + dfs(next_t))

            memo[t] = res
            return res

        ans = dfs(target)
        return ans if ans != float('inf') else -1
