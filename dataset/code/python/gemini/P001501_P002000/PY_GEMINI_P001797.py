from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstFromPostorder(self, postorder: List[int]) -> TreeNode:
        idx = len(postorder) - 1

        def build(bound):
            nonlocal idx
            if idx < 0 or postorder[idx] < bound:
                return None
            val = postorder[idx]
            idx -= 1
            root = TreeNode(val)
            root.right = build(val)
            root.left = build(bound)
            return root

        return build(float('-inf'))