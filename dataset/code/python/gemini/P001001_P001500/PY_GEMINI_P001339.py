from typing import List

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # dp table storing optimal subproblem solutions
        dp = [set()]
        for s in arr:
            s_set = set(s)
            if len(s_set) < len(s):
                continue
            for prev in list(dp):
                if not (prev & s_set):
                    dp.append(prev | s_set)
        return max(len(s) for s in dp)