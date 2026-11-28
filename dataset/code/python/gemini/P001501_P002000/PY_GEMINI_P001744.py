class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def everyInternalNodeOneChild(self, root: TreeNode) -> bool:
        if not root:
            return True
        if not root.left and not root.right:
            return True
        if root.left and root.right:
            return False
        return self.everyInternalNodeOneChild(root.left if root.left else root.right)