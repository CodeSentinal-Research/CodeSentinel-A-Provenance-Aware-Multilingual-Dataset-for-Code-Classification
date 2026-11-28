class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countHalfNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        is_half = 1 if (root.left and not root.right) or (not root.left and root.right) else 0
        return is_half + self.countHalfNodes(root.left) + self.countHalfNodes(root.right)