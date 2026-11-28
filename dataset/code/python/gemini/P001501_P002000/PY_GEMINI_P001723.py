class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return root.val
        if not root.left:
            return root.val + self.maxPathSum(root.right)
        if not root.right:
            return root.val + self.maxPathSum(root.left)
        return root.val + max(self.maxPathSum(root.left), self.maxPathSum(root.right))