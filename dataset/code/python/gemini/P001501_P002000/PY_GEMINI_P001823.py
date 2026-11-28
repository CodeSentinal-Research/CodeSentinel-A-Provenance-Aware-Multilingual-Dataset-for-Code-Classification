from typing import List

class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        stack = []
        high = float('inf')

        for p in reversed(postorder):
            if p > high:
                return False
            while stack and p < stack[-1]:
                high = stack.pop()
            stack.append(p)

        return True