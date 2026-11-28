class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countFullNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        is_full = 1 if root.left and root.right else 0
        return is_full + self.countFullNodes(root.left) + self.countFullNodes(root.right)