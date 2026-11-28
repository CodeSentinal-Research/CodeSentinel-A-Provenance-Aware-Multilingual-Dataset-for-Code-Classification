# problem title : Different Ways to Add Parentheses
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        memo = {}

        def ways(s: str) -> List[int]:
            if s in memo:
                return memo[s]

            res = []
            for i, c in enumerate(s):
                if c in "+-*":
                    left = ways(s[:i])
                    right = ways(s[i + 1:])
                    for l in left:
                        for r in right:
                            if c == '+':
                                res.append(l + r)
                            elif c == '-':
                                res.append(l - r)
                            elif c == '*':
                                res.append(l * r)

            if not res:
                res.append(int(s))
            memo[s] = res
            return res

        return ways(expression)
