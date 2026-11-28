# problem title : Frog Jump
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def canCross(self, stones: List[int]) -> bool:
        dp = {s: set() for s in stones}
        dp[0].add(0)

        for s in stones:
            for k in dp[s]:
                for step in [k - 1, k, k + 1]:
                    if step > 0 and (s + step) in dp:
                        dp[s + step].add(step)

        return len(dp[stones[-1]]) > 0
