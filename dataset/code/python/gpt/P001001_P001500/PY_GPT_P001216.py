# problem title : Minimum Cost Tree From Leaf Values
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        res = 0
        stack = [float('inf')]
        for x in arr:
            while stack[-1] <= x:
                mid = stack.pop()
                res += mid * min(stack[-1], x)
            stack.append(x)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        return res
