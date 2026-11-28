from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSearch(self, root: TreeNode, low: int, high: int) -> List[int]:
        """Performs search to locate target element within the given collection."""
        res = []

        def inorder(node):
            if not node:
                return
            if node.val > low:
                inorder(node.left)
            if low <= node.val <= high:
                res.append(node.val)
            if node.val < high:
                inorder(node.right)

        inorder(root)
        return res