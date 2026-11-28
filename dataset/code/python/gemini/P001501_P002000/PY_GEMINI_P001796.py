from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        idx = 0

        def build(bound):
            nonlocal idx
            if idx == len(preorder) or preorder[idx] > bound:
                return None
            val = preorder[idx]
            idx += 1
            root = TreeNode(val)
            root.left = build(val)
            root.right = build(bound)
            return root

        return build(float('inf'))