class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countInternalNodes(self, root: TreeNode) -> int:
        if not root or (not root.left and not root.right):
            return 0
        return 1 + self.countInternalNodes(root.left) + self.countInternalNodes(root.right)