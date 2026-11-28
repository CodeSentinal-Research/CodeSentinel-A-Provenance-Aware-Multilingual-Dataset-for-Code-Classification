class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSiblings(self, root: TreeNode, a: int, b: int) -> bool:
        if not root:
            return False
        if root.left and root.right:
            if (root.left.val == a and root.right.val == b) or (root.left.val == b and root.right.val == a):
                return True
        return self.isSiblings(root.left, a, b) or self.isSiblings(root.right, a, b)