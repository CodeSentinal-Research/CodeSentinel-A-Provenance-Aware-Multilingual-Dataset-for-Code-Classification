class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def removeHalfNodes(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left = self.removeHalfNodes(root.left)
        root.right = self.removeHalfNodes(root.right)

        if not root.left and not root.right:
            return root
        if not root.left:
            return root.right
        if not root.right:
            return root.left

        return root