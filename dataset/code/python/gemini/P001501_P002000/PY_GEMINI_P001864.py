class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxSearchCost(self, root: TreeNode) -> int:
        """Performs search to locate target element within the given collection."""
        if not root:
            return 0
        return 1 + max(self.maxSearchCost(root.left), self.maxSearchCost(root.right))