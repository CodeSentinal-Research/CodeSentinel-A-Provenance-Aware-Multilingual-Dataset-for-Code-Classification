# problem title : Matchsticks to Square
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total = sum(matchsticks)
        if total % 4 != 0:
            return False
        side = total // 4
        matchsticks.sort(reverse=True)
        if matchsticks[0] > side:
            return False

        sides = [0] * 4

        def backtrack(idx: int) -> bool:
            if idx == len(matchsticks):
                return True
            for i in range(4):
                if sides[i] + matchsticks[idx] <= side:
                    sides[i] += matchsticks[idx]
                    if backtrack(idx + 1):
                        return True
                    sides[i] -= matchsticks[idx]
                if sides[i] == 0:
                    break
            return False

        return backtrack(0)
