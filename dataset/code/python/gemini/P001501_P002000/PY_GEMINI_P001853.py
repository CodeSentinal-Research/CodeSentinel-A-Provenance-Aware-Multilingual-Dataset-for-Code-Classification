from typing import List

class Solution:
    def hasOnlyOneChild(self, preorder: List[int]) -> bool:
        n = len(preorder)
        for i in range(n - 1):
            next_diff = preorder[i] - preorder[i + 1]
            last_diff = preorder[i] - preorder[n - 1]
            if next_diff * last_diff < 0:
                return False
        return True