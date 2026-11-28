class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isStrictBinaryTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        if not root.left and not root.right:
            return True
        if root.left and root.right:
            return self.isStrictBinaryTree(root.left) and self.isStrictBinaryTree(root.right)
        return False