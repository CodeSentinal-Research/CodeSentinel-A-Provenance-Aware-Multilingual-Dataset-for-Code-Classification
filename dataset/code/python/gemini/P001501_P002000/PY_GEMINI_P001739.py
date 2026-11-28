class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def removeLeaves(self, root: TreeNode) -> TreeNode:
        if not root or (not root.left and not root.right):
            return None
        root.left = self.removeLeaves(root.left)
        root.right = self.removeLeaves(root.right)
        return root